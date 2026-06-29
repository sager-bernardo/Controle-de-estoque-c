#include <stdio.h>
#include <string.h>


void adicionar_item(){
    char nome[500];
    int qtd;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);
    printf("Digite a quantidade: ");
    scanf("%d", &qtd);

    FILE *f = fopen("inventory.txt", "a");
    if (!f){
        printf("Erro.\n");
        return;
    }
    fprintf (f, "%s\n%d\n", nome, qtd);
    fclose(f);

    printf("Item adicionado com sucesso!\n");
}

void remover_item(){
    char nomes[100], nomes_arquivo[500][100], linha_nome[100];
    int qtd_remover, quantidades[500], total = 0, linha_qtd;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomes);
    printf("Digite a quantidade a ser removida: ");
    scanf("%d", &qtd_remover);

    FILE *f = fopen("inventory.txt", "r");
    if (!f){
        printf("Erro.\n");
        return;
    }
    while (fscanf (f, " %[^\n] %d", linha_nome, &linha_qtd) == 2){
        strcpy(nomes_arquivo[total], linha_nome);
        quantidades[total] = linha_qtd;
        total++;
    }
    fclose(f);

    int idx = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(nomes_arquivo[i], nomes) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1){
        printf("Item nao encontrado!");
        return;
    }

    if (quantidades[idx] < qtd_remover){
        printf("Estoque insuficiente. Quantidade disponivel: %d", quantidades[idx]);
        return;
    } else if (quantidades[idx] >= qtd_remover){
        quantidades[idx] -= qtd_remover;
        if (quantidades[idx] > 0){
            printf("Quantidade atualizada com sucesso\n");
        } else {
            printf("Item removido do estoque\n");
        }
    }

    f = fopen("inventory.txt", "w");
    if (!f){
        printf("Item nao encontrado.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        if (quantidades[i] > 0) {
            fprintf(f, "%s\n%d\n", nomes_arquivo[i], quantidades[i]);
        }
    }
    fclose(f);
}

void listar_estoque(){
    char linha_nome[100];
    int linha_qtd, encontrou = 0;

    printf("====================\n");
    printf("   Estoque atual\n");
    printf("====================\n");

    FILE *f = fopen("inventory.txt", "r");
    if (!f){
        printf("O estoque está vazio.\n");
        return;
    }
    while (fscanf(f, " %[^\n] %d", linha_nome, &linha_qtd) == 2) {
        printf("Nome: %s\nQuantidade: %d\n\n", linha_nome, linha_qtd);
        encontrou = 1;
    }
    fclose(f);

    if (!encontrou) {
        printf("O estoque está vazio.\n");
    }
}

int main(){
    int option;
    char continuar;

    do {
        printf("====================\n");
        printf("Controle de Estoque\n");
        printf("====================\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opcao: ");

        while (scanf("%d", &option) != 1 || option < 1 || option > 4) {
            while (getchar() != '\n');
            printf("Opcao invalida! Tente novamente.\nOpcao: ");
        }

        switch (option) {
            case 1: adicionar_item(); break;
            case 2: remover_item();   break;
            case 3: listar_estoque(); break;
            case 4:
                printf("Obrigado por usar o Controle de Estoques! Ate a proxima.\n");
                return 0;
        }

        printf("Deseja realizar outra operacao? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por usar o Controle de Estoques! Ate a proxima.\n");
    return 0;
}
