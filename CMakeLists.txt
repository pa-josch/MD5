#cmake_minimum_required(VERSION 3.19)
project(MD5 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

add_executable(MD5 main.c main_preproc.c md5.c)
target_link_libraries(MD5 m)

#target_compile_options(test_int PRIVATE -Wall -D ENABLE_LOCAL_MAIN -O2)
#target_compile_options(test_double_obj PRIVATE -Wall -O2 -save-temps)