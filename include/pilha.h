#ifndef BIBLIOTECA_ESTDADOS_PILHA_H
#define BIBLIOTECA_ESTDADOS_PILHA_H

typedef struct consulta
{
    int id;
    int tipo;
    char termo[200];
} Consulta;

typedef struct elemento* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pilha);
int tamanho_pilha(Pilha* pilha);
int pilha_vazia(Pilha* pilha);

int push(Pilha* pilha, Consulta consulta);
int pop(Pilha* pilha);
int peek(Pilha* pilha, Consulta* consulta);

#endif
