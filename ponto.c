#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

struct list
{
    char diadomes[100];
    long long int cpf;
    char localizacao[100];
    char horariodeentrada[100];
    char horariodesaida[100];
    float quantidadedehoras;
    char pausa[100];

    struct list *proz;
};

Listo *lst_cria2(void)
{
    return NULL;
}

Listo *lst_insere2(Listo *l)
{

    Listo *novo = (Listo *)malloc(sizeof(Listo));
    int escolha;

    printf("\n----(Dados do ponto)----\n\n");

    printf("Digite o data exemplo (12/03/2022): ");
    scanf(" %[^\n]", novo->diadomes);

    printf("Digite a localizacao: ");
    scanf(" %[^\n]", novo->localizacao);

    printf("Digite o horario de entrada (12:30): ");
    scanf(" %[^\n]", &novo->horariodeentrada);

    printf("Digite o horario de saida (17:30): ");
    scanf(" %[^\n]", novo->horariodesaida);

    printf("Pausa exemplo (14:00) a (14:30): ");
    scanf(" %[^\n]", novo->pausa);

    printf("Digite o total de horas trabalhadas: ");
    scanf("%f", &novo->quantidadedehoras);

    novo->proz = l;

    system("cls");
    return novo;
}

int lst_vazia2(Listo *l)
{
    return (l == NULL);
}

void lst_imprime2(Listo *l)
{

    Listo *p;

    for (p = l; p != NULL; p = p->proz)
    {

        printf("\n----(Dados do ponto)----\n\n");

        printf("Localizacao: %s\n", p->localizacao);

        printf("Horario de entrada: %s\n", p->horariodeentrada);

        printf("Horario de saida: %s\n", p->horariodesaida);

        printf("Quantidade de horas trabalhadas: %.2f\n", p->quantidadedehoras);

        printf("Pausa: %s\n", p->pausa);
        if (p->cpf < 1000000000)
        {
            printf("Cpf: 0%lld\n", p->cpf);
        }
        else
        {
            printf("Cpf: %lld\n", p->cpf);
        }
    }
}

void imprimepontodefuncionario(long long int elemento, Listo *l)
{
    system("cls");
    Listo *p;

    printf("\n----(Pontos do funcionario requerido)----\n\n");
    for (p = l; p != NULL; p = p->proz)
    {

        if (p->cpf == elemento)
        {

            printf("\n(Ponto cadratrado no dia (%s))\n\n", p->diadomes);

            printf("Localizacao: %s\n", p->localizacao);

            printf("Horario de entrada: %s\n", p->horariodeentrada);

            printf("Horario de saida: %s\n", p->horariodesaida);

            printf("Quantidade de horas trabalhadas: %.2f\n", p->quantidadedehoras);

            printf("Pausa: %s\n", p->pausa);
        }
    }
}

void lst_buscadata(Listo *l)
{
    Listo *p;
    char data[100];
    char datastruct[100];
    int result = 1;

    printf("A data do dia requerido exemplo 12/11/2022: \n");
    scanf(" %[^\n]", data);

    for (p = l; p != NULL; p = p->proz)
    {
        strcpy(datastruct, p->diadomes);
        result = strcmp(data, datastruct);
        if (result == 0)
        {

            if (p->cpf < 1000000000)
            {
                printf("\n(Ponto cadratrado no cpf (0%lld) no dia %s)\n\n", p->cpf, p->diadomes);
            }
            else
            {
                printf("\n(Ponto cadratrado no cpf (%lld) no dia %s)\n\n", p->cpf, p->diadomes);
            }

            printf("Localizacao: %s\n", p->localizacao);

            printf("Horario de entrada: %s\n", p->horariodeentrada);

            printf("Horario de saida: %s\n", p->horariodesaida);

            printf("Quantidade de horas trabalhadas: %.2f\n", p->quantidadedehoras);

            printf("Pausa: %s\n", p->pausa);
        }
    }

    if (result == 1){

        printf("\nNenhum ponto cadastrado nesta data.\n");
    }

}

Listo *lst_editaponto(Listo *l)
{
    Listo *p;
    Listo *novo = (Listo *)malloc(sizeof(Listo));
    char data[100];
    char datastruct[100];
    int result = 1;

    printf("A data do dia requerido exemplo 12/11/2022: \n");
    scanf(" %[^\n]", data);

    for (p = l; p != NULL; p = p->proz)
    {
        strcpy(datastruct, p->diadomes);
        result = strcmp(data, datastruct);
        if (result == 0)
        {

            printf("\n----(Dados do ponto)----\n\n");

            printf("Digite o data exemplo (12/03/2022): ");
            scanf(" %[^\n]", p -> diadomes);

            printf("Digite a localizacao: ");
            scanf(" %[^\n]", p -> localizacao);

            printf("Digite o horario de entrada (12:30): ");
            scanf(" %[^\n]", & p -> horariodeentrada);

            printf("Digite o horario de saida (17:30): ");
            scanf(" %[^\n]", p -> horariodesaida);

            printf("Pausa exemplo (14:00) a (14:30): ");
            scanf(" %[^\n]", p -> pausa);

            printf("Digite o total de horas trabalhadas: ");
            scanf("%f", & p -> quantidadedehoras);

           
        }
    }
    if (result == 1){

        printf("\nNenhum ponto cadastrado nesta data.\n");
    }

    return l;
}

Listo *lst_retira(Listo *l, long long int elemento)
{
    Listo *ant = NULL; // ponteiro para elemento anterior
    Listo *p = l;      // ponteiro para percorrer a lista

    // procura elemento na lista, guardando anterior

    while (p->cpf != elemento)
    {
        if (p == NULL)
            return l; // n�o achou: retorna lista original
        ant = p;
        p = p->proz;
        // verifica se achou elemento
    }
    // retira elemento
    if (ant == NULL)
        // retira elemento do inicio
        l = p->proz;
    else
        // retira elemento do meio da lista
        ant->proz = p->proz;
    free(p);

    return l;
}

void lst_libera2(Listo *l)
{
    Listo *p = l;
    Listo *t;
    while (p != NULL)
    {
        t = p->proz;
        free(p);
        p = t;
    }
}
