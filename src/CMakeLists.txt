add_library(BlobIncludes INTERFACE)
target_include_directories(BlobIncludes INTERFACE ${INCLUDE_FOLDER})
add_library(Blob::Includes ALIAS BlobIncludes)

file(GLOB_RECURSE SRCS *.cpp)

add_library(Blob STATIC ${SRCS})
target_link_libraries(Blob LINK_PUBLIC Blob::Includes imgui stb glfw bgfx bx Blob::Shaders)
