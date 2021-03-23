add_executable(TestForms TestForms.cpp)
target_link_libraries(TestForms mingw32 SDL2::SDL2main SDL2::SDL2-static Blob::Collision)

add_executable(TestCollision TestCollision.cpp)
target_link_libraries(TestCollision mingw32 SDL2::SDL2main SDL2::SDL2-static Blob::Collision)
