add_subdirectory(GL)
if (BLOBVK)
    add_subdirectory(VK)
endif ()
add_subdirectory(collision)
add_subdirectory(geometrie)
add_subdirectory(glTF2)
add_subdirectory(Reader)

add_library(BlobImGUI STATIC
		ImGUI.cpp)
target_include_directories(BlobImGUI PUBLIC ../../include)
target_link_libraries(BlobImGUI imgui Blob::GL Blob::Geometrie)

add_library(BlobCore STATIC
		Controls.cpp
		Time.cpp
		Material.cpp
		Renderable.cpp
		Window.cpp
		WindowCore.cpp
		Color.cpp
		ImGUI.cpp)
target_include_directories(BlobCore PUBLIC ../../include)
target_link_libraries(BlobCore imgui stb EnTT Blob::GL Blob::FileReader Blob::Geometrie)

add_library(Blob STATIC
		Shape.cpp
		Scene.cpp
		Shapes.cpp)
target_include_directories(Blob PUBLIC ../../include)
target_link_libraries(Blob BlobCore BlobImGUI)
