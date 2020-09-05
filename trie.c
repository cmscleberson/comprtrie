
#include <stdlib.h>
#include <stdio.h>


#define TAM 26
#define LIN_MAT 5000
#define COL_MAT 26

char matrizPalav [LIN_MAT][COL_MAT];
char matrizResult [LIN_MAT][COL_MAT];
int contOcorr[LIN_MAT];




typedef struct No
{
    int idxWord;
    
    int tam;

    struct No* filho[TAM];
	int ehFinal;
} No;




int retornaIndVazioP()
{
	int i=0, j;
	for(i=0; i<LIN_MAT; i++)
	{
		
		if(matrizPalav[i][0] == NULL)
			break;
	}
	return i;
}


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
	

    return no;
}






int retornaIndVazioRes()
{
	int i=0, j;
	for(i=0; i<LIN_MAT; i++)
	{
		
		if(matrizResult[i][0] == NULL)
			break;
	}
	return i;
}


void insereMatrizRes(char* value)
{
	int idx = retornaIndVazioRes();
	int i;
	char* vl = value;
	int tam = 0;
	
	while(*vl)
	{
		tam++;
		vl++;
	}
	
	for(i=0; i<tam;i++)
	{
		matrizResult[idx][i] = *value;
		value++;

	}
}



void insereMatrizP(char* value)
{
	int idx = retornaIndVazioP();
	int i;
	char* vl = value;
	int tam = 0;
	
	while(*vl)
	{
		tam++;
		vl++;
	}
	
	for(i=0; i<tam;i++)
	{
		matrizPalav[idx][i] = *value;
		value++;

	}
}




void insereNo(No* raiz, char *valor, int idx)
{
    int tam =raiz->tam;
    int cont = 0;
    char *valorTemp = valor;
    int index;

    No* atual = raiz;


    while(*valorTemp)
    {
        index = *valorTemp-'a';

        if(atual->filho[index] != NULL)
        {
            cont++;
        }
        else
        {
            break;
        }

        atual = atual->filho[index];
        valorTemp++;

    }

    //se falso eh pq a palavra já existe inteira na trie, nada eh adicionado
    if(cont != tam)
    {

			atual->filho[index] = criaNo(valor);
            atual->filho[index]->idxWord = idx;
			atual->filho[index]->ehFinal = 1;
            atual = atual->filho[index];

	}
}





void util(No* root, int count, char* st, int pos) {
        
		No* atual = root;
		char* stt = st;
		int tam = 0;
		while(*stt)
		{
			tam++;
			stt++;
		}
	
        if(count > 1 && pos == tam)
            return;
			
        for(int i = pos; i < tam; i++) 
		{
            int index = st[i] - 'a';

            if(!atual->filho[index])
                break;
           
			int ind = atual->filho[index]->idxWord;
			printf("\nTeste indice matriz palavra:::%d\n",ind);


			char* vlIns = matrizPalav[ind];
			insereMatrizRes(vlIns);
			printf("\nValor inserido no arquivo result:::%s\n",vlIns);
			
			atual = atual->filho[index];
			
			util(atual, count + 1, st, i + 1);
                
            
        }
}



void processa(No* root) 
{		
	    No* atual = root;
		int ind= retornaIndVazioP();
		int i;
        for(i=0; i<ind; i++)
		{
			char *palavra = matrizPalav[i];
			if(*palavra != NULL)
			{
				insereNo(root, palavra, i);
				printf("\nPalavra inserida na trie:::%s\n", palavra);
				printf("\nIndice usado::: %d\n", i);

			}
			
		}		
}





int main(int argc, char **argv)
{
	
	
	
    No* raiz = criaNo("+");
   
	
	insereMatrizP("tem");
	insereMatrizP("test");
		insereMatrizP("templo");
		



	processa(raiz);
	
	char *plB = "te";
	
	util(raiz, 0, plB, 0);
	
	

	
	//printf("\nResult::::%d", res);
	
	return 0;
}



	
	
	
    

