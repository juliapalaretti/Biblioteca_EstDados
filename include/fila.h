#ifndef BIBLIOTECA_ESTDADOS_FILA_H
#define BIBLIOTECA_ESTDADOS_FILA_H

typedef struct NoFila {
    int id;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void fila_iniciar(Fila *f);
int fila_enqueue(Fila *f, int id);
int fila_tirar(Fila *f, int *id);
void fila_exibir(const Fila *f);
void fila_liberar(Fila *f);

#endif
