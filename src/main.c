#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bst.h"
#include "../include/fila.h"

void exibir_menu();
int ler_linha(char *buf, size_t tam);
void aparar(char *s);
int ler_inteiro(const char *prompt, int min, int max, int *valor);
int ler_texto(const char *prompt, char *destino);
void cadastrar(No **raiz);
void buscar(No *raiz);
void remover_livro(No **raiz);
void listar(No *raiz);
void enfileirar(Fila *fila);
void desenfileirar(Fila *fila);
void exibir_fila(const Fila *fila);

int main(void)
{
    No *raiz = NULL;
    Fila fila;
    fila_iniciar(&fila);

    int opcao = -1;
    do {
        exibir_menu();
        int r = ler_inteiro("Escolha uma opcao: ", 0, 7, &opcao);
        if (r == -1) {
            break;
        }
        if (r == 0) {
            opcao = -1;
            continue;
        }
        switch (opcao) {
        case 1: cadastrar(&raiz); break;
        case 2: buscar(raiz); break;
        case 3: remover_livro(&raiz); break;
        case 4: listar(raiz); break;
        case 5: enfileirar(&fila); break;
        case 6: desenfileirar(&fila); break;
        case 7: exibir_fila(&fila); break;
        case 0: break;
        }
    } while (opcao != 0);

    bst_liberar(raiz);
    fila_liberar(&fila);
    return 0;
}

void exibir_menu() {
    printf("================================\n"
           "MENU DA BIBLIOTECA\n"
           "================================\n"
           "1 - Cadastrar registro na BST\n"
           "2 - Buscar registro por ID na BST\n"
           "3 - Remover registro da BST\n"
           "4 - Listar registros em-ordem\n"
           "5 - Inserir ID na fila\n"
           "6 - Remover da fila\n"
           "7 - Exibir fila\n"
           "0 - Encerrar\n"
           "================================\n");
}

int ler_linha(char *buf, size_t tam) {
    if (fgets(buf, (int)tam, stdin) == NULL) {
        return -1;
    }
    size_t n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') {
        buf[n - 1] = '\0';
        return 1;
    }
    int c, excedeu = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        excedeu = 1;
    }
    return excedeu ? 0 : 1;
}

void aparar(char *s) {
    size_t ini = 0, fim = strlen(s);
    while (s[ini] != '\0' && isspace((unsigned char)s[ini])) {
        ini++;
    }
    while (fim > ini && isspace((unsigned char)s[fim - 1])) {
        fim--;
    }
    memmove(s, s + ini, fim - ini);
    s[fim - ini] = '\0';
}

int ler_inteiro(const char *prompt, int min, int max, int *valor) {
    char linha[256];
    printf("%s", prompt);
    int r = ler_linha(linha, sizeof linha);
    if (r == -1) {
        return -1;
    }
    if (r == 0) {
        printf("Entrada invalida: texto longo demais.\n");
        return 0;
    }
    aparar(linha);
    char *fim;
    errno = 0;
    long v = strtol(linha, &fim, 10);
    if (linha[0] == '\0' || *fim != '\0' || errno == ERANGE || v < min || v > max) {
        printf("Entrada invalida: informe um inteiro entre %d e %d.\n", min, max);
        return 0;
    }
    *valor = (int)v;
    return 1;
}

int ler_texto(const char *prompt, char *destino) {
    char linha[256];
    printf("%s", prompt);
    int r = ler_linha(linha, sizeof linha);
    if (r == -1) {
        return -1;
    }
    if (r == 0) {
        printf("Entrada invalida: texto longo demais (maximo 79 caracteres).\n");
        return 0;
    }
    aparar(linha);
    if (linha[0] == '\0') {
        printf("Entrada invalida: o texto nao pode ser vazio.\n");
        return 0;
    }
    if (strlen(linha) > 79) {
        printf("Entrada invalida: texto longo demais (maximo 79 caracteres).\n");
        return 0;
    }
    strcpy(destino, linha);
    return 1;
}

void cadastrar(No **raiz) {
    Livro livro;
    if (ler_inteiro("ID: ", 1, INT_MAX, &livro.id) != 1) {
        return;
    }
    if (bst_buscar(*raiz, livro.id) != NULL) {
        printf("ID duplicado: ja existe um livro com o ID %d.\n", livro.id);
        return;
    }
    if (ler_texto("Titulo: ", livro.titulo) != 1) {
        return;
    }
    if (ler_texto("Autor: ", livro.autor) != 1) {
        return;
    }
    if (ler_inteiro("Ano de publicacao (1 a 2026): ", 1, 2026, &livro.ano) != 1) {
        return;
    }
    int status;
    *raiz = bst_inserir(*raiz, livro, &status);
    if (status == 1) {
        printf("Livro cadastrado com sucesso.\n");
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void buscar(No *raiz) {
    int id;
    if (ler_inteiro("ID a buscar: ", 1, INT_MAX, &id) != 1) {
        return;
    }
    No *no = bst_buscar(raiz, id);
    if (no == NULL) {
        printf("Livro com ID %d nao encontrado.\n", id);
    } else {
        printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
               no->livro.id, no->livro.titulo, no->livro.autor, no->livro.ano);
    }
}

void remover_livro(No **raiz) {
    if (*raiz == NULL) {
        printf("A BST esta vazia. Nada para remover.\n");
        return;
    }
    int id;
    if (ler_inteiro("ID a remover: ", 1, INT_MAX, &id) != 1) {
        return;
    }
    if (bst_buscar(*raiz, id) == NULL) {
        printf("Livro com ID %d nao encontrado.\n", id);
        return;
    }
    *raiz = bst_remover(*raiz, id);
    printf("Livro removido com sucesso.\n");
}

void listar(No *raiz) {
    if (raiz == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    bst_listar_em_ordem(raiz);
}

void enfileirar(Fila *fila) {
    int id;
    if (ler_inteiro("ID do livro para a fila de emprestimos: ", 1, INT_MAX, &id) != 1) {
        return;
    }
    if (fila_enqueue(fila, id)) {
        printf("ID %d inserido na fila.\n", id);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void desenfileirar(Fila *fila) {
    int id;
    if (fila_tirar(fila, &id)) {
        printf("ID %d removido da fila.\n", id);
    } else {
        printf("A fila esta vazia. Nada para remover.\n");
    }
}

void exibir_fila(const Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }
    fila_exibir(fila);
}