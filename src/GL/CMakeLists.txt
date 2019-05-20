add_library(BlobGL STATIC
        FrameBufferObject.cpp
        Graphic.cpp
        Movable.cpp
        Renderable.cpp
        Scene.cpp
        ShaderProgram.cpp
        Shape.cpp
        Shapes.cpp
        Texture.cpp
        VertexArrayObject.cpp
        VertexBufferObject.cpp
        )
add_library(Blob::GL ALIAS BlobGL)
target_link_libraries(BlobGL Blob::FileReader Blob::Time Blob::Controls glfw glad Blob::Geometrie imgui ${OPENGL_gl_LIBRARY} stb glm)
target_include_directories(BlobGL PUBLIC ../../include)
