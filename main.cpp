#include <iostream>
#include <stdlib.h>
#include "arvorebin.h"
#include "listaenc.h"
#ifdef __linux__ 
	#include <stdio_ext.h>
#endif

using namespace std;

void menu();
void imprime();
void limparTela();
void limparBuffer();
void buscar();

No *arvore;
char opcao;

static int contadorBinario = 0;
int main(int argc, char const *argv[])
{
	limparTela();
	ListaEnc *lista1 = new ListaEnc();
	lista1->insere(1);
	lista1->insere(3);
	lista1->insere(4);

	ListaEnc *lista2 = new ListaEnc();
	lista2->insere(2);
	lista2->insere(3);

	ListaEnc *lista3 = new ListaEnc();
	lista3->insere(4);
	lista3->insere(6);
	lista3->insere(8);
	lista3->insere(9);

	ListaEnc *lista4 = new ListaEnc();
	lista4->insere(7);
	lista4->insere(6);
	lista4->insere(8);
	lista4->insere(9);
	lista4->insere(0);

	No *arvore = new No(lista1);
	arvore->insere(lista2);
	arvore->insere(lista3);
	arvore->insere(lista4);

	menu();

	return 0;
}
void menu(){
	limparBuffer();
	cout << "1 - Buscar valor\t2 - Imprimir\t3 - Buscar Item\t4 - Apagar Nodo Arvore" << endl;
	cout << "x - Para Sair" << endl;
	cin >> opcao;
	switch (opcao){
		case '1':
			limparTela();
			buscar();
			menu();
			break;
		case '2':
			imprime();
			menu();
			break;
		case '3':
			limparTela();
			buscar();
			menu();
			break;
		case '4':
			limparTela();
			retirar();
			menu();
			break;
		case 'x':
			limparTela();
			limparBuffer();
			exit(0);
			break;
		default:
			limparTela();
			cout<< "Opcao Invalida!" << endl;
			menu();
			break;
	}
}
void imprime()
{ 
	cout << "Pre ordem." << endl;
	arvore->imprimePre();
	cout<< "=====" << endl;
	cout << "Pos ordem." << endl;
	arvore->imprimePos();
	cout<< "=====" << endl;
	cout << "Em ordem." << endl;
	arvore->imprimeEm();
}
void limparTela()
{
	#ifdef __linux__ 
    	system("clear");
	#elif _WIN32
	    system("cls");
	#else

	#endif
}
void buscar()
{
	
}
void retirar()
{

}
void limparBuffer()
{
	#ifdef __linux__ 
    	 __fpurge(stdin);
	#elif _WIN32
	    fflush(stdin);
	#else

	#endif
}