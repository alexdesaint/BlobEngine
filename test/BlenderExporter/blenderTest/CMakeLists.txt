add_library(blenderTest STATIC src/Meshes/Cube.cpp)
target_link_libraries(blenderTest Blob)
target_include_directories(blenderTest PUBLIC include/)