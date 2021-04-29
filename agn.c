#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    int codigo;
    char Nome[50];
    char Telefone[50];
    char Email[50];
    char DataNacimento[50];
    char Obs[50];
    struct Pessoa *proximo;
} Pessoa;

void listar(Pessoa *aux)
{
    while (aux != NULL)
    {
        printf("Codigo: %i\n" , aux->codigo);

        printf("Nome: %s\n" , aux->Nome);


        printf("Telefone:%s\n", aux->Telefone);


        printf("Email:%s\n", aux->Email);


        printf("Data de Nascimento:%s\n" , aux->DataNacimento);


        printf("Observação:%s\n" ,aux->Obs);

        aux = aux->proximo;

    }
    
}

main()
{
    Pessoa *p = NULL , *aux, *ultimo;
    int volta;

    do
    {
        aux = malloc(sizeof(Pessoa));

        printf("Codigo:\n");
        scanf("%i" , &aux -> codigo);

        printf("Nome:\n");
        scanf("%s" , aux ->Nome);

        printf("Telefone:\n");
        scanf("%s" , aux ->Telefone);

        printf("Email:\n");
        scanf("%s" , aux ->Email);

        printf("Data de Nascimento:\n");
        scanf("%s" , aux ->DataNacimento);

        printf("Observação:\n");
        scanf("%s" , aux ->Obs);

        aux->proximo = NULL;

        if (p == NULL)
        {
            p = aux;
            ultimo = aux;
        }
        else
        {
            ultimo ->proximo = aux;
            ultimo = aux;
        }
        
        printf("Deseja inserir mais contatos : ");
        scanf("%i" , &volta);

    } while (volta > 0);

    printf("--------\n");

    listar(p);

    
}
