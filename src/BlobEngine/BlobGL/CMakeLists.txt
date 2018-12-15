add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Shape.hpp)
target_link_libraries(BlobGL FileReader glad)
