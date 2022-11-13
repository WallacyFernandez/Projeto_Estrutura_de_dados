#include <stdio.h>
#include <stdlib.h>
#include "projetoponto.h"

struct list
{
    char diadomes[100];
    int cpf;
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

        printf("Cpf: %d\n", p->cpf);
    }
}

void imprimepontodefuncionario(int elemento, Listo *l)
{   
    system("cls");
    Listo *p;

    printf("\n----(Pontos do funcionario requerido)----\n\n");
    for (p = l; p != NULL; p = p->proz)
    {
        
        if (p -> cpf == elemento){

        printf("\n(Data do ponto (%s))\n\n", p->diadomes);

        printf("Localizacao: %s\n", p->localizacao);

        printf("Horario de entrada: %s\n", p->horariodeentrada);

        printf("Horario de saida: %s\n", p->horariodesaida);

        printf("Quantidade de horas trabalhadas: %.2f\n", p->quantidadedehoras);

        printf("Pausa: %s\n", p->pausa);

        printf("Cpf: %d\n", p->cpf);
        printf("Cpf: %d\n", p->cpf);
        }
    }
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
