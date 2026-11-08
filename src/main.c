#include <stdio.h>

static void exibir_menu();

int main(void)
{
    exibir_menu();
}

static void exibir_menu() {
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
           "================================\n"
           "Escolha uma opcao:\n");
}