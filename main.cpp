#include <iostream>
#include "trie.c"

using namespace std;

int main()
{

    No* raiz = criaRaiz();


    inserir(raiz, "teste");
    inserir(raiz, "testa");

    return 0;
}
