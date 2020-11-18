message("    GL Test are enable")

add_executable(TestShader TestShader.cpp)
target_link_libraries(TestShader Blob::GL)

add_executable(TestGLFW TestGLFW.cpp)
target_link_libraries(TestGLFW Blob::GLFW Blob::GL)

add_executable(TestCore TestCore.cpp)
target_link_libraries(TestCore Blob::GL)
