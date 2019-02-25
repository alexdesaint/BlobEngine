add_library(BlobglTF2 SceneManager.cpp Asset.cpp Buffer.cpp BufferView.cpp Accessor.cpp Mesh.cpp Shape.cpp Scene.cpp)
add_library(Blob::glTF2 ALIAS BlobglTF2)
target_include_directories(BlobglTF2 PUBLIC ../../include)
