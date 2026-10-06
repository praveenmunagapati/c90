cmake_minimum_required(VERSION 4.3)
project(c90 C)

set(CMAKE_C_STANDARD 11)

add_executable(c90 main.c
        mylib.h
        mylib.c
)
