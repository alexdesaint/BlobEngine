add_library(BlobGL STATIC VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Scene.cpp Texture.cpp Movable.cpp Form.cpp FrameBufferObject.cpp)
target_link_libraries(BlobGL FileReader Time glfw glad ${OPENGL_gl_LIBRARY} libbmpread)
target_include_directories(BlobGL PUBLIC ../../include)
