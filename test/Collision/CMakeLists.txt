find_package(SFML REQUIRED system window graphics network audio)
IF (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    message("SFML found")
else()
    message(ERROR "SFML not found")
endif()

add_executable(TestForms TestForms.cpp)
target_link_libraries(TestForms sfml-system sfml-graphics sfml-window sfml-audio Blob::Collision)

add_executable(TestCollision TestCollision.cpp)
target_link_libraries(TestCollision sfml-system sfml-graphics sfml-window sfml-audio Blob::Collision)
