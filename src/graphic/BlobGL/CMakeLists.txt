add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp ../../../include/BlobEngine/BlobGL/Buffer.cpp ../../../include/BlobEngine/BlobGL/Buffer.hpp)
target_link_libraries(BlobGL FileReader glTF2Loader glad)
