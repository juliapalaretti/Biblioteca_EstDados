cmake_minimum_required(VERSION 4.3)
project(Biblioteca_EstDados C)

set(CMAKE_C_STANDARD 11)

add_executable(Biblioteca_EstDados src/main.c
        src/lista.c
        include/lista.h
        src/bst.c
        include/bst.h
        src/ordenacao.c
        include/ordenacao.h
        src/pilha.c
        include/pilha.h
        src/grafo.c
        include/grafo.h
        src/fila.c
        include/fila.h)
