
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM 26



typedef struct No
{
    char valor[TAM];
    struct No* filho[TAM];
	int ehFinal;


} No;


No* criaNo()
{
    No* no = (No*) malloc (sizeof(No));

    int i;
    for(i=0; i<TAM; i++)
    {
        no->filho[i] = NULL;
        no->valor[i] = NULL;
    }


    return no;

}


void insereChaveValor(No* raiz, char* valorT, int idx, int contad, int taman)
{
    No* atual = raiz;
    int j, k=0;
    char v;
    for(j=0; j<taman;j++)
    {
        atual->valor[j] = valorT[j];
        printf("\n Valor inseerido:::%c",valorT[j] );
    }

}

int *retValFilhos(No* raiz)
{
    int val[TAM],i,j;
    int k = 0;

    for(j=0; j<TAM; j++)
    {
        val[j] = NULL;
    }

    for(i=0; i<TAM; i++)
    {
        if(raiz->filho[i] != NULL)
        {
            val[k] = i;
            k++;
        }
    }
    int *ptr = val;
    return ptr;

}












void comprime(No* raiz, char* valor, int idxAtual)
{

No* temp = raiz;
int corte=0;
int tamValorNo = sizeof(temp->valor)/sizeof(temp->valor[0]);

//identifica ponto onde as palavras se diferem
while(temp->valor[corte]==valor[corte])
{
    corte++;
}

printf("\nIndice de corte da palavra::%d", corte);

int i, k=0;
char iguald[corte];
char sufNo[TAM];
char sufPalav[TAM];


//identifica as partes iguais entre o valor do nó e o valor a ser inserido (prefixos iguais)
for(i=0; i<corte; i++)
{
    if(temp->valor[i] != NULL)
    {
        iguald[i] = temp->valor[i];
        printf("\nIgualdade+++%c", temp->valor[i]);
    }
    else
    {
        iguald[i] = NULL;
    }


}


int t=0;
//extrai as partes diferentes (sufixos) entre o valor do nó e o valor a ser inserido
for(i=corte; i<TAM; i++)
{
    if(temp->valor[i] != NULL)
    {
        sufNo[t] = temp->valor[i] ;
        t++;
    }
}

t=0;
for(i=corte; i<TAM; i++)
{
    if(valor[i] != NULL)
    {
        sufPalav[t] = valor[i];
        t++;
    }
}



temp->ehFinal = 0;

//cria um novo nó, com a chave sendo o primeiro caracter de igualdade, e dois nós com os valores diferentes
int idxA = sufNo[0]-'a';
int idxB = sufPalav[0]-'a';
int tamVetSufA = sizeof(sufNo)/sizeof(sufNo[0]);

int tamVetSufB = sizeof(sufPalav)/sizeof(sufPalav[0]);


temp->filho[idxAtual]->filho[idxA] = criaNo();
temp->filho[idxAtual]->filho[idxB] = criaNo();





//atribui novo valor ao nó, retirando os sufixos
int tamVetIgual = sizeof(iguald)/sizeof(iguald[0]);
int p=0;
for(i=1; i<=tamVetIgual; i++)
{
    if(iguald[i] != NULL)
    {
      temp->valor[p] = iguald[i];
        p++;
    }
    else
        {
        temp->valor[p]= NULL;
        p++;
        }

}



for(i=0; i<tamVetSufA; i++)
{
    temp->filho[idxAtual]->filho[idxA]->valor[i] = sufNo[i];

}


for(i=0; i<tamVetSufB; i++)
{
    temp->filho[idxAtual]->filho[idxB]->valor[i] = sufPalav[i];

}


printf("\nSufixA::%s", temp->valor);

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


    int cont=0;
    int index;
    int indexUlt;

    No* atual = raiz;
    No* temp=NULL;
    printf("\n\nTamanho::%d\n", tam);

    while(*valorTemp)
    {

        index = *valorTemp-'a';

        if(atual->filho[index] != NULL)
        {

            temp = atual;
            indexUlt = index;
            cont++;
            printf("\n:::: Letra jah inserida:::\n%d", index);
        }
        else
        {

            break;
        }
        atual = atual->filho[index];

        valorTemp++;

    }


    //se for palavra repetida, a execução termina cont=tam
    if(cont != tam )
    {



        if(temp != NULL)
        {
            if(temp->valor == NULL)
            {   //O noh não possui valor alem da chave, inserir a chave e o valor

            atual->filho[index] = criaNo();

            cont++;
            int j, k=0;

            for(j=cont; j<tam; j++)
            {
                atual->valor[k] = valorTemp[j];
                printf("\nInserida letra como valor::::%c", atual->valor[k]);
                k++;

            }

            atual = atual->filho[index];



            }
            else
            {
                //Nó com chave e valor associado, dividir o nó entre o novo valor e o valor do nó (compressão)
                printf("\nO noh possui  um valor alem da chave. Fazer a compressão");
                printf("\nPalavras para compressão:::%s--%s", temp->valor ,valorTemp);
                printf("\nUltimo index:::%d", index);
                comprime(temp, valorTemp, indexUlt);
                atual = temp;


            }
        }
        else
        {
            //Não existe palavra com a inicial informada. Insere o noh filho e o valor
            atual->filho[index] = criaNo();

            cont++;
            int j, k=0;

            for(j=cont; j<tam; j++)
            {
                atual->valor[k] = valorTemp[j];
                printf("\nInserida letra como valor::::%c", atual->valor[k]);
                k++;

            }

            atual = atual->filho[index];


        }
    }

}


void busca(No* raiz, char* prefix)
{

    No* atual = raiz;


}











