#pragma once

#include "Buffer.hpp"
#include "CommandBuffer.hpp"
#include "Image.hpp"
#include "ImageView.hpp"
#include <Blob/Maths.inl>
#include <list>
namespace Blob::VK {

struct UniformBufferObject {
    Blob::Maths::Mat4 model;
    Blob::Maths::Mat4 view;
    Blob::Maths::Mat4 proj;
};

class model {
private:
    static std::list<model *> models;
    const Window &coreEngine;

public:
    void updateUniformBuffer(){};

    model(const Window &coreEngine, const std::string &textPath, const std::string &modelPath);
    model(const model &) = delete;
    model(model &&) = delete;
    ~model();

    static void createCommandBuffers();
    static void executeCommandsBuffers(VkCommandBuffer c, size_t i);

    Image textureImage;
    //    ImageView textureImageView;
    //    VkSampler textureSampler;

    /*    Buffer vertexBuffer;

        Buffer uniformStagingBuffer;

        Buffer uniformBuffer;

        Buffer indexBuffer;*/

    VkDescriptorPool descriptorPool;
    VkDescriptorSet descriptorSet;

    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    std::vector<CommandBuffer> commandBuffers;

    Blob::Maths::Vec3<float> position;

private:
    /*    void createTextureSampler();

        void loadModel(std::string MODEL_PATH);

        void createVertexBuffer();

        void createIndexBuffer();

        void createUniformBuffer();

        void createDescriptorPool();

        void createDescriptorSet();*/
};
}