# Sistema de Gerenciamento de Biblioteca

## 1. Sobre o projeto

Este projeto consiste em um sistema simples de gerenciamento de biblioteca, desenvolvido em linguagem C como parte da disciplina de Estrutura de Dados.

O programa permite cadastrar, consultar, remover e listar livros, além de gerenciar uma fila independente de IDs. O desenvolvimento teve como objetivo aplicar conceitos de estruturas de dados dinâmicas, alocação de memória, ponteiros, modularização e manipulação de dados.

## 2. Estruturas de dados utilizadas

Foram escolhidas duas estruturas de dados para organizar e manipular as informações do sistema:

### Árvore Binária de Busca (BST)

A Árvore Binária de Busca foi utilizada para armazenar os livros cadastrados, utilizando seus IDs como critério de organização.

Cada nó contém os dados de um livro e dois ponteiros: um para o filho à esquerda e outro para o filho à direita. Na árvore, IDs menores são armazenados à esquerda e IDs maiores à direita.
Essa organização permite realizar operações de busca, inserção e remoção. Além disso, o percurso em ordem permite listar os livros em ordem crescente de ID.

### Fila encadeada

A fila foi implementada utilizando alocação dinâmica e nós encadeados, seguindo o princípio FIFO (*First In, First Out*), no qual o primeiro elemento inserido é o primeiro a ser removido.

Cada nó armazena apenas o ID de um livro e um ponteiro para o próximo elemento. A fila funciona de maneira independente da árvore, o que permite inserir IDs repetidos ou que não correspondam a livros cadastrados.

## 3. Estrutura do projeto

O projeto foi organizado em diretórios para separar as declarações das estruturas de dados de suas respectivas interfaces e do programa principal.

```text
Biblioteca_EstDados/
│
├── docs/
│   ├── Documentação Técnica.pdf       # Documento técnico do projeto
│
├── include/
│   ├── bst.h       # Definições da árvore e da estrutura Livro
│   └── fila.h      # Definições da fila encadeada
│
├── src/
│   ├── bst.c       # Operações da árvore binária de busca
│   ├── fila.c      # Operações da fila encadeada
│   └── main.c      # Menu e lógica principal do sistema
│
├── CMakeLists.txt  # Configurações de compilação
└── README.md       # Documentação do projeto
```

## 4. Tecnologias e ambiente de desenvolvimento

- **Linguagem:** C
- **Padrão:** C11
- **Sistema operacional utilizado:** Windows
- **IDE:** CLion
- **Sistema de build:** CMake

## 5. Compilação e execução

O projeto foi desenvolvido e executado em ambiente Windows, utilizando a IDE CLion e o sistema de build CMake.

### Pelo CLion

É possível compilar o projeto utilizando o CMake pelo terminal do Windows, a partir da pasta raiz do repositório:

```bash
cmake -S . -B build
cmake --build build --config Release
```

Após a compilação, o executável poderá ser encontrado no diretório de saída gerado pelo CMake. 
A execução pode ser feita pelo terminal:

```powershell
.\build\Release\Biblioteca_EstDados.exe
```

## 6. Funcionalidades

O sistema disponibiliza um menu interativo com as seguintes operações:

1. Cadastrar um livro.
2. Buscar um livro pelo ID.
3. Remover um livro pelo ID.
4. Listar todos os livros em ordem crescente de ID.
5. Inserir um ID na fila.
6. Retirar o próximo ID da fila.
7. Exibir os elementos da fila.
0. Encerrar o programa.

O programa também realiza validações das entradas fornecidas pelo usuário e libera a memória alocada dinamicamente ao encerrar a execução.

## 7. Utilização de inteligência artificial

Ferramentas de inteligência artificial foram utilizadas como apoio durante o processo de desenvolvimento, especificamente para a realização de *code review*, auxiliando na análise do código, identificação de possíveis problemas e revisão da implementação.
A implementação e as decisões de desenvolvimento do projeto foram realizadas pela autora.
