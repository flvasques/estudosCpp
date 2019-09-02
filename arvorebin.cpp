#include <iostream>
#include "arvorebin.h"
#include "listaenc.h"
using namespace std;
No::No(ListaEnc *v)
{
	this->esq = NULL;
	this->dir = NULL;
	this->pai = NULL;
	this->valor = v;
}
No::No(ListaEnc *v, No *pai)
{
	this->esq = NULL;
	this->dir = NULL;
	this->pai = pai;
	this->valor = v;
}
No::~No()
{
	if(this->esq == NULL)
		this->esq->~No();
	if(this->dir == NULL)
		this->dir->~No();
	delete[] this->valor;
	free(this);
}
void No::insere(ListaEnc *v)
{
	if(v->tam <= this->valor->tam)
	{
		if(this->esq == NULL)
			this->esq = new No(v, this);
		else
			this->esq->insere(v);
	}
	else
	{
		if(this->dir == NULL)
			this->dir = new No(v, this);
		else
			this->dir->insere(v);
	}
}
void No::imprimePre()
{
	this->valor->imprime();
	cout << endl;
	if(this->esq != NULL)
		this->esq->imprimePre();
	if(this->dir != NULL)
		this->dir->imprimePre();
}
void No::imprimePos()
{
	if(this->esq != NULL)
		this->esq->imprimePos();
	if(this->dir != NULL)
		this->dir->imprimePos();
	this->valor->imprime();
	cout << endl;
}
void No::imprimeEm()
{
	if(this->esq != NULL)
		this->esq->imprimeEm();
	this->valor->imprime();
	cout << endl;
	if(this->dir != NULL)
		this->dir->imprimeEm();
}
int No::buscar(int num)
{
	int acumulador = 0;
	acumulador = this->valor->procurar(num, 0);
	if(this->esq != NULL)
		acumulador += this->esq->buscar(num);
	if(this->dir != NULL)
		acumulador += this->dir->buscar(num);
	return acumulador;
}

int No::count(int num, int i)
{
	return 0;
}