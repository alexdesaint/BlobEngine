# glad
add_subdirectory(glad)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

# SDL
add_subdirectory(SDL)

#imgui
file(GLOB IMGUIFILES "imgui/*.cpp")
add_library(imgui ${IMGUIFILES} imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp)
target_compile_definitions(imgui 
    PUBLIC IMGUI_USER_CONFIG=<imconfigUser.h> 
    PUBLIC IMGUI_DISABLE_INCLUDE_IMCONFIG_H
    PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(imgui Blob::Includes glfw gladGL)
target_include_directories(imgui PUBLIC imgui/ imguiConfig/)

# libs
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb/)
