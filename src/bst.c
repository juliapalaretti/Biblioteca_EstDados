#include <stdio.h>
#include <stdlib.h>
#include "../include/bst.h"

No *bst_inserir(No *raiz, Livro livro, int *status) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        if (novo == NULL) {
            *status = -1;
            return NULL;
        }
        novo->livro = livro;
        novo->esq = NULL;
        novo->dir = NULL;
        *status = 1;
        return novo;
    }
    if (livro.id < raiz->livro.id) {
        raiz->esq = bst_inserir(raiz->esq, livro, status);
    } else if (livro.id > raiz->livro.id) {
        raiz->dir = bst_inserir(raiz->dir, livro, status);
    } else {
        *status = 0;
    }
    return raiz;
}

No *bst_buscar(No *raiz, int id) {
    while (raiz != NULL && raiz->livro.id != id) {
        raiz = (id < raiz->livro.id) ? raiz->esq : raiz->dir;
    }
    return raiz;
}

static No *menor_no(No *raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

No *bst_remover(No *raiz, int id) {
    if (raiz == NULL) {
        return NULL;
    }
    if (id < raiz->livro.id) {
        raiz->esq = bst_remover(raiz->esq, id);
    } else if (id > raiz->livro.id) {
        raiz->dir = bst_remover(raiz->dir, id);
    } else if (raiz->esq == NULL) {
        No *filho = raiz->dir;
        free(raiz);
        return filho;
    } else if (raiz->dir == NULL) {
        No *filho = raiz->esq;
        free(raiz);
        return filho;
    } else {
        No *sucessor = menor_no(raiz->dir);
        raiz->livro = sucessor->livro;
        raiz->dir = bst_remover(raiz->dir, sucessor->livro.id);
    }
    return raiz;
}

void bst_listar_em_ordem(const No *raiz) {
    if (raiz == NULL) {
        return;
    }
    bst_listar_em_ordem(raiz->esq);
    printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
           raiz->livro.id, raiz->livro.titulo, raiz->livro.autor, raiz->livro.ano);
    bst_listar_em_ordem(raiz->dir);
}

void bst_liberar(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    bst_liberar(raiz->esq);
    bst_liberar(raiz->dir);
    free(raiz);
}