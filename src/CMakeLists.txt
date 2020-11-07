add_subdirectory(GL)
if (BLOBVK)
    add_subdirectory(VK)
endif ()
add_subdirectory(collision)
add_subdirectory(Geometry)
add_subdirectory(glTF2)
add_subdirectory(Reader)
add_subdirectory(Core)

add_library(BlobMaths INTERFACE)
add_library(Blob::Maths ALIAS BlobMaths)
target_include_directories(BlobMaths INTERFACE ../include)

add_library(BlobGLFW STATIC GLFW.cpp Controls.cpp)
target_link_libraries(BlobGLFW glfw glad)
target_include_directories(BlobGLFW PUBLIC ../include)
add_library(Blob::GLFW ALIAS BlobGLFW)

add_library(Blob STATIC
		Time.cpp
		Material.cpp
		Mesh.cpp
		Window.cpp
		Color.cpp
        ImGui.cpp
		Shape.cpp
		Scene.cpp
		Shapes.cpp)
target_include_directories(Blob PUBLIC ../include)
target_link_libraries(Blob imgui Blob::GLFW Blob::GL Blob::FileReader Blob::Core::RenderOptions)
