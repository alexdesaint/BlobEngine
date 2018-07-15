add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp)
target_link_libraries(BlobGL FileReader glTF2Loader)
