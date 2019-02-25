add_executable(testInstance testInstance.cpp)
target_link_libraries(testInstance Blob::VK)

add_executable(testPhysicalDevice testPhysicalDevice.cpp)
target_link_libraries(testPhysicalDevice Blob::VK)

add_executable(testQueueFamily testQueueFamily.cpp)
target_link_libraries(testQueueFamily Blob::VK)
