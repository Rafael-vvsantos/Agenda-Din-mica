#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
    int codigo;
    char Nome[50];
    char Telefone[50];
    char Email[50];
    char DataNacimento[50];
    char Obs[50];
    struct Pessoa *proximo;
} Pessoa;

Pessoa *p = NULL, *aux = NULL, *ultimo = NULL;
int volta, escolha;

void menu()
{
    printf(" ___________________\n");
    printf("|                   |\n");
    printf("| AGENDA ELETRONICA |\n");
    printf("|___________________|\n");
    printf("|1 - Cadratratar    |\n");
    printf("|2 - Listar         |\n");
    printf("|3 - Alterar        |\n");
    printf("|0 - Sair           |\n");
    printf("|___________________|\n");
}

void cadrasto()
{
    do
    {
        aux = malloc(sizeof(Pessoa));

        printf("Codigo:\n");
        scanf("%i", &aux->codigo);

        printf("Nome:\n");
        scanf("%s", aux->Nome);

        printf("Telefone:\n");
        scanf("%s", aux->Telefone);

        printf("Email:\n");
        scanf("%s", aux->Email);

        printf("Data de Nascimento:\n");
        scanf("%s", aux->DataNacimento);

        printf("Observação:\n");
        scanf("%s", aux->Obs);

        aux->proximo = NULL;

        if (p == NULL)
        {
            p = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->proximo = aux;
            ultimo = aux;
        }

        printf("Deseja inserir mais contatos ? (1 - Sim / 0 - NAO) :");
        scanf("%i", &volta);

    } while (volta > 0);
}

void listar(Pessoa *aux)
{
    if (vazia())
    {
       printf("Agenda vazia !\nn");
    }else{
    
        while (aux != NULL)
        {
            printf("Codigo: %i\n", aux->codigo);

            printf("Nome: %s\n", aux->Nome);

            printf("Telefone:%s\n", aux->Telefone);

            printf("Email:%s\n", aux->Email);

            printf("Data de Nascimento:%s\n", aux->DataNacimento);

            printf("Observação:%s\n\n", aux->Obs);

            aux = aux->proximo;
        }
    }
}

void alterar(Pessoa *aux)
{
    int codigo;

    if (vazia())
    {
       printf("Agenda vazia !\n\n");
    }else{

        printf("Digite o código do registro a ser alterado: ");
        scanf("%i", &codigo);

        while (aux != NULL)
        {

            if (aux->codigo == codigo)
            {
                printf("Registro encontrado!\n\n");
                printf("Digite o novo código: ");
                scanf("%i", &aux->codigo);
                printf("Digite o novo nome: ");
                scanf("%s", aux->Nome);
                return;
            }
            aux = aux->proximo;
        }
    }
}

int vazia()
{
    if (aux == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main(void)
{
    
    do
    {
        menu();
        printf("Escolha uma opcao :");
        scanf("%d" , &escolha);

        switch (escolha)
        {
        case 1:
            cadrasto();
            break;
        
        case 2:
            listar(p);
            break;
         
        case 3:
            alterar(p);
            break;    
        
        case 0:
            printf("Obrigado por utilizar nossa Agenda !\n");
        
        default:
            printf("Opcao invalida !\n");
            break;
        }
        
    } while (escolha > 0);
    
    system("pause");
}
