file(GLOB IMGUIFILES RELATIVE ${PROJECT_SOURCE_DIR}/imguiTest "*.cpp")

add_executable(imguiDefaultTest ${IMGUIFILES})
target_link_libraries(imguiDefaultTest BlobGL imgui glad glfw -static -static-libgcc -static-libstdc++ -lpthread)
