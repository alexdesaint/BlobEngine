add_executable(TestForms TestForms.cpp)
target_link_libraries(TestForms SDL2::SDL2main SDL2::SDL2-static Blob::Collision)

add_executable(TestCollision TestCollision.cpp)
target_link_libraries(TestCollision SDL2::SDL2main SDL2::SDL2-static Blob::Collision)

add_executable(TestFormResolution TestFormResolution.cpp)
target_link_libraries(TestFormResolution SDL2::SDL2main SDL2::SDL2-static Blob::Collision)
