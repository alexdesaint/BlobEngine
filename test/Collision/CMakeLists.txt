add_subdirectory(polygon_triangulate)

add_executable(TestForms TestForms.cpp)
target_link_libraries(TestForms Blob nanovg)

add_executable(TestCollision TestCollision.cpp)
target_link_libraries(TestCollision Blob nanovg)

# add_executable(TestFormResolution TestFormResolution.cpp)
# target_link_libraries(TestFormResolution SDL2::SDL2main SDL2::SDL2-static Blob::Collision polygon_triangulate)
