add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Shape.cpp Graphic.cpp)
target_link_libraries(BlobGL FileReader glad)
