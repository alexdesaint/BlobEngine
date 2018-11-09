add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Buffer.cpp Shape.cpp Graphic.cpp)
target_link_libraries(BlobGL FileReader glTF2Loader glad)
