cmake_minimum_required(VERSION 3.10)

project(bintree)

set(SOURCE_LIB bintree.c)		

add_library(bintree STATIC ${SOURCE_LIB})