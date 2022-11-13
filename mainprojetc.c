#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "projetofuncionario.c"
#include "projetoponto.c"

#define TITULO_OPCAO1 "Cadrastrar ponto"
#define TITULO_OPCAO2 "(Teste de imprimindo) Excluir ponto"
#define TITULO_OPCAO3 "Listar pontos marcados de um dado funcionario"
#define TITULO_OPCAO4 "Buscar funcionario"
#define TITULO_OPCAO5 "Editar cadratro de ponto"
#define TITULO_OPCAO6 "Consultar pontos de um dado dia"
#define TITULO_OPCAO7 "Sair"

#define N_OPCOES 7
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'

/****
 * Função: LimpaBuffer()
 * Descrição: Lê e descarta caracteres encontrados na entrada
 * Parâmetros: Nenhum
 * Retorno: Nada
 ****/
void LimpaBuffer(void)
{
    int valorLido; /* valorLido deve ser int! */
    do
    {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/****
 * Função: LeOpcao()
 * Descrição: Lê e valida a opção digitada pelo usuário
 * Parâmetros:
 *   menorValor (entrada): o menor valor válido
 *   maiorValor (entrada): o maior valor válido
 * Retorno: A opção lida é validada
 ****/
int LeOpcao()
{
    int retorno, retorno2, n1, letra;

        retorno = 0;
        while (retorno != 1)
        {

          printf("\nDigite sua opcao: ");
          retorno2 = scanf("%d", &n1);

          if (n1 >= 1 && n1 <= 7)
          {

            retorno = retorno2;
          }

          if (retorno == 0)
          {
            printf("\n---(Valor inserido invalido)---\n\n");
          }

          letra = 0;
          while (letra != '\n')
          {

            letra = getchar();
          }

          
          printf("\n");
        }
      
    return n1;
}
/****
 * Função: LeInteiro()
 * Descrição: Lê um número inteiro introduzido pelo usuário
 * Parâmetros: Nenhum
 * Retorno: O inteiro lido
 ****/

/****
 * Função: ApresentaMenu
 * Descrição: Apresenta menu com número indeterminado de opções
 * Parâmetros:
 *   nItens (entrada): número de itens no menu
 *   menorOpcao (entrada): caractere associado ao item I
 * Retorno: Nada
 ****/
void ApresentaMenu(int nItens, int menorOpcao, ...)
{
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menorOpcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for (i = 0; i < nItens; ++i)
    {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos); /* Encerra processamento de argumentos */
}

int main(void)
{

    int escolha, cpf1, verificacpf;
    int retorno, retorno2, n1, letra;
    Lista *lista = lst_cria();  /*Cria uma lista*/
    Listo *listo = lst_cria2(); /*Cria uma lista*/
    unsigned char op;
    unsigned int saida = 0;

    do
    {
        printf("\n");
        printf("\n");
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7);
         
        
        op = LeOpcao();

        switch (op)
        {

        case 1:

            system("cls");
            printf("Cadrastar novo funcionario (1)\n");
            printf("Cadrastar ponto(2)\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            if (escolha == 1)
            {

                lista = lst_insere(lista); /*Insere o elemento na lista*/
            }
            else if (escolha == 2)
            {

                printf("Digite o cpf do funcionario: \n");
                scanf("%d", &cpf1);

                verificacpf = lst_busca(cpf1, lista);

                if (verificacpf == cpf1)
                {

                    listo = lst_insere2(listo);

                    listo -> cpf = cpf1;
                   
                }
                else
                {

                    printf("Funcionario nao existe\n");
                }
            }

            break;

        case 2:
            
            printf("imprimir dados dos funcionarios(1)\n");
            printf("imprimir os pontos dos funcionarios(2)\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            if (escolha == 1)
            {

                lst_imprime(lista);
            }
            else if (escolha == 2)
            {

                lst_imprime2(listo);
            }

            break;

        case 3:
         
                printf("Digite o cpf do funcionario: \n");
                scanf("%d", &cpf1);

                verificacpf = lst_busca(cpf1, lista);

                if (verificacpf == cpf1)
                {

                 imprimepontodefuncionario(cpf1, listo);
                   
                }
                else
                {

                    printf("Funcionario nao existe\n");
                }

            break;

        case 4:
           

            break;

        case 5:
           

            break;

        case 6:
            

            break;

        case 7:
           
            saida = 1;
            printf("Obrigado por usar este programa.");
            break;

        default:
            printf("Este programa possui um bug.");
            return 1;
        }
    } while (!saida);

    lst_libera(lista);
    lst_libera2(listo);
    return 0;
}