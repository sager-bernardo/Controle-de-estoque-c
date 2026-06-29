#include <stdio.h>

int adicionarItem();
int removerItem();
int listarEstoque();

int main(){
    double option, x, y, result;
    char operator, new = 'y';
    printf("====================\n");
    printf("Controle de Estoque \n");
    printf("====================\n");

    do {
        printf("Selecione uma opcao: \n 1. Adicionar Item\n 2. Remover Item\n 3. Listar Estoque\n 4. Sair\n Option: ");
        scanf("%lf", &option);

        if (option == 1){
            adicionarItem();    
        } else if (option == 2){
            removerItem();
        } else if (option == 3){
            listarEstoque();
        } else if (option == 4){
            printf("Obrigado por usar o Controle de Estoques! Ate a próxima.");
            break;
        } else {
            printf("Opção Inválida");
        }
    } while (option != 1 && option != 2 && option != 3 && option != 4);

return 0;
}
