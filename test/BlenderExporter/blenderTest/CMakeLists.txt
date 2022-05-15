add_library(blenderTest STATIC src/Meshes/Cube.cpp
    src/Meshes/Cylinder.cpp
    src/Meshes/Sphere.cpp)
target_link_libraries(blenderTest Blob)
target_include_directories(blenderTest PUBLIC include/)