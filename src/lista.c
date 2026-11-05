#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"

struct elemento
{
    struct livro dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista()
{
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) *li = NULL;
    return li;
}

void libera_lista(Lista* lista)
{
    if (lista != NULL)
    {
        Elem* no;
        while ((*lista) != NULL)
        {
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);
    }
}

int tamanho_lista(Lista* lista)
{
    if (lista == NULL) return 0;
    int cont = 0;
    Elem* no = *lista;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* lista)
{
    if (lista == NULL) return 1;
    if (*lista == NULL) return 1;
    return 0;
}

void lista_imprimir(Lista* lista);

int insere_lista(Lista* lista, Livro livro)
{
    if (lista == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = livro;
    no->prox = NULL;
    if (*lista == NULL)
    {
        *lista = no;
    } else
    {
        Elem *aux = *lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int remove_lista(Lista* lista, int id)
{
    if (lista == NULL) return 0;
    Elem *ant, *no = *lista;
    while (no != NULL && no->dados.id != id)
    {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) return 0;
    if (no == *lista)
    {
        *lista = no->prox;
    } else
    {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_id(Lista* lista, int id, Livro* livro)
{
    if (lista == NULL) return 0;
    Elem* no = *lista;
    while (no != NULL && no->dados.id != id)
    {
        no = no->prox;
    }
    if (no == NULL) return 0;
    *livro = no->dados;
    return 1;
}