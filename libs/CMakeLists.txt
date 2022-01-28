# SDL
add_subdirectory(SDL)

# libs
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb/)

# bgfx
add_subdirectory(bgfx)
