add_executable(TestInstance TestInstance.cpp)
target_link_libraries(TestInstance Blob::VK)

add_executable(TestPhysicalDevice TestPhysicalDevice.cpp)
target_link_libraries(TestPhysicalDevice Blob::VK)

add_executable(TestQueueFamily TestQueueFamily.cpp)
target_link_libraries(TestQueueFamily Blob::VK)
