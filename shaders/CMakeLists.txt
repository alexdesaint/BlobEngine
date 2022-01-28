file(MAKE_DIRECTORY include/shaders)

shaderc(FILE v_normal.sc OUTPUT include/shaders/v_normal.h LINUX VERTEX PROFILE spirv INCLUDES ../libs/bgfx/bgfx/src BIN2C v_normal)
shaderc(FILE f_colorArray.sc OUTPUT include/shaders/f_colorArray.h LINUX FRAGMENT PROFILE spirv INCLUDES ../libs/bgfx/bgfx/src BIN2C f_colorArray)

add_library(BlobShaders INTERFACE include/shaders/v_normal.h include/shaders/f_colorArray.h)
target_include_directories(BlobShaders INTERFACE include/)
