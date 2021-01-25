add_library(BlobVK STATIC
        Window.cpp
        model.cpp
        Device.cpp
        Image.cpp
        ImageView.cpp
        Framebuffer.cpp
        RenderPass.cpp
        DescriptorSetLayout.cpp
        PipelineLayout.cpp
        Pipeline.cpp
        CommandPool.cpp
        DeviceMemory.cpp
        CommandBuffer.cpp
        Semaphore.cpp
        Swapchain.cpp
        Buffer.cpp)

target_link_libraries(BlobVK Blob::GLFW Vulkan::Vulkan)
target_include_directories(BlobVK PUBLIC ${INCLUDE_FOLDER})
add_library(Blob::VK ALIAS BlobVK)
