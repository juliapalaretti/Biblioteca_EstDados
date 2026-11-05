#ifndef BIBLIOTECA_ESTDADOS_LISTA_H
#define BIBLIOTECA_ESTDADOS_LISTA_H

typedef struct livro
{
    int id;
    char titulo[200];
    char autor[100];
    int ano;
} Livro;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* lista);
int tamanho_lista(Lista* lista);
int lista_vazia(Lista* lista);

int insere_lista(Lista* lista, Livro livro);
int remove_lista(Lista* lista, int id);

int consulta_lista_id(Lista* lista, int id, Livro* livro);

#endif