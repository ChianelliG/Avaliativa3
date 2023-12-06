#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct {
    char codigo[20];
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    Produto produtos[TAM];
    int quantidadeProdutos;
} Estoque;

void inicializarEstoque(Estoque *estoque) {
    estoque->quantidadeProdutos = 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarProduto(Estoque *estoque) {
    if (estoque->quantidadeProdutos < TAM) {
        Produto *produto = &estoque->produtos[estoque->quantidadeProdutos];

        printf("Digite o codigo do produto: ");
        scanf("%s", produto->codigo);
        limparBuffer();
        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]s", produto->descricao);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produto->quantidade);
        printf("Digite o valor do produto: ");
        scanf("%f", &produto->valor);

        estoque->quantidadeProdutos++;
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Limite maximo de produtos atingido.\n");
    }
}

void gerarRelatorio(Estoque *estoque) {
    printf("\nRelatorio de Produtos:\n");
    for (int i = 0; i < estoque->quantidadeProdutos; i++) {
        printf("Codigo: %s\n", estoque->produtos[i].codigo);
        printf("Descricao: %s\n", estoque->produtos[i].descricao);
        printf("Quantidade: %d\n", estoque->produtos[i].quantidade);
        printf("Valor: %.2f\n", estoque->produtos[i].valor);
        printf("--------------------------\n");
    }
}

void pesquisarProduto(Estoque *estoque) {
    char codigoPesquisa[20];
    printf("Digite o codigo do produto que deseja pesquisar: ");
    scanf("%s", codigoPesquisa);
    limparBuffer();

    for (int i = 0; i < estoque->quantidadeProdutos; i++) {
        if (strcmp(estoque->produtos[i].codigo, codigoPesquisa) == 0) {
            printf("Produto encontrado:\n");
            printf("Codigo: %s\n", estoque->produtos[i].codigo);
            printf("Descricao: %s\n", estoque->produtos[i].descricao);
            printf("Quantidade: %d\n", estoque->produtos[i].quantidade);
            printf("Valor: %.2f\n", estoque->produtos[i].valor);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void removerProduto(Estoque *estoque) {
    char codigoRemover[20];
    printf("Digite o codigo do produto que deseja remover: ");
    scanf("%s", codigoRemover);
    limparBuffer();

    for (int i = 0; i < estoque->quantidadeProdutos; i++) {
        if (strcmp(estoque->produtos[i].codigo, codigoRemover) == 0) {
            estoque->produtos[i] = estoque->produtos[estoque->quantidadeProdutos - 1];
            estoque->quantidadeProdutos--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

int main() {
    Estoque estoque;
    inicializarEstoque(&estoque);

    int escolher;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Gerar Relatorio de Produtos\n");
        printf("3. Pesquisar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &escolher);
        limparBuffer();

        switch (escolher) {
            case 1:
                cadastrarProduto(&estoque);
                break;
            case 2:
                gerarRelatorio(&estoque);
                break;
            case 3:
                pesquisarProduto(&estoque);
                break;
            case 4:
                removerProduto(&estoque);
                break;
            case 0:
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (escolher != 0);

    return 0;
}
