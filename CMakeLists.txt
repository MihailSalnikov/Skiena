cmake_minimum_required(VERSION 3.10)

project(Skiena_alghoritms)		

set(SOURCE_EXE main.c)			

include_directories(list)

add_executable(main ${SOURCE_EXE})	

add_subdirectory(list)

target_link_libraries(main list)