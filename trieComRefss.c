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
    int iniWord;
    int fimWord;
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









char* retValorNo(int idx)
{

char *valor = matrizPalav[idx];
return valor;
}






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
    int indexUlt;

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
			printf("\nTeste Indice da Palavra:::::%d", atual->idxWord);

        atual = atual->filho[index];
        valorTemp++;

    }

    //se falso eh pq a palavra já existe inteira na trie, nada eh adicionado
    if(cont != tam)
    {

			atual->filho[index] = criaNo(valor);
            atual->filho[index]->iniWord = cont;
            atual->filho[index]->idxWord = idx;
            atual->filho[index]->fimWord = tam;
			atual->filho[index]->ehFinal = 1;
            atual = atual->filho[index];
	}
}





int util(No* root, int count, char* st, int pos) {
        
		No* atual = root;
		char* stt = st;
		int tam;
		while(*stt)
		{
			tam++;
			stt++;
		}
	
        if(count > 1 && pos == tam)
            return 1;
			
        for(int i = pos; i < tam; i++) 
		{
            int index = st[i] - 'a';
            if(!atual->filho[index])
                return 0;
            if(atual->filho[index]->ehFinal == 1 && util(atual, count + 1, st, i + 1))
                return 1;
            atual = atual->filho[index];
        }
        return 0;
}



void processa(No* root) 
{		
	    No* atual = root;
		int i;
        for(i=0; i<LIN_MAT; i++)
		{
			char *palavra = matrizPalav[i];
			insereNo(root, palavra, i);

		}

		int index = atual->idxWord;
		char* valorNo = matrizPalav[index];
		insereMatrizRes(valorNo);
		
		
        for(i=0; i<LIN_MAT; i++)
		{
			char *palavra = matrizPalav[i];
            if(util(atual, 0, palavra, 0)==1)
			{
				insereMatrizRes(palavra);
			}
        }
}


int buscaNo(No* raiz, char* prefix)
{
	No* atual = raiz;
	char* pref = prefix;
	char* prefA = prefix;
	int tamPrefix = 0;
	
	while(*prefA)
	{
		tamPrefix++;
		prefA++;
	}

	int contP = 0;
	
	while(*pref)
	{
		int index = *pref-'a';
		
		if(atual->filho[index] != NULL)
		{
			atual = atual->filho[index];
			contP++;
		}
		else break;

		pref++;
	}
	
	if(contP == 0)
	{
		return 0;
	}
	
	processa(atual);
	
}






