cmake_minimum_required(VERSION 3.10)

project(Skiena_alghoritms)		

set(SOURCE_EXE main.c)			

include_directories(list bintree)

add_executable(main ${SOURCE_EXE})	

add_subdirectory(list)
add_subdirectory(bintree)

target_link_libraries(main list bintree)
add_definitions("-g")