add_executable(TestInstance TestInstance.cpp)
target_link_libraries(TestInstance Blob::VK)

add_executable(TestVK TestVK.cpp)
target_link_libraries(TestVK Blob::VK)
