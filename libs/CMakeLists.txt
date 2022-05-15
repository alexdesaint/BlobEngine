# glfw
add_subdirectory(glfw)

# libs
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb/)

#imgui
file(GLOB IMGUIFILES "imgui/*.cpp")
add_library(imgui ${IMGUIFILES})
target_compile_definitions(imgui
    PUBLIC IMGUI_USER_CONFIG=<imconfigUser.h>
    PUBLIC IMGUI_DISABLE_INCLUDE_IMCONFIG_H)
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(imgui Blob::Includes glfw)
target_include_directories(imgui PUBLIC imgui/ imguiConfig/)

# bgfx
add_subdirectory(bgfx)

# nanovg bgfx/bgfx/examples/common/nanovg/nanovg.h

file(GLOB NANOVGFILES "bgfx/bgfx/examples/common/nanovg/*.cpp")
add_library(nanovg ${NANOVGFILES})
target_include_directories(imgui PUBLIC bgfx/bgfx/examples/common/nanovg)
target_link_libraries(nanovg bgfx bx stb)