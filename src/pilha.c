#include <stdio.h>
#include <stdlib.h>
#include "../include/pilha.h"

struct elemento
{
    struct consulta dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Pilha* cria_pilha()
{
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL) *pi = NULL;
    return pi;
}

void libera_pilha(Pilha* pilha)
{
    if (pilha != NULL)
    {
        Elem* no;
        while ((*pilha) != NULL)
        {
            no = *pilha;
            *pilha = (*pilha)->prox;
            free(no);
        }
        free(pilha);
    }
}

int tamanho_pilha(Pilha* pilha)
{
    if (pilha == NULL) return 0;
    int cont = 0;
    Elem* no = *pilha;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_vazia(Pilha* pilha)
{
    if (pilha == NULL) return 1;
    if (*pilha == NULL) return 1;
    return 0;
}

int push(Pilha* pilha, Consulta consulta)
{
    if (pilha == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = consulta;
    no->prox = *pilha;
    *pilha = no;
    return 1;
}

int pop(Pilha* pilha)
{
    if (pilha == NULL || *pilha == NULL) return 0;
    Elem* no = *pilha;
    *pilha = no->prox;
    free(no);
    return 1;
}

int peek(Pilha* pilha, Consulta* consulta)
{
    if (pilha == NULL || *pilha == NULL || consulta == NULL) return 0;
    *consulta = (*pilha)->dados;
    return 1;
}