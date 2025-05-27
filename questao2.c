#include <stdio.h>
#include <string.h>

#define MAX 40

typedef struct {
    int codigo;
    char descricao[100];
    float valor;
    int estoque;
} Produto;

Produto produtos[MAX];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos < MAX) {
        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[totalProdutos].codigo);
        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]s", produtos[totalProdutos].descricao);
        printf("Digite o valor unitario: ");
        scanf("%f", &produtos[totalProdutos].valor);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtos[totalProdutos].estoque);
        totalProdutos++;
    } else {
        printf("Estoque de produtos cheio!\n");
    }
}

void alterarValorUnitario(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Digite o novo valor unitario: ");
            scanf("%f", &produtos[i].valor);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

float obterValorUnitario(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].valor;
        }
    }
    printf("Produto nao encontrado.\n");
    return -1;
}

int obterQuantidadeEstoque(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].estoque;
        }
    }
    printf("Produto nao encontrado.\n");
    return -1;
}

void realizarVenda(int codigo, int quantidade) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            if (produtos[i].estoque == 0) {
                printf("Estoque zerado. Produto nao pode ser vendido.\n");
            } else if (quantidade <= produtos[i].estoque) {
                char confirmar;
                printf("Deseja efetuar a compra? (S/N): ");
                scanf(" %c", &confirmar);
                if (confirmar == 'S' || confirmar == 's') {
                    produtos[i].estoque -= quantidade;
                    printf("Total a pagar: %.2f\n", produtos[i].valor * quantidade);
                    if (produtos[i].estoque == 0) {
                        printf("Produto com estoque zerado.\n");
                    }
                }
            } else {
                printf("Quantidade em estoque insuficiente.\n");
            }
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void atualizarEstoque(int codigo, int quantidade) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            produtos[i].estoque = quantidade;
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void exibirProdutos() {
    for (int i = 0; i < totalProdutos; i++) {
        printf("Codigo: %d, Descricao: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

void exibirProdutosEstoqueZero() {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].estoque == 0) {
            printf("Codigo: %d, Descricao: %s\n", produtos[i].codigo, produtos[i].descricao);
        }
    }
}

int main() {
    int opcao, codigo, quantidade;

    while (1) {
        printf("\n1. Cadastrar Produto\n2. Alterar Valor Unitario\n3. Obter Valor Unitario\n4. Obter Quantidade em Estoque\n5. Realizar Venda\n6. Atualizar Estoque\n7. Exibir Produtos\n8. Exibir Produtos com Estoque Zero\n9. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                alterarValorUnitario(codigo);
                break;
            case 3:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Valor unitario: %.2f\n", obterValorUnitario(codigo));
                break;
            case 4:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Quantidade em estoque: %d\n", obterQuantidadeEstoque(codigo));
                break;
            case 5:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                realizarVenda(codigo, quantidade);
                break;
            case 6:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a nova quantidade em estoque: ");
                scanf("%d", &quantidade);
                atualizarEstoque(codigo, quantidade);
                break;
            case 7:
                exibirProdutos();
                break;
            case 8:
                exibirProdutosEstoqueZero();
                break;
            case 9:
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
