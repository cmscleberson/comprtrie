

#define TAM 30

typedef struct No
{
    char value[TAM];
    struct No* prox;
    int fimPalavra;
    int contaPalavra;

};



struct No* criaRaiz()
{
    struct No* no = (struct No*) malloc(sizeof(struct No));
    no->fimPalavra = 1;
    return no;
}







void inserir(struct No* raiz, char valor[])
{
    struct No* noAt = raiz;

    while(noAt->fimPalavra != 1)
    {
        noAt->fimPalavra = 0;
        noAt = noAt->prox;
    }


    int tam = sizeof(valor)/sizeof(valor[0]);

    int i,j;
    for(i=0; i<tam; i++)
    {
        if(valor[i] && noAt->value[i])
        {
            if(valor[i] != noAt->value[i])
            {
                struct No *novo = criaRaiz();
                noAt->prox = novo;
                noAt->fimPalavra = 0;



                int fim = sizeof(valor)/sizeof(valor[0]);
                int m = 0;

                for(j=i; j<=fim; j++)
                {
                    novo->value[m] = valor[j];
                    printf("Inserindooooo: %c", valor[j]);
                    printf("\n");
                    m++;
                }
                novo->fimPalavra = 1;
                break;
            }
        }
    }
}

