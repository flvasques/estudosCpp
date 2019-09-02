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
void inserir();
void retirar();
void limpar_vetor(char *c, int tam);
void remover(No *arvore, int tamanho);

No *arvore;
ListaEnc *lista1 = new ListaEnc();
ListaEnc *lista2 = new ListaEnc();
ListaEnc *lista3 = new ListaEnc();
ListaEnc *lista4 = new ListaEnc();
char opcao;

static int contadorBinario = 0;
int main(int argc, char const *argv[])
{
	limparTela();
	lista1->insere(1);
	lista1->insere(3);
	lista1->insere(4);
	
	lista2->insere(2);
	lista2->insere(3);
	
	lista3->insere(4);
	lista3->insere(6);
	lista3->insere(8);
	lista3->insere(9);

	lista4->insere(7);
	lista4->insere(6);
	lista4->insere(8);
	lista4->insere(9);
	lista4->insere(0);

	arvore = new No(lista1);
	arvore->insere(lista2);
	arvore->insere(lista3);
	arvore->insere(lista4);

	menu();

	return 0;
}
void menu(){
	limparBuffer();
	cout << "1 - Buscar valor \t 2 - Imprimir \t 3 - Buscar Item \t 4 - Inserir Lista na Arvore \t 5 - Apagar Lista da Arvore" << endl;
	cout << "x - Para Sair" << endl;
	cin >> opcao;
	switch (opcao){
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
			delete lista1;
			delete lista2;
			delete lista3;
			delete lista4;
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
	cout << "O numero: " << num << ", foi encontrado: " << ret << " vez(es)." << endl;
}
void inserir()
{
	ListaEnc *lista = new ListaEnc();
	char *pre_lista = new char[2000000];
	pre_lista[0] = '\0';
	char *pre_elemento = new char[6];
	limpar_vetor(pre_elemento, 6);
	char separador = ',';
	int elemento;
	int i = 0;
	int j = 0;
	limparBuffer();
	cout << "Informe os elementos da lista e separados por virgula(,) sem espacos;" << endl;
	cin >> pre_lista;
	while(pre_lista[i] != '\0')i++;
	pre_lista[i] = ',';
	pre_lista[i + 1] = '\0';
	i = 0;
	while(pre_lista[i] != '\0')
	{
		if(pre_lista[i] != separador)
			pre_elemento[j++] = pre_lista[i];
		else if((pre_lista[i + 1] == '\0') || (pre_lista[i] == separador))
		{
			elemento = atoi(pre_elemento);
			lista->insere(elemento);
			limpar_vetor(pre_elemento, 6);
			j = 0;
		}

		i++;
	}
	arvore->insere(lista);
	delete[] pre_lista;
	delete[] pre_elemento;
}
void retirar()
{
	arvore->imprimePre();
	int tam;
	cout << "Escolha o item pelo tamaho em caso de tamanhos o iguais o primeiro sera apagado." << endl;
	cin >> tam;
	remover(arvore, tam);

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
void remover(No *ar,int tamanho)
		{
	if(tamanho == ar->valor->tam)
	{
		if(ar->esq == NULL && ar->dir == NULL)
		{	if(ar->pai->dir == ar)
				ar->pai->dir = NULL;
			if(ar->pai->esq == ar)
				ar->pai->esq = NULL;
			free(ar);
		}
		else if(ar->dir != NULL)
		{
			ar->pai->dir == ar->dir;
			delete ar->valor;
			free(ar);
		}
		else if(ar->esq != NULL)
		{
			ar->pai->esq == ar->esq;
			delete ar->valor;
			free(ar);
		}
		else if(ar->esq != NULL && ar->dir != NULL)
		{
			No *aux = ar->esq;
			while(aux->dir != NULL)
				aux = aux->dir;
			ListaEnc *aux_valor = ar->valor;
			ar->valor = aux->valor;
			aux->valor = aux_valor;
			if(aux->esq == NULL && aux->dir == NULL)
				delete aux;
			else
			{
				aux->pai->esq == aux->esq;
				delete aux->valor;
				free(aux);
			}
		}
	}
	else
	{
		if(ar->esq != NULL)
			remover(ar->esq, tamanho);
		if(ar->dir != NULL)
			remover(ar->dir, tamanho);
	}
}