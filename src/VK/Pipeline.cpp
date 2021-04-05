#include <SDL2/SDL_syswm.h>

#include <vulkan/vulkan.h>

#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

#include <vector>
#include <array>
#include <set>
#include <stdexcept>

#include "Vertex.h"
#include "vdeleter.h"
#include "CoreEngine.h"

#include "Pipeline.h"

pipeline::pipeline(const Device &device) :
        swapchain(), device(device),
        renderPass(device, swapChainImageFormat,
                   device.physicalDevice.findSupportedFormat(
                           {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT},
                           VK_IMAGE_TILING_OPTIMAL,
                           VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
                   )),
        descriptorSetLayout(device) {

    createDescriptorSetLayout();
    createGraphicsPipeline();
    createCommandPool();
    createDepthResources();
    createFramebuffers();
}

void pipeline::drawFrame() {
    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(device.device, swapChain, std::numeric_limits<uint64_t>::max(),
                                            imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);

    if (result == VK_ERROR_OUT_OF_DATE_KHR) {
        recreateSwapChain();
        return;
    } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        throw std::runtime_error("failed to acquire swap chain image!");
    }

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {imageAvailableSemaphore};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &maincommandBuffers[imageIndex];

    VkSemaphore signalSemaphores[] = {renderFinishedSemaphore};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE) != VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo = {};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {swapChain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;

    presentInfo.pImageIndices = &imageIndex;

    result = vkQueuePresentKHR(presentQueue, &presentInfo);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR) {
        recreateSwapChain();
    } else if (result != VK_SUCCESS) {
        throw std::runtime_error("failed to present swap chain image!");
    }
}

void pipeline::loadModel() {
    createMainCommandBuffers();
    createSemaphores();
}

void pipeline::recreateSwapChain() {
    vkDeviceWaitIdle(device.device);

    createSwapChain();
    createImageViews();
    createRenderPass();
    createGraphicsPipeline();
    createDepthResources();
    createFramebuffers();

    model::CreateCommandBuffers();

    createMainCommandBuffers();
}

inline void pipeline::createGraphicsPipeline() {


    VkGraphicsPipelineCreateInfo pipelineInfo = {};
    pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipelineInfo.stageCount = 2;
    pipelineInfo.pStages = shaderStages;
    pipelineInfo.pVertexInputState = &vertexInputInfo;
    pipelineInfo.pInputAssemblyState = &inputAssembly;
    pipelineInfo.pViewportState = &viewportState;
    pipelineInfo.pRasterizationState = &rasterizer;
    pipelineInfo.pMultisampleState = &multisampling;
    pipelineInfo.pDepthStencilState = &depthStencil;
    pipelineInfo.pColorBlendState = &colorBlending;
    pipelineInfo.layout = pipelineLayout;
    pipelineInfo.renderPass = renderPass;
    pipelineInfo.subpass = 0;
    pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;

    if (vkCreateGraphicsPipelines(device.device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr,
                                  graphicsPipeline.replace()) != VK_SUCCESS) {
        throw std::runtime_error("failed to create graphics pipeline!");
    }
}

inline void pipeline::createDepthResources() {
    VkFormat depthFormat = CoreEngine::getInstance().findDepthFormat();

    CoreEngine::getInstance().createImage(swapChainExtent.width, swapChainExtent.height, depthFormat,
                                          VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
                                          VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, depthImage.replace(),
                                          depthImageMemory.replace());
    CoreEngine::getInstance().createImageView(depthImage, depthFormat, VK_IMAGE_ASPECT_DEPTH_BIT,
                                              depthImageView.replace());

    CoreEngine::getInstance().transitionImageLayout(depthImage, depthFormat, VK_IMAGE_LAYOUT_UNDEFINED,
                                                    VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL, this);
}

inline void pipeline::createMainCommandBuffers() {
    if (maincommandBuffers.size() > 0) {
        vkFreeCommandBuffers(device.device, commandPool, (uint32_t) maincommandBuffers.size(),
                             maincommandBuffers.data());
    }

    maincommandBuffers.resize(swapChainFramebuffers.size());

    VkCommandBufferAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = (uint32_t) maincommandBuffers.size();

    if (vkAllocateCommandBuffers(device.device, &allocInfo, maincommandBuffers.data()) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }

    for (size_t i = 0; i < maincommandBuffers.size(); i++) {
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;

        vkBeginCommandBuffer(maincommandBuffers[i], &beginInfo);//

        VkRenderPassBeginInfo renderPassInfo = {};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = renderPass;
        renderPassInfo.framebuffer = swapChainFramebuffers[i];
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = swapChainExtent;

        std::array<VkClearValue, 2> clearValues = {};
        clearValues[0].color = {0.0f, 0.0f, 0.0f, 1.0f};
        clearValues[1].depthStencil = {1.0f, 0};

        renderPassInfo.clearValueCount = (uint32_t) clearValues.size();
        renderPassInfo.pClearValues = clearValues.data();

        vkCmdBeginRenderPass(maincommandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS);

        CoreEngine::getInstance().ExecuteCommandsBuffers(maincommandBuffers[i], i);

        vkCmdEndRenderPass(maincommandBuffers[i]);

        if (vkEndCommandBuffer(maincommandBuffers[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to record command buffer!");
        }
    }
}

inline void pipeline::createSemaphores() {
    VkSemaphoreCreateInfo semaphoreInfo = {};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    if (vkCreateSemaphore(device.device, &semaphoreInfo, nullptr, imageAvailableSemaphore.replace()) != VK_SUCCESS ||
        vkCreateSemaphore(device.device, &semaphoreInfo, nullptr, renderFinishedSemaphore.replace()) != VK_SUCCESS) {
        throw std::runtime_error("failed to create semaphores!");
    }
}
