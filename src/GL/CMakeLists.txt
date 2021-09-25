add_library(BlobGL STATIC
        FrameBuffer.cpp
        Shader.cpp
        ShaderProgram.cpp
        Texture.cpp
        Types.cpp
        VertexArrayObject.cpp
        VertexBufferObject.cpp
        Window.cpp)

target_link_libraries(BlobGL Blob::Includes Blob::GLFW gladGL)
add_library(Blob::GL ALIAS BlobGL)
