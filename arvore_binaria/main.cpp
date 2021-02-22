#include <iostream>
#include <stdlib.h>
#include "arvorebin.h"
#ifdef __linux__ 
	#include <stdio_ext.h>
#endif

using namespace std;

void menu();
void imprime();
void limparTela();
void limparBuffer();
void buscar();
void inserir();
void retirar();
void limpar_vetor(char *c, int tam);

No *arvore;
char opcao;

static int contadorBinario = 0;
int main(int argc, char const *argv[])
{
	limparTela();
	arvore = new No(1);
	arvore->insere(3);
	arvore->insere(2);
	arvore->insere(4);

	menu();

	return 0;
}
void menu()
{
	limparBuffer();
	cout << "1 - Buscar valor \t 2 - Imprimir \t 3 - Buscar Item \t 4 - Inserir \t 5 - Apagar" << endl;
	cout << "x - Para Sair" << endl;
	cin >> opcao;
	switch (opcao) {
		case '1':
			limparTela();
			buscar();
			menu();
			break;
		case '2':
			limparTela();
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
			inserir();
			menu();
			break;
		case '5':
			limparTela();
			retirar();
			menu();
			break;
		case 'x':
			limparTela();
			limparBuffer();
			delete arvore;
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
	cout<< "=====" << endl;
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
	limparBuffer();
	int num = 0;
	cout << "Buscar e Contar a repeticao de um numero nas listas." << endl;
	cout << "Informe o valor que dejesa buscar." << endl;
	cin >> num;
	int ret = arvore->buscar(num);
	cout << "O numero: " << num << (ret == 1 ? ", foi encontrado"  : ", nao foi encontrado")<< endl;
}
void inserir()
{
	char *pre_elemento = new char[6];
	limpar_vetor(pre_elemento, 6);
	int elemento;
	limparBuffer();
	
	cout << "Por favor informe um inteiro valido." << endl;
	cin >> pre_elemento;

	elemento = atoi(pre_elemento);
	arvore->insere(elemento);
	limpar_vetor(pre_elemento, 6);

	delete[] pre_elemento;
}
void retirar()
{
	arvore->imprimePre();
	int numero;
	cout << "Escolha o item pelo tamaho em caso de tamanhos o iguais o primeiro sera apagado." << endl;
	cin >> numero;
	
	if(arvore->valor == numero) 
	{
		No *aux = arvore;

		if(arvore->esq != NULL)
			arvore = arvore->esq;
		if(arvore->dir != NULL)
			arvore = arvore->dir;
		free(aux);
	}
	else 
		arvore->remover(numero);


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
void limpar_vetor(char *c, int tam)
{
	for(int i = 0; i < tam; i++)
		c[i] = '\0';
}