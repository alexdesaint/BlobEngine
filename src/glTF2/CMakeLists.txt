add_library(BlobglTF2 STATIC
        SceneManager.cpp
        Asset.cpp
        Buffer.cpp
        BufferView.cpp
        Accessor.cpp
        Mesh.cpp
        Node.cpp
        Scene.cpp
        Material.cpp
        Texture.cpp
        Image.cpp
        Sampler.cpp)
target_link_libraries(BlobglTF2 Blob Blob::Includes libs)
add_library(Blob::glTF2 ALIAS BlobglTF2)
