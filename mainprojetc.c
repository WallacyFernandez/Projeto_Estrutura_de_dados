#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "projetofuncionario.c"
#include "projetoponto.c"

#define TITULO_OPCAO1 "Cadrastrar ponto"
#define TITULO_OPCAO2 "Excluir ponto"
#define TITULO_OPCAO3 "Listar pontos marcados de um dado funcionario"
#define TITULO_OPCAO4 "Buscar funcionario"
#define TITULO_OPCAO5 "Editar cadratro de ponto"
#define TITULO_OPCAO6 "Consultar pontos de um dado dia"
#define TITULO_OPCAO7 "Imprimir dados de todos os funcionarios"
#define TITULO_OPCAO8 "imprimir todos os pontos dos funcionarios"
#define TITULO_OPCAO9 "Sair"

#define N_OPCOES 9
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'
#define OPCAO9 '9'

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

        if (n1 >= 1 && n1 <= 9)
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
int LeOpcao2()
{
    int retorno, retorno2, n1, letra;

    retorno = 0;
    while (retorno != 1)
    {

        printf("\nDigite sua opcao: ");
        retorno2 = scanf("%d", &n1);

        if (n1 >= 1 && n1 <= 2)
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
    char data[100];
    int escolha;
    int verificacpf, inicializador = 0;
    long long int cpf1;
    int retorno, retorno2, n1, letra;
    Lista *lista = lst_cria(); /*Cria uma lista*/
    
    lista = lst_lertxt(lista);


    Listo *listo = lst_cria2(); /*Cria uma lista*/
    unsigned char op;
    unsigned int saida = 0;

    do
    {
        printf("\n");
        printf("\n");
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8, TITULO_OPCAO9);

        op = LeOpcao();

        switch (op)
        {

        case 1:

            system("cls");
            printf("Cadrastar novo funcionario (1)\n");
            printf("Cadrastar ponto(2)\n");
            escolha = LeOpcao2();

            if (escolha == 1)
            {
                Lista *p;
                FILE *arq;

                arq = fopen("banco.txt", "r");

                fscanf(arq, "%d", &inicializador);

                fclose(arq);

                inicializador++;
                lista = lst_insere(lista); /*Insere o elemento na lista*/
            }
            else if (escolha == 2)
            {

                printf("Digite o cpf do funcionario: \n");
                scanf("%lld", &cpf1);

                verificacpf = lst_busca(cpf1, lista);

                if (verificacpf == 1)
                {

                    listo = lst_insere2(listo);

                    listo->cpf = cpf1;
                }
                else
                {

                    printf("\nFuncionario nao existe\n");
                }
            }
            else
            {
            }

            break;

        case 2:

            printf("Digite o cpf do funcionario: \n");
            scanf("%lld", &cpf1);

            verificacpf = lst_busca(cpf1, lista);

            if (verificacpf == 1)
            {
                printf("Deseja excluir pontos registrados por este funcionario? \n(1) sim \n(2) nao: \n");
                escolha = LeOpcao2();

                if (escolha == 1)
                {

                    listo = lst_retira(listo, cpf1);
                }
                else
                {

                    printf("\nVoltando ao inicio.\n");
                }
            }
            else
            {

                printf("\nFuncionario nao existe\n");
            }

            break;

        case 3:

            printf("Digite o cpf do funcionario: \n");
            scanf("%lld", &cpf1);

            verificacpf = lst_busca(cpf1, lista);

            if (verificacpf == 1)
            {

                imprimepontodefuncionario(cpf1, listo);
            }
            else
            {

                printf("\nFuncionario nao existe\n");
            }

            break;

        case 4:

            printf("Digite o cpf do funcionario: \n");
            scanf("%lld", &cpf1);

            verificacpf = lst_busca(cpf1, lista);

            if (verificacpf == 1)
            {

                imprimefuncionario(cpf1, lista);
            }
            else
            {

                printf("\nFuncionario nao existe\n");
            }

            break;

        case 5:

            listo = lst_editaponto(listo);

            break;

        case 6:

            lst_buscadata(listo);

            break;

        case 7:

            lst_imprime(lista);

            break;

        case 8:

            lst_imprime2(listo);

            break;

        case 9:

            system("cls");

            Lista *p;
            FILE *arquivo;
            arquivo = fopen("banco.txt", "w");
            fprintf(arquivo, "%d ", inicializador);
            for (p = lista; p != NULL; p = p->prox)
            {

             fprintf(arquivo, " %s\n %s\n %lld %.2f %s\n %s\n", p-> nome, p -> setor, p -> cpf, p -> salario, p -> datadecontratacao, p -> jornadadetrabalho);
            }

            fclose(arquivo);

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