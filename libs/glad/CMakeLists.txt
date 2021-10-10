add_subdirectory(src)
target_include_directories(gladGL PUBLIC include)
target_include_directories(gladVulkan PUBLIC include)
target_compile_options(gladGL PRIVATE "-fPIC")
