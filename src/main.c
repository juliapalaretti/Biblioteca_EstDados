#include <stdio.h>

int menu();

int main(void)
{
    menu();
}

int menu() {
    printf("================================\n"
           "MENU DA BIBLIOTECA\n"
           "================================\n"
           "1 - Cadastrar Livro (cria vertice)\n"
           "2 - Buscar Livro (BST)\n"
           "3 - Remover Livro e vertice/arestas\n"
           "4 - Listar Livros (BST em ordem)\n"
           "5 - Ordenar e Exibir Livros por nome/título\n"
           "6 - Adicionar conexão (aresta)\n"
           "7 - Remover conexão (aresta)\n"
           "8 - Consultar conexão direta\n"
           "9 - Listar alcancaveis (BFS + lista)\n"
           "10 - Verificar caminho entre 2 IDs\n"
           "11 - Consultar historico (pilha)\n"
           "0 - Encerrar\n"
           "================================\n"
           "Escolha uma opcao:\n");
}