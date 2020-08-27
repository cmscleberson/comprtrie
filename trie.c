
#include <stdlib.h>
#include <stdio.h>


#define TAM 26



typedef struct No
{

    char *valor;
    struct No* filho[TAM];
	int indComp;
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




void insereNo(No* raiz, char *palavra)
{
    No* atual = raiz;
    int cont = 0;
    int indIniResto = 0;
    int j =0;
    char *temp = palavra;
    char temp2[TAM];
    char *temp3 = palavra;
    char palavIns;

    while(*temp)
    {
       cont++;
       temp++;
    }



    while(*palavra)
    {
        int index = *palavra-'a';

        if(atual->filho[index] == NULL)
        {
            int k;
            char teste = (char) index;

            atual->filho[index] = criaNo();


            for(k = indIniResto; k<cont; k++)
            {
                temp2[j] = palavra[k];

                j++;
            }
                atual->valor = temp3;
                break;
            }


        atual = atual->filho[index];
        palavra++;
        indIniResto++;

    }
    atual->ehFinal =1;
        printf("\nEh o noh final::: %d", atual->ehFinal);

   }


