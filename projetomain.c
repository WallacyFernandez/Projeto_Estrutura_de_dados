#include <stdio.h>
#include <stdlib.h>
#include "projetofuncionario.c"
#include "projetoponto.c"

#define titulo_opcao1 "Cadrastrar ponto"
#define titulo_opcao1 "Excluir ponto"
#define titulo_opcao1 "Listar pontos marcados de um dado funcionario"
#define titulo_opcao1 "Buscar funcionario"


int main(void)
{
 

    int escolha, cpf, verificacpf;
    Lista *lista = lst_cria(); /*Cria uma lista*/
    Listo *listo = lst_cria2(); /*Cria uma lista*/
    

    do
    {
        printf("\n");
        printf("1 - Cadrastrar ponto\n");
        printf("2 - (Imprimindo teste da primeira funcao)Excluir ponto\n");
        printf("3 - Listar pontos marcados de um dado funcionario\n");
        printf("4 - Buscar funcionario\n");
        printf("5 - Editar cadratro de ponto\n");
        printf("6 - Consultar pontos de um dado dia\n");
        printf("7 - Sair\n");
        printf("Digite a opcao: \n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            system("cls");
            printf("Cadrastar novo funcionario (1)\n");
            printf("Cadrastar ponto de funcionario existente (2)\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            if (escolha == 1){

            lista = lst_insere(lista); /*Insere o elemento na lista*/

            }
            else if (escolha == 2){
            
            printf("Digite o cpf do funcionario: \n");
            scanf("%d", &cpf);

            verificacpf = lst_busca(cpf, lista);

            if(verificacpf == cpf){
             

             
             

             listo = lst_insere2(listo);

            }
            else{
             
             printf("Funcionario nao existe\n");

            }
            }
            break;
        case 2:
           
            printf("imprimir dados dos funcionarios(1)\n");
            printf("imprimir os pontos dos funcionarios(2)\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            if (escolha == 1){

            lst_imprime(lista);

            }
            else if (escolha == 2){
                
            lst_imprime2(listo);

            }
            break;
        case 3:

            break;
        case 7:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (escolha != 7);

lst_libera(lista);
lst_libera2(listo);

    return 0;
}