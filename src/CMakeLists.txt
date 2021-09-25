add_library(BlobIncludes INTERFACE)
add_library(Blob::Includes ALIAS BlobIncludes)
target_include_directories(BlobIncludes INTERFACE ${INCLUDE_FOLDER})

add_subdirectory(Collision)
add_subdirectory(Core)
add_subdirectory(GL)
add_subdirectory(Reader)
add_subdirectory(SDL2)
add_subdirectory(VK)

add_library(BlobColor STATIC Color.cpp)
target_link_libraries(BlobColor Blob::Includes)
add_library(Blob::Color ALIAS BlobColor)

add_library(BlobGLFW STATIC GLFW.cpp)
target_link_libraries(BlobGLFW glfw gladGL Blob::Includes)
add_library(Blob::GLFW ALIAS BlobGLFW)

add_library(BlobMaterials STATIC Materials.cpp)
target_link_libraries(BlobMaterials Blob::Color Blob::Core)
add_library(Blob::Materials ALIAS BlobMaterials)

add_library(BlobShapes STATIC Shapes.cpp)
target_link_libraries(BlobShapes Blob::Materials)
add_library(Blob::Shapes ALIAS BlobShapes)

add_library(Blob INTERFACE)
target_link_libraries(Blob INTERFACE Blob::Core Blob::Materials Blob::Shapes)