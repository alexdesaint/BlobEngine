# glad
add_subdirectory(glad)

# Vulkan
add_subdirectory(Vulkan-Headers)
add_subdirectory(Vulkan-Loader)

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
add_library(imgui ${IMGUIFILES})
target_compile_definitions(imgui INTERFACE IMGUI_USER_CONFIG=<imconfigUser.h> INTERFACE IMGUI_DISABLE_INCLUDE_IMCONFIG_H)
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(imgui Blob::Maths)
target_include_directories(imgui PUBLIC imgui/ imguiConfig/)

# libs
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE stb/ include/)
target_compile_definitions(libs INTERFACE TINYGLTF_USE_CPP14)

#json
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann/json.hpp)
    file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/master/single_include/nlohmann/json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann/json.hpp SHOW_PROGRESS)
endif ()