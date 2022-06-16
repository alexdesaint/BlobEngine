message("Blob Test are enabled")

add_executable(TestNanovg TestNanovg.cpp)
target_link_libraries(TestNanovg Blob nanovg)

add_subdirectory(BlenderExporter)
add_subdirectory(Maths)
add_subdirectory(Collision)
