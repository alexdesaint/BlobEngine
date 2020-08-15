#glad
add_subdirectory(glad)

#glm
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory(glm)

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

#imgui
file(GLOB IMGUIFILES "imgui/*.cpp")
add_library(imgui ${IMGUIFILES})
target_compile_definitions(imgui INTERFACE IMGUI_USER_CONFIG=<imconfigUser.h> INTERFACE IMGUI_DISABLE_INCLUDE_IMCONFIG_H)
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(imgui Blob::Geometrie)
target_include_directories(imgui PUBLIC imgui/ imguiConfig/)

# libs
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE stb/ include/)
target_compile_definitions(libs INTERFACE TINYGLTF_USE_CPP14)

#json
file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/master/single_include/nlohmann/json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann/json.hpp SHOW_PROGRESS)

#entt
file(DOWNLOAD https://raw.githubusercontent.com/skypjack/entt/master/single_include/entt/entt.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/entt/entt.hpp SHOW_PROGRESS)

#tinygltf
file(DOWNLOAD https://raw.githubusercontent.com/syoyo/tinygltf/master/tiny_gltf.h ${CMAKE_CURRENT_SOURCE_DIR}/include/tiny_gltf.h SHOW_PROGRESS)
