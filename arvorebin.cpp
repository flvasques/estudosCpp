#include <iostream>
#include "arvorebin.h"
using namespace std;
No::No(ListaEnc *v)
{
	this->esq = NULL;
	this->dir = NULL;
	this->valor = v;
}
void No::insere(ListaEnc *v)
{
	if(v->tam < this->valor->tam)
	{
		if(this->esq == NULL)
			this->esq = new No(v);
		else
			this->esq->insere(v);
	}
	else
	{
		if(this->dir == NULL)
			this->dir = new No(v);
		else
			this->dir->insere(v);
	}
}
void No::imprimePre()
{
	try
	{
		this->valor->imprime();
		if(this->esq != NULL)
			this->esq->imprimePre();
		if(this->dir != NULL)
			this->dir->imprimePre();
	}
	catch (char *excp) 
	{ 
        cout << "Caught: " << excp; 
    }  
}
void No::imprimePos()
{
	if(this->esq != NULL)
		this->esq->imprimePos();
	if(this->dir != NULL)
		this->dir->imprimePos();
	this->valor->imprime();
}
void No::imprimeEm()
{
	if(this->esq != NULL)
		this->esq->imprimeEm();
	this->valor->imprime();
	if(this->dir != NULL)
		this->dir->imprimeEm();
}
int No::buscar(int num)
{/*
	if(this->valor == num) 
		return 1;	
	else
	{
		if(num < this->valor)
		{
			if(this->esq != NULL)
				this->esq->buscar(num);
			else
				return 0;
		}
		else
		{
			if(this->dir != NULL)
				this->dir->buscar(num);
			else
				return 0;
		}
	}*/
	return 0;
}
int No::count()
{/*
	if(this->esq != NULL)
		return 1 + this->esq->count();
	else
		return 0;*/
	return 0;
}