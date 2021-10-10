add_library(BlobGL STATIC
        FrameBuffer.cpp
        Shader.cpp
        ShaderProgram.cpp
        Texture.cpp
        Types.cpp
        VertexArrayObject.cpp
        VertexBufferObject.cpp
        Window.cpp)

target_link_libraries(BlobGL LINK_PUBLIC Blob::Includes Blob::GLFW gladGL)
add_library(Blob::GL ALIAS BlobGL)
target_compile_options(BlobGL PRIVATE "-fPIC")

