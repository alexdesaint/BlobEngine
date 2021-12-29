message("    Core Test are enable")

add_executable(TestDynamicDrawCallList TestDynamicDrawCallList.cpp)
target_link_libraries(TestDynamicDrawCallList Blob::Core)