add_library(BlobCore STATIC
        RenderOptions.cpp
        Material.cpp
        Mesh.cpp
        Window.cpp
        Shape.cpp
        Scene.cpp
        Shader.cpp
        Controls.cpp
        Primitive.cpp
        Buffer.cpp
        Texture.cpp Image.cpp)
target_link_libraries(BlobCore Blob::Includes Blob::GL imgui Blob::Time Blob::FileReader libs)
add_library(Blob::Core ALIAS BlobCore)
