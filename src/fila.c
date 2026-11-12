#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"

void fila_iniciar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int fila_enqueue(Fila *f, int id) {
    NoFila *novo = malloc(sizeof(NoFila));
    if (novo == NULL) {
        return 0;
    }
    novo->id = id;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return 1;
}

int fila_tirar(Fila *f, int *id) {
    if (f->inicio == NULL) {
        return 0;
    }
    NoFila *remover = f->inicio;
    *id = remover->id;
    f->inicio = remover->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(remover);
    return 1;
}

void fila_exibir(const Fila *f) {
    const NoFila *atual = f->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("%d) ID %d\n", posicao++, atual->id);
        atual = atual->prox;
    }
}

void fila_liberar(Fila *f) {
    int descartado;
    while (fila_tirar(f, &descartado)) { }
}