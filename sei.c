#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

int main(){

    char nome[100];
    long long int cpf;
    char cargo[100];
    char setor[100];
    float salario;
    char datadecontratacao[100];
    char jornadadetrabalho[100];
    int inicializador;

FILE *banco;

    banco = fopen("banco.txt", "r");

    fscanf(banco, "%d", &inicializador);

    if (banco == NULL)
    {
        printf("Não encontrado\n");
    }
    else
    {
    
     for (int i = 0; i < inicializador; i++)
     {
        fscanf(banco, " %[^\n] %[^\n] %lld %f %[^\n] %[^\n]", nome, setor, &cpf, &salario, datadecontratacao, jornadadetrabalho);
        printf("Aqui tem %s\n", nome);
        printf("Aqui tem %s\n", setor);
        printf("Aqui tem %lld\n", cpf);
        printf("Aqui tem %.2f\n", salario);
        printf("Aqui tem %s\n", datadecontratacao);
         printf("Aqui tem %s\n", jornadadetrabalho);
     }
     
        
     }
        
    
          
        
        fclose(banco);



    
}