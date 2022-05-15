file(MAKE_DIRECTORY include/shaders)

set(FILES "")

foreach(vertexShader v_normal vs_ocornut_imgui)
    list(APPEND FILES include/shaders/${vertexShader}.h)
    shaderc(
        FILE ${vertexShader}.sc
        OUTPUT include/shaders/${vertexShader}.h
        LINUX VERTEX
        PROFILE spirv
        INCLUDES ../libs/bgfx/bgfx/src
        BIN2C ${vertexShader})
endforeach()

foreach(fragmentShader f_colorArray f_colorUniform fs_ocornut_imgui)
    list(APPEND FILES include/shaders/${fragmentShader}.h)
    shaderc(
        FILE ${fragmentShader}.sc 
        OUTPUT include/shaders/${fragmentShader}.h 
        LINUX FRAGMENT 
        PROFILE spirv 
        INCLUDES ../libs/bgfx/bgfx/src 
        BIN2C ${fragmentShader})
endforeach()

add_library(BlobShaders INTERFACE ${FILES})
target_include_directories(BlobShaders INTERFACE include/)
add_library(Blob::Shaders ALIAS BlobShaders)
