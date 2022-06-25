file(MAKE_DIRECTORY include/shaders)

set(FILES "")

foreach(shader v_normal vs_ocornut_imgui)
    set(inFile ${CMAKE_CURRENT_SOURCE_DIR}/${shader}.sc)
    set(outFile ${CMAKE_CURRENT_SOURCE_DIR}/include/shaders/${shader}.h)
    list(APPEND FILES ${outFile})
    shaderc(
        FILE ${inFile}
        OUTPUT ${outFile}
        LINUX VERTEX
        PROFILE spirv
        INCLUDES ../libs/bgfx/bgfx/src
        BIN2C ${shader})
endforeach()

foreach(shader f_colorArray f_colorUniform fs_ocornut_imgui)
    set(inFile ${CMAKE_CURRENT_SOURCE_DIR}/${shader}.sc)
    set(outFile ${CMAKE_CURRENT_SOURCE_DIR}/include/shaders/${shader}.h)
    list(APPEND FILES ${outFile})
    shaderc(
        FILE ${inFile}
        OUTPUT ${outFile}
        LINUX FRAGMENT 
        PROFILE spirv 
        INCLUDES ../libs/bgfx/bgfx/src 
        BIN2C ${shader})
endforeach()

add_library(BlobShaders INTERFACE ${FILES})
target_include_directories(BlobShaders INTERFACE include/)
add_library(Blob::Shaders ALIAS BlobShaders)
