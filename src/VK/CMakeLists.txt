

add_library(BlobVK STATIC Instance.cpp PhysicalDevice.cpp QueueFamily.cpp Device.cpp)
add_library(Blob::VK ALIAS BlobVK)
target_link_libraries(BlobVK glfw Vulkan)
target_include_directories(BlobVK PUBLIC ../../include)
