add_subdirectory(glad)
add_subdirectory(rapidjson)
add_subdirectory(libbmpread)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

file(GLOB IMGUIFILES
		"imgui/*.cpp"
		)

add_library(imgui ${IMGUIFILES})
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(imgui PUBLIC imgui/)
target_include_directories(imgui PUBLIC imgui/examples)