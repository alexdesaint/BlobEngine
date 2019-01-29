add_library(BlobGL STATIC VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Scene.cpp Texture.cpp Movable.cpp Form.cpp FrameBufferObject.cpp Text.cpp)
target_link_libraries(BlobGL FileReader Time glfw glad Geometrie ${OPENGL_gl_LIBRARY} libbmpread)
target_include_directories(BlobGL PUBLIC ../../include)
