add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Scene.cpp Texture.cpp Movable.cpp Form.cpp)
target_link_libraries(BlobGL FileReader glad -lglu32 -lopengl32 sfml-system sfml-graphics sfml-window)
