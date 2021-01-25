#include <vulkan/vulkan.h>

#include <Blob/VK/Vertex.hpp>
#include <Blob/VK/Window.hpp>
#include <Blob/VK/model.hpp>
namespace Blob::VK {

std::list<model *> model::models;

model::model(const Window &coreEngine, const std::string &textPath, const std::string &modelPath)
    : coreEngine(coreEngine), textureImage(coreEngine.device, textPath, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_TILING_LINEAR, VK_IMAGE_USAGE_SAMPLED_BIT,
                                           VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) /*,
                                                                 textureImageView(coreEngine.device, textureImage.image,
                                                                                  VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT)*/
{

    textureImage.transitionImageLayout(VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_LAYOUT_PREINITIALIZED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                                       coreEngine.commandPool);

    /*  createTextureImage(textPath);
      createTextureImageView();
      createTextureSampler();
      loadModel(modelPath);

      createVertexBuffer();
      createIndexBuffer();
      createUniformBuffer();

      createDescriptorPool();
      createDescriptorSet();
      createCommandBuffers();*/

    position = Blob::Maths::Vec3<>(0, 0, 0);
    models.push_back(this);
}

void model::createCommandBuffers() {
    for (auto &m : models) {
        m->createCommandBuffers();
    }
}

void model::executeCommandsBuffers(VkCommandBuffer c, size_t i) {
    for (auto &m : models) {
        // vkCmdExecuteCommands(c, 1, &m->commandBuffers[i]);
    }
}

/*void model::updateUniformBuffer() {
  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::milliseconds>(
                   currentTime - startTime)
                   .count() /
               1000.0f;

  UniformBufferObject ubo = {};
  ubo.model = glm::translate(
      glm::mat4(1), glm::vec3(position.x, position.y,
                              position.z)); // rotation (matrice identit�)

  ubo.view = glm::lookAt(
      glm::vec3(0.0f, 0.0f,
                -54.32f), // the position of your camera, in world space
      glm::vec3(0.0f, 0.0f, 0.0f), // where you want to look at, in world space
      glm::vec3(0.0f, 1.0f,
                0.0f) // probably glm::vec3(0,1,0), but (0,-1,0) would make you
                      // looking upside-down, which can be great too
  );
  // Generates a really hard-to-read matrix, but a normal, standard 4x4 matrix
  // nonetheless
  ubo.proj = glm::perspective(
      glm::radians(45.0f), // The horizontal Field of View, in degrees : the
                           // amount of "zoom". Think "camera lens". Usually
                           // between 90� (extra wide) and 30� (quite zoomed in)
      (float)16.0 / (float)9.0, // Aspect Ratio. Depends on the size of your
                                // window. Notice that 4/3 == 800/600 ==
                                // 1280/960, sounds familiar ?
      0.1f,  // Near clipping plane. Keep as big as possible, or you'll get
             // precision issues.
      100.0f // Far clipping plane. Keep as little as possible.
  );
  ubo.proj[1][1] *= -1;

  void *data;
  vkMapMemory(coreEngine.device.device, uniformStagingBufferMemory, 0,
              sizeof(ubo), 0, &data);
  memcpy(data, &ubo, sizeof(ubo));
  vkUnmapMemory(coreEngine.device.device, uniformStagingBufferMemory);

  CoreEngine::getInstance().copyBuffer(uniformStagingBuffer, uniformBuffer,
                                       sizeof(ubo),
                                       CoreEngine::getInstance().pipe);
}

inline void model::createTextureSampler() {
  VkSamplerCreateInfo samplerInfo = {};
  samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
  samplerInfo.magFilter = VK_FILTER_NEAREST;
  samplerInfo.minFilter = VK_FILTER_LINEAR;
  samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.anisotropyEnable = VK_TRUE;
  samplerInfo.maxAnisotropy = 16;
  samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
  samplerInfo.unnormalizedCoordinates = VK_FALSE;
  samplerInfo.compareEnable = VK_FALSE;
  samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
  samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;

  if (vkCreateSampler(coreEngine.device.device, &samplerInfo, nullptr,
                      &textureSampler) != VK_SUCCESS)
    throw std::runtime_error("failed to create texture sampler!");
}

inline void model::loadModel(std::string MODEL_PATH) {
  tinyobj::attrib_t attrib;
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;
  std::string err;

  if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &err,
                        MODEL_PATH.c_str())) {
    throw std::runtime_error(err);
  }

  std::unordered_map<Vertex, int> uniqueVertices = {};

  for (const auto &shape : shapes) {
    for (const auto &index : shape.mesh.indices) {
      Vertex vertex = {};

      vertex.pos = {attrib.vertices[3 * index.vertex_index + 0],
                    attrib.vertices[3 * index.vertex_index + 1],
                    attrib.vertices[3 * index.vertex_index + 2]};

      vertex.texCoord = {attrib.texcoords[2 * index.texcoord_index + 0],
                         1.0f - attrib.texcoords[2 * index.texcoord_index + 1]};

      vertex.color = {1.0f, 1.0f, 1.0f};

      if (uniqueVertices.count(vertex) == 0) {
        uniqueVertices[vertex] = (uint32_t)vertices.size();
        vertices.push_back(vertex);
      }

      indices.push_back(uniqueVertices[vertex]);
    }
  }
}

inline void model::createVertexBuffer() {
  VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

  VDeleter<VkBuffer> stagingBuffer{coreEngine.device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> stagingBufferMemory{coreEngine.device, vkFreeMemory};
  CoreEngine::getInstance().createBuffer(
      bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
          VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
      stagingBuffer, stagingBufferMemory);

  void *data;
  vkMapMemory(coreEngine.device.device, stagingBufferMemory, 0, bufferSize, 0,
              &data);
  memcpy(data, vertices.data(), (size_t)bufferSize);
  vkUnmapMemory(coreEngine.device.device, stagingBufferMemory);

  CoreEngine::getInstance().createBuffer(
      bufferSize,
      VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
      VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vertexBuffer, vertexBufferMemory);

  CoreEngine::getInstance().copyBuffer(stagingBuffer, vertexBuffer, bufferSize,
                                       CoreEngine::getInstance().pipe);
}

inline void model::createIndexBuffer() {
  VkDeviceSize bufferSize = sizeof(indices[0]) * indices.size();

  VDeleter<VkBuffer> stagingBuffer{coreEngine.device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> stagingBufferMemory{coreEngine.device, vkFreeMemory};
  CoreEngine::getInstance().createBuffer(
      bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
          VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
      stagingBuffer, stagingBufferMemory);

  void *data;
  vkMapMemory(coreEngine.device.device, stagingBufferMemory, 0, bufferSize, 0,
              &data);
  memcpy(data, indices.data(), (size_t)bufferSize);
  vkUnmapMemory(coreEngine.device.device, stagingBufferMemory);

  CoreEngine::getInstance().createBuffer(
      bufferSize,
      VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
      VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, indexBuffer, indexBufferMemory);

  CoreEngine::getInstance().copyBuffer(stagingBuffer, indexBuffer, bufferSize,
                                       CoreEngine::getInstance().pipe);
}

inline void model::createUniformBuffer() {
  VkDeviceSize bufferSize = sizeof(UniformBufferObject);

  CoreEngine::getInstance().createBuffer(
      bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
          VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
      uniformStagingBuffer, uniformStagingBufferMemory);
  CoreEngine::getInstance().createBuffer(
      bufferSize,
      VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
      VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, uniformBuffer, uniformBufferMemory);
}

inline void model::createDescriptorPool() {
  std::array<VkDescriptorPoolSize, 2> poolSizes = {};
  poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
  poolSizes[0].descriptorCount = 1;
  poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
  poolSizes[1].descriptorCount = 1;

  VkDescriptorPoolCreateInfo poolInfo = {};
  poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
  poolInfo.poolSizeCount = (uint32_t)poolSizes.size();
  poolInfo.pPoolSizes = poolSizes.data();
  poolInfo.maxSets = 1;

  if (vkCreateDescriptorPool(coreEngine.device.device, &poolInfo, nullptr,
                             &descriptorPool) != VK_SUCCESS) {
    throw std::runtime_error("failed to create descriptor pool!");
  }
}

inline void model::createDescriptorSet() {
  VkDescriptorSetLayout layouts[] = {
      CoreEngine::getInstance().pipe->descriptorSetLayout};
  VkDescriptorSetAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
  allocInfo.descriptorPool = descriptorPool;
  allocInfo.descriptorSetCount = 1;
  allocInfo.pSetLayouts = layouts;

  if (vkAllocateDescriptorSets(coreEngine.device.device, &allocInfo,
                               &descriptorSet) != VK_SUCCESS) {
    throw std::runtime_error("failed to allocate descriptor set!");
  }

  VkDescriptorBufferInfo bufferInfo = {};
  bufferInfo.buffer = uniformBuffer.buffer;
  bufferInfo.offset = 0;
  bufferInfo.range = sizeof(UniformBufferObject);

  VkDescriptorImageInfo imageInfo = {};
  imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
  imageInfo.imageView = textureImageView.imageView;
  imageInfo.sampler = textureSampler;

  std::array<VkWriteDescriptorSet, 2> descriptorWrites = {};

  descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  descriptorWrites[0].dstSet = descriptorSet;
  descriptorWrites[0].dstBinding = 0;
  descriptorWrites[0].dstArrayElement = 0;
  descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
  descriptorWrites[0].descriptorCount = 1;
  descriptorWrites[0].pBufferInfo = &bufferInfo;

  descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  descriptorWrites[1].dstSet = descriptorSet;
  descriptorWrites[1].dstBinding = 1;
  descriptorWrites[1].dstArrayElement = 0;
  descriptorWrites[1].descriptorType =
      VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
  descriptorWrites[1].descriptorCount = 1;
  descriptorWrites[1].pImageInfo = &imageInfo;

  vkUpdateDescriptorSets(coreEngine.device.device,
                         (uint32_t)descriptorWrites.size(),
                         descriptorWrites.data(), 0, nullptr);
}

inline void model::createCommandBuffers() {
  if (!commandBuffers.empty()) {
    vkFreeCommandBuffers(
        coreEngine.device.device, CoreEngine::getInstance().pipe->commandPool,
        (uint32_t)commandBuffers.size(), commandBuffers.data());
  }

  commandBuffers.resize(
      CoreEngine::getInstance().pipe->swapChainFramebuffers.size());

  VkCommandBufferAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  allocInfo.commandPool = coreEngine.commandPool;
  allocInfo.level = VK_COMMAND_BUFFER_LEVEL_SECONDARY;
  allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();

  if (vkAllocateCommandBuffers(coreEngine.device.device, &allocInfo,
                               commandBuffers.data()) != VK_SUCCESS) {
    throw std::runtime_error("failed to allocate command buffers!");
  }

  for (size_t i = 0; i < commandBuffers.size(); i++) {
    VkCommandBufferInheritanceInfo InheritanceInfo = {};
    InheritanceInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    InheritanceInfo.renderPass = CoreEngine::getInstance().pipe->renderPass;
    InheritanceInfo.framebuffer =
        CoreEngine::getInstance().pipe->swapChainFramebuffers[i];

    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT |
                      VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
    beginInfo.pInheritanceInfo = &InheritanceInfo;

    vkBeginCommandBuffer(commandBuffers[i], &beginInfo);

    vkCmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS,
                      CoreEngine::getInstance().pipe->graphicsPipeline);

    VkBuffer vertexBuffers[] = {vertexBuffer};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(commandBuffers[i], 0, 1, vertexBuffers, offsets);

    vkCmdBindIndexBuffer(commandBuffers[i], indexBuffer, 0,
                         VK_INDEX_TYPE_UINT32);

    vkCmdBindDescriptorSets(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS,
                            CoreEngine::getInstance().pipe->pipelineLayout, 0,
                            1, &descriptorSet, 0, nullptr);

    vkCmdDrawIndexed(commandBuffers[i], (uint32_t)indices.size(), 1, 0, 0, 0);

    if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS) {
      throw std::runtime_error("failed to record command buffer!");
    }
  }
}*/

model::~model() {
    vkDestroyDescriptorPool(coreEngine.device.device, descriptorPool, nullptr);
}
}