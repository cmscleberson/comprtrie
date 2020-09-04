
#include <stdlib.h>
#include <stdio.h>


#define TAM 26


typedef struct No
{
    int *idxWord;
    int *iniWord;
    int *fimWord;
    int tam;

    struct No* filho[TAM];
	int ehFinal;


} No;




No* criaNo(char *valor)
{
    char *vl = valor;
    No* no = (No*) malloc (sizeof(No));


    int i, tam = 0;

    for(i=0; i<TAM; i++)
    {
        no->filho[i] = NULL;
    }

    while(*vl)
    {
        tam++;
        vl++;
    }
	no->idxWord = NULL;
	no->fimWord = NULL;
	no->iniWord = NULL;

    printf("\nNoh criado coom o valor::::%s\n", valor);
    return no;
}



char* retValor(int idx)
{

char* teste = "bear";
return teste;

}


void insereNo(No* raiz, char *valor, int idx)
{
    int tam =raiz->tam;
    int cont = 0;

    char *valorTemp = valor;


    int index;
    int indexUlt;

    No* atual = raiz;
	printf("\nTeste Raiz%d", atual->idxWord);


    while(*valorTemp)
    {
        index = *valorTemp-'a';

        if(atual->filho[index] != NULL)
        {
            atual->ehFinal = 0;
            cont++;
            printf("\n:::: Letra jah inserida:::%d\n", index);
        }
        else
        {
            break;
        }

        atual = atual->filho[index];
        valorTemp++;

    }

    //se true eh pq a palavra já existe inteira na trie, nada eh adicionado
    if(cont != tam)
    {

        //primeira chave

		if(atual->fimWord == NULL)
		{
			atual->filho[index] = criaNo(valor);
            atual->filho[index]->iniWord = &cont;
            atual->filho[index]->idxWord = &idx;
            atual->filho[index]->fimWord = &tam;
			atual->filho[index]->ehFinal = 1;

            atual = atual->filho[index];
			printf("\Primeira chave criada com a inicial\n");


		}
		else
		{
			//chave já existe. verificar o segundo digito para atualizar valores ou criar novo Noh
		    int indexBusca = *atual->idxWord;
			int contIg = 0;
		    char *vlBuscado = retValor(indexBusca);
		    char *vlParaIns = valor;
			
			while(*vlBuscado)
			{
				char a = *vlParaIns;
				char b = *vlBuscado;
				if(a==b)
				{
					contIg++;
				}
				else
				{
					break;
				}

				vlBuscado++;
				vlParaIns++;
				
			}
			
			//primeira e segunda letra já existem, atualizar valores do noh
			if(contIg>1)
			{
				//move ponteiros para inserir novos valores
				atual->iniWord++;
				atual->idxWord++;
				atual->fimWord++;
				
				atual->iniWord = &cont;
				atual->idxWord = &idx;
				atual->fimWord = &tam;
				printf("\nprimeira e segunda letra já existem, att valores do noh\n");
			}
			
			//a segunda letra não eh igual ao valor do Noh, criar um novo
			else
			{
				atual->filho[index] = criaNo(valor);
				atual->filho[index]->iniWord = &cont;
				atual->filho[index]->idxWord = &idx;
				atual->filho[index]->fimWord = &tam;
				atual->filho[index]->ehFinal = 1;

				atual = atual->filho[index];
				printf("\na segunda letra não eh igual ao valor do Noh, criar um novo\n");
				
			}

		}

            }

}








