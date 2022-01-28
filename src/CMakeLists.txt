add_library(BlobIncludes INTERFACE)
add_library(Blob::Includes ALIAS BlobIncludes)
target_include_directories(BlobIncludes INTERFACE ${INCLUDE_FOLDER})

add_subdirectory(Collision)
add_subdirectory(SDL2)

add_library(Blob STATIC
        Buffer.cpp
        Controls.cpp
        Image.cpp
        Material.cpp
        Mesh.cpp
        Primitive.cpp
        RenderOptions.cpp
        Scene.cpp
        Shader.cpp
        Shape.cpp
        Texture.cpp
        VertexBuffer.cpp
        VertexLayout.cpp
        Window.cpp
        Materials.cpp
        Color.cpp
        FileReader.cpp)
target_link_libraries(Blob LINK_PUBLIC Blob::Includes dear-imgui stb bgfx bx BlobSDL2 BlobShaders)
