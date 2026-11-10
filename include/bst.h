#ifndef BIBLIOTECA_ESTDADOS_BST_H
#define BIBLIOTECA_ESTDADOS_BST_H

typedef struct {
    int id;
    char titulo[80];
    char autor[80];
    int ano;
} Livro;

typedef struct No {
    Livro livro;
    struct No *esq;
    struct No *dir;
} No;

No *bst_inserir(No *raiz, Livro livro, int *status);
No *bst_buscar(No *raiz, int id);
No *bst_remover(No *raiz, int id);
void bst_listar_em_ordem(const No *raiz);
void bst_liberar(No *raiz);

#endif