find_package(GLM QUIET)
if(GLM_FOUND)
    message("Enable GLM test")
    add_executable(TestVec4 TestVec4.cpp)
    target_link_libraries(TestVec4 Blob::Includes)
    target_compile_options(TestVec4 PUBLIC -mavx -O3)
endif()

add_executable(TestMVP TestMVP.cpp)
target_link_libraries(TestMVP Blob::Includes)

add_executable(TestMaths TestMaths.cpp)
target_link_libraries(TestMaths Blob::Includes)
