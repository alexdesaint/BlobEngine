add_library(BlobglTF2 STATIC SceneManager.cpp Asset.cpp Buffer.cpp BufferView.cpp Accessor.cpp Mesh.cpp Node.cpp Scene.cpp Material.cpp Texture.cpp Image.cpp Sampler.cpp)
add_library(Blob::glTF2 ALIAS BlobglTF2)
target_link_libraries(BlobglTF2 BlobGL nlohmann_json)
target_include_directories(BlobglTF2 PUBLIC ../../include)
