cmake_minimum_required(VERSION 4.3)
project(Biblioteca_EstDados C)

set(CMAKE_C_STANDARD 11)

add_executable(Biblioteca_EstDados src/main.c
        src/bst.c
        include/bst.h
        src/fila.c
        include/fila.h
)
