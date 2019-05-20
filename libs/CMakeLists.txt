#glad
add_subdirectory(glad)

#json
set(JSON_BuildTests OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory(json)

#glm
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory(glm)

#stb
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb/)

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

#imgui
file(GLOB IMGUIFILES
		"imgui/*.cpp"
		)
add_library(imgui ${IMGUIFILES})
set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(imgui Blob::Geometrie)
target_include_directories(imgui PUBLIC imgui/)

