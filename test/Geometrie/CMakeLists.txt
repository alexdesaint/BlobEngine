add_executable(TestFastInverse TestFastInverse.c)
target_link_libraries(TestFastInverse m)
target_compile_options(TestFastInverse PUBLIC -mavx)
