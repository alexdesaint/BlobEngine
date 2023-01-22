set(FILES "")

set(BGFX_SHADER_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/libs/bgfx/bgfx/src)

add_executable(bgfx::shaderc ALIAS shaderc)

foreach(shader v_normal vs_ocornut_imgui)
    set(inFile ${CMAKE_CURRENT_SOURCE_DIR}/${shader}.sc)
    list(APPEND FILES ${inFile})
    bgfx_compile_shader_to_header(
        TYPE VERTEX
        SHADERS ${inFile}
        VARYING_DEF ${CMAKE_CURRENT_SOURCE_DIR}/varying.def.sc
        OUTPUT_DIR ${PROJECT_SOURCE_DIR}/include/shaders
    )
endforeach()

foreach(shader f_colorArray f_colorUniform fs_ocornut_imgui)
    set(inFile ${CMAKE_CURRENT_SOURCE_DIR}/${shader}.sc)
    list(APPEND FILES ${inFile})
    bgfx_compile_shader_to_header(
        TYPE FRAGMENT
        SHADERS ${inFile}
        VARYING_DEF ${CMAKE_CURRENT_SOURCE_DIR}/varying.def.sc
        OUTPUT_DIR ${PROJECT_SOURCE_DIR}/include/shaders
    )
endforeach()

add_library(BlobShaders INTERFACE ${FILES})
target_include_directories(BlobShaders INTERFACE ${PROJECT_SOURCE_DIR}/include)
add_library(Blob::Shaders ALIAS BlobShaders)
