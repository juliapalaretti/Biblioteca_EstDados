#ifndef BIBLIOTECA_ESTDADOS_LIVRO_H
#define BIBLIOTECA_ESTDADOS_LIVRO_H

typedef struct
{
    int id;
    char titulo[80];
    char autor[80];
    int ano;
} Livro;

int valida_livro(const Livro *livro);

#endif
