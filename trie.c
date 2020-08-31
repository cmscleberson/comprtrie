#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM 70



typedef struct No
{

    struct No* filho[TAM];
    struct No* interno[TAM];

	int ehFinal;


} No;


No* criaNo()
{
    No* no = (No*) malloc (sizeof(No));

    int i;
    for(i=0; i<TAM; i++)
    {
        no->filho[i] = NULL;
    }

    return no;

}


void insereNoInterno(No* raiz, char* valor, int ini, int fim)
{
    No* atual = raiz;

    int index = valor[ini]-'a';
    atual->interno[index] = criaNo();
    *atual->interno = atual->interno[index];
    printf("\nNoh interno adicionado:::%d", index);
}




void insereNoFilho(No* raiz, char *valor)
{
    int tam =0;
    char *valorCont = valor;

    while(*valorCont)
    {
        tam++;
        valorCont++;
    }

    char *valorTemp = valor;
    char *valorNoInterno = valor;


    int cont=0;
    int index;

    No* atual = raiz;
    No* temp=NULL;
    printf("\n\nTamanho::%d\n", tam);

    while(*valorTemp)
    {

        index = *valorTemp-'a';

        if(atual->filho[index] != NULL)
        {

            temp = atual;
            cont++;

            printf("\n:::: Letra jah inserida:::\n%d", index);
        }
        else
        {
            atual->filho[index] = criaNo();
            cont++;
            break;

        }
        atual = atual->filho[index];

        valorTemp++;

    }

    if(cont != tam )
    {
        //verificar se tem nós internos
        if(temp != NULL)
        {
            //verificar se tem nós internos
            printf("\nNó temporário:::%d", index);
        }
        else
        {
            //insere o noh filho e os nós internos
            int j;
            for(j=cont; j<tam; j++)
            {
                insereNoInterno(atual, valorNoInterno, j, tam);
            }
        }
    }
}

