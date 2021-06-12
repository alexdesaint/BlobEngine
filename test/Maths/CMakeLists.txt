# FIXME: TestVec4 need glm
#add_executable(TestVec4 TestVec4.cpp)
#target_link_libraries(TestVec4 m Blob::Maths)
#target_compile_options(TestVec4 PUBLIC -mavx)

add_executable(TestMVP TestMVP.cpp)
target_link_libraries(TestMVP Blob::Includes)
