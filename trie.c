

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM 70



typedef struct No
{

    char *valor[TAM];
    struct No* filho[TAM];
	int indComp;
	int ehFinal;


} No;


No* criaNo()
{

    No* novo = (No*) malloc(sizeof(No));
    novo ->ehFinal = 1;
	novo->indComp =0;

    int i;
    for(i=0; i<TAM; i++)
    {
        novo->filho[i] = NULL;
        novo->valor[i] = NULL;
    }

    return novo;

}

void inserirNo(No* raiz, char *val[],  int tamP)
{

    No* atual = raiz;

	int j;
	int indParada = 0;


	for(j=0; j<tamP; j++)
	{
	    printf("\nValor que estah na raiz: %s", *atual->valor);

	    if(*atual->valor == NULL)
        {
            No* novo = criaNo();
            atual->filho[*val[0]-'A'] = novo;
			*atual->valor = *val;
			printf("\nInsserindo :::%s", val[0]);
			break;

        }
        else
        {
            printf("\nValor que esta na posicao J do No%d", atual->valor[0][j]-'A');
            int valorNo = atual->valor[0][j]-'A';
            int indexPalavra = val[0][j]-'A';
            printf("\nLetra procurada :::%d", indexPalavra);


            if(indexPalavra == valorNo)
            {
                //atual->indComp = j+1;
                printf("\nJá existe a letra de numero :::%d", indexPalavra);
            }
            else break;
        }
    }
}


