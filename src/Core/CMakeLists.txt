add_library(BlobCore STATIC
        RenderOptions.cpp
        Material.cpp
        Mesh.cpp
        Window.cpp
        Shape.cpp
        Scene.cpp
        Shader.cpp
        Controls.cpp
        Primitive.cpp Buffer.cpp)
target_link_libraries(BlobCore Blob::GL Blob::ImGui Blob::Time Blob::GLFW Blob::FileReader)
target_include_directories(BlobCore PUBLIC ../../include)
add_library(Blob::Core ALIAS BlobCore)
