#include <iostream>
#include <stdlib.h>
#include "arvoreavl.h"
#ifdef __linux__ 
	#include <stdio_ext.h>
#endif

using namespace std;

NoAVL *arvore;
char opcao;

static int contadorBinario = 0;
int main(int argc, char const *argv[])
{
	arvore = new NoAVL(1);
	arvore->insere(1, true);
	arvore->insere(3, true);
	arvore->insere(2, true);
	arvore->insere(4, true);
	cout << "Altura da arvore: " << arvore->altura() << endl;
	arvore->remover(4);
	cout << "Altura da arvore: " << arvore->altura() << endl;
	arvore->imprimePre();
	//arvore->imprimePos();
	//arvore->imprimeEm();
	delete arvore;
	return 0;
}