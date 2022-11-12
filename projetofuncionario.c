/* 
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

 Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
 */

#include <stdio.h>
#include <stdlib.h>
#include "projetofuncionario.h"

struct lista{

	char nome[100];
    int cpf;
    char cargo[100];
    char setor[100];
    float salario;
    char datadecontratacao[100];
    char jornadadetrabalho[100];

	struct lista*prox;
};


Lista* lst_cria(void){
	return NULL;
}


Lista* lst_insere(Lista* l){
    system("cls");
	Lista* novo = (Lista*) malloc(sizeof(Lista));
    int escolha;

    
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", novo->nome);
    printf("Digite o cpf do funcionario sem pontuacao: ");
    scanf("%d", &novo->cpf);
    printf("Digite o setor do funcionario: ");
    scanf(" %[^\n]", novo->setor);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &novo->salario);
    printf("Digite a data de contratação do funcionario: ");
    scanf(" %[^\n]", novo->datadecontratacao);
    printf("Digite a jornada de trabalho mensal do funcionario: ");
    scanf(" %[^\n]", novo->jornadadetrabalho);
    
    
	novo->prox = l;
	return novo;
}



int lst_vazia(Lista *l){
	return (l==NULL);
}

void lst_imprime(Lista*l){
    system("cls");

	Lista*p;

	for(p=l; p!=NULL; p=p->prox){

    printf("\n----(dados dos funcionarios)----\n\n");

	printf("Nome do funcionario: %s\n", p->nome);
    
    printf("O cpf do funcionario: %d\n", p -> cpf);
    
    printf("Setor do funcionario: %s\n", p -> setor);
    
    printf("Salario do funcionario: %.2f\n", p -> salario);
   
    printf("Data de contratacao do funcionario: %s\n", p->datadecontratacao);
    
    printf("Jornada de trabalho mensal do funcionario: %s\n", p->jornadadetrabalho);
    

	}

}



/*
Lista * lst_busca(int elemento, Lista* l){
	Lista * p;
	for(p=l; p!=NULL; p=p->prox){
		if(p->info ==elemento)
			return p;
	}

	return NULL;

}
*/

/*
Lista * lst_retira(Lista*l, int v){
    Lista* ant = NULL; /* ponteiro para elemento anterior 
    Lista* p = l; /* ponteiro para percorrer a lista
    /* procura elemento na lista, guardando anterior 
    while(p->info!=v){
    	if (p==NULL)
        	return l; /* n�o achou: retorna lista original 
        ant = p;
        p = p->prox;
            /* verifica se achou elemento 

    }
    /* retira elemento 
    if (ant==NULL)
    /* retira elemento do inicio 
        l = p->prox;
    else
    /* retira elemento do meio da lista 
        ant->prox = p->prox;
    free(p);
    return l;
}
*/

void lst_libera(Lista* l){
    Lista* p = l;
    Lista* t;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;

    }
}



/*
Lista* lst_insere_ordenada(Lista * l, int v){
	Lista * novo;
	Lista * ant = NULL;
	Lista * p =l;
	while(p!=NULL && p->info<v){
		ant = p;
		p = p->prox;

	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	if(ant ==NULL){
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return l;
}
*/


