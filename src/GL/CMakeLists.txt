add_library(BlobGL STATIC
        Window.cpp
        FrameBuffer.cpp
        Shader.cpp
        Texture.cpp
        VertexArrayObject.cpp
        VertexBufferObject.cpp
        Material.cpp
        Types.cpp)

target_link_libraries(BlobGL glad ${OPENGL_gl_LIBRARY} glfw libs)
target_include_directories(BlobGL PUBLIC ${INCLUDE_FOLDER})
add_library(Blob::GL ALIAS BlobGL)
