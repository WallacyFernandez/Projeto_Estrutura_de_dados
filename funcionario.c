/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

 Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

struct lista
{

    char nome[100];
    long long int cpf;
    char cargo[100];
    char setor[100];
    float salario;
    char datadecontratacao[100];
    char jornadadetrabalho[100];

    struct lista *prox;
};

Lista *lst_cria(void)
{
    return NULL;
}

Lista *lst_insere(Lista *l)
{
    system("cls");
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    printf("\n----(Inserindo dados de funcionario)----\n\n");

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", novo->nome);

    printf("Digite o cpf do funcionario sem pontuacao: ");
    scanf("%lld", &novo->cpf);

    printf("Digite o setor do funcionario: ");
    scanf(" %[^\n]", novo->setor);

    printf("Digite a data de contratacao do funcionario: ");
    scanf(" %[^\n]", novo->datadecontratacao);

    printf("Digite a jornada de trabalho mensal do funcionario: ");
    scanf(" %[^\n]", novo->jornadadetrabalho);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &novo->salario);

    system("cls");
    novo->prox = l;
    return novo;
}

int lst_vazia(Lista *l)
{
    return (l == NULL);
}

void lst_imprime(Lista *l)
{
    system("cls");

    Lista *p;

    for (p = l; p != NULL; p = p->prox)
    {

        printf("\n----(Dados dos funcionarios)----\n\n");

        printf("Nome do funcionario: %s\n", p->nome);

        printf("O cpf do funcionario: %lld\n", p->cpf);

        printf("Setor do funcionario: %s\n", p->setor);

        printf("Salario do funcionario: %.2f\n", p->salario);

        printf("Data de contratacao do funcionario: %s\n", p->datadecontratacao);

        printf("Jornada de trabalho mensal do funcionario: %s\n", p->jornadadetrabalho);
    }
}

void lst_imprimetxt(Lista *l)
{
    system("cls");

    Lista *p;
    FILE *arquivo;
    arquivo = fopen("banco.txt", "w");
    for (p = l; p != NULL; p = p->prox)
    {

        fprintf(arquivo, " %s\n %lld\n %s\n %.2f\n %s\n %s", p->nome, p->cpf, p->setor, p->salario, p->datadecontratacao, p->jornadadetrabalho);
    }

    fclose(arquivo);
}

Lista *lst_lertxt(Lista *l)
{
    int inicializador;

    char nome[100];
    long long int cpf;
    char cargo[100];
    char setor[100];
    float salario;
    char datadecontratacao[100];
    char jornadadetrabalho[100];

    FILE *banco;

    banco = fopen("banco.txt", "r");

    fscanf(banco, "%d", &inicializador);

    if (banco == NULL)
    {
        printf("Banco de dados Vazio.\n");
    }
    else
    {

        for (int i = 0; i < inicializador; i++)
        {
            Lista *novo = (Lista *)malloc(sizeof(Lista));
            fscanf(banco, " %[^\n] %[^\n] %lld %f %[^\n] %[^\n]", nome, setor, &cpf, &salario, datadecontratacao, jornadadetrabalho);
            strcpy(novo->nome, nome);
            strcpy(novo->setor, setor);
            strcpy(novo->datadecontratacao, datadecontratacao);
            strcpy(novo->jornadadetrabalho, jornadadetrabalho);
            novo->cpf = cpf;
            novo->salario = salario;
            novo->prox = l;
            l = novo;
        }
    }

    fclose(banco);

    return l;
}

void imprimefuncionario(long long int elemento, Lista *l)
{
    system("cls");
    Lista *p;

    printf("\n----(Dados do funcionario)----\n\n");
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->cpf == elemento)
        {

            printf("Nome do funcionario: %s\n", p->nome);

            if (p->cpf < 1000000000)
            {
                printf("O cpf do funcionario: 0%lld\n", p->cpf);
            }
            else
            {
                printf("O cpf do funcionario: %lld\n", p->cpf);
            }

            printf("Setor do funcionario: %s\n", p->setor);

            printf("Salario do funcionario: %.2f\n", p->salario);

            printf("Data de contratacao do funcionario: %s\n", p->datadecontratacao);

            printf("Jornada de trabalho mensal do funcionario: %s\n", p->jornadadetrabalho);
        }
    }
}

int lst_busca(long long int elemento, Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->cpf == elemento)
            return 1;
    }

    return NULL;
}



void lst_libera(Lista *l)
{
    Lista *p = l;
    Lista *t;
    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
}
