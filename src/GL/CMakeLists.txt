add_library(BlobGL STATIC VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Scene.cpp Texture.cpp Movable.cpp Shapes.cpp FrameBufferObject.cpp)
add_library(Blob::GL ALIAS BlobGL)
target_link_libraries(BlobGL Blob::FileReader Blob::Time glfw glad Blob::Geometrie imgui ${OPENGL_gl_LIBRARY} stb glm)
target_include_directories(BlobGL PUBLIC ../../include)
