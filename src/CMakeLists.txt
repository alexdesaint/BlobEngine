add_subdirectory(GL)
if (BLOBVK)
    add_subdirectory(VK)
endif ()
add_subdirectory(collision)
add_subdirectory(geometrie)
add_subdirectory(glTF2)
add_subdirectory(Reader)

add_library(Blob STATIC
		Controls.cpp
		Movable.cpp
		ProjectionTransform.cpp
		Renderable.cpp
		Scene.cpp
		Shape.cpp
		Shapes.cpp
		Time.cpp
		Window.cpp
		WindowCore.cpp)
target_include_directories(Blob PUBLIC ../../include)
target_link_libraries(Blob imgui stb glm EnTT Blob::GL Blob::FileReader Blob::Geometrie)
