add_library(BlobGL VertexArrayObject.cpp VertexBufferObject.cpp ShaderProgram.cpp Renderable.cpp Graphic.cpp Shape.cpp Scene.cpp Texture.cpp Movable.cpp)
target_link_libraries(BlobGL FileReader glad -lglu32 -lopengl32 ${SDL2_LIBRARIES} sfml-graphics)
