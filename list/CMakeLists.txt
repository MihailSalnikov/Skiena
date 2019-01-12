cmake_minimum_required(VERSION 3.10)

project(list)

set(SOURCE_LIB list.c)		

add_library(list STATIC ${SOURCE_LIB})