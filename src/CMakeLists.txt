add_library(BlobIncludes INTERFACE)
add_library(Blob::Includes ALIAS BlobIncludes)
target_include_directories(BlobIncludes INTERFACE ${INCLUDE_FOLDER})

add_subdirectory(Collision)
add_subdirectory(Core)
add_subdirectory(GL)
add_subdirectory(VK)

add_library(BlobGLFW STATIC GLFW.cpp)
target_link_libraries(BlobGLFW glfw Blob::Includes)
add_library(Blob::GLFW ALIAS BlobGLFW)
target_compile_options(BlobGLFW PRIVATE "-fPIC")

add_library(Blob STATIC Materials.cpp Shapes.cpp Color.cpp FileReader.cpp)
target_link_libraries(Blob LINK_PUBLIC Blob::Core gladGL)
set_target_properties(Blob PROPERTIES RESOURCE ${SHADERS_FOLDER}/frag.spv)
