message("    GL Test are enable")

add_executable(TestGLFW TestGLFW.cpp)
target_link_libraries(TestGLFW glad ${OPENGL_gl_LIBRARY} glfw glm)

add_executable(TestShader TestShader.cpp)
target_link_libraries(TestShader Blob::GL glm)

add_executable(TestCore TestCore.cpp)
target_link_libraries(TestCore Blob::GL Blob::Geometrie)
