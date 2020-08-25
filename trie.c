

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM 60



typedef struct No
{

    char *valor[TAM];
    struct No* filho[TAM];

    int ehFinal;


} No;


No* criaNo()
{

    No* novo = (No*) malloc(sizeof(No));
    novo ->ehFinal = 0;

    int i;
    for(i=0; i<TAM; i++)
    {
        novo->filho[i] = NULL;
    }

    return novo;

}

void inserirNo(No* raiz, char val[], int tamP)
{

    No* atual = raiz;
	No* ultimo = (No*) malloc(sizeof(No));
    int i,j, index; 
	int indParada = -1;
	printf("\nPalavra a inserir: %s\n", val);

    for(i=0; i<tamP; i++)
    {
        index = val[i]-'A';
		if(atual->filho[index] != NULL)
		{
			atual->ehFinal = 0;
			ultimo = atual;
			atual = atual->filho[index];
			printf("\n Já tem a letra :: %c", val[i]);		
		}
		else
		{
			indParada = i;
			break;
		}
	}
	
	printf("\nIndice de parada da palavrs:\n%d", indParada);
	
	
	if(indParada<tamP-1)
	{
		char palavr[tamP-indParada];
		//palavr='';
		for(j=indParada; j<tamP; j++)
		{
			palavr = palavr+val[j];
		}
		
			int ini;
			ini = val[indParada]-'A';
	
			No* novo = criaNo();
			*novo->valor = palavr;
			atual->filho[ini] = novo;
			printf("Inserido::: %s", palavra);
	}		
	
	
	
	


}

