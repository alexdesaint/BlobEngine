add_library(BlobVK STATIC
        Buffer.cpp
        CommandBuffer.cpp
        CommandPool.cpp
        DescriptorSetLayout.cpp
        Device.cpp
        DeviceMemory.cpp
        Framebuffer.cpp
        Image.cpp
        ImageView.cpp
        Instance.cpp
        model.cpp
        PhysicalDevice.cpp
#        Pipeline.cpp
        PipelineLayout.cpp
        QueueFamily.cpp
        RenderPass.cpp
        Semaphore.cpp
        Swapchain.cpp
        Window.cpp)

target_link_libraries(BlobVK gladVulkan Blob::GLFW)
target_include_directories(BlobVK PUBLIC ${INCLUDE_FOLDER})
add_library(Blob::VK ALIAS BlobVK)
