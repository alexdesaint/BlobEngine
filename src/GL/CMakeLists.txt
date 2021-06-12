add_library(BlobGL STATIC
        Window.cpp
        FrameBuffer.cpp
        Shader.cpp
        Texture.cpp
        VertexArrayObject.cpp
        VertexBufferObject.cpp
        Material.cpp
        Types.cpp)

target_link_libraries(BlobGL Blob::Includes Blob::GLFW glad)
add_library(Blob::GL ALIAS BlobGL)
