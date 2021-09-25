add_library(gladGL gl.c)
set_target_properties(gladGL PROPERTIES LINKER_LANGUAGE C)
if (UNIX)
    target_link_libraries(gladGL ${CMAKE_DL_LIBS})
endif ()

add_library(gladVulkan vulkan.c)
set_target_properties(gladVulkan PROPERTIES LINKER_LANGUAGE C)
