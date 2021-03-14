#include <iostream>
#include "arvorebin.h"
using namespace std;
No::No(int v)
{
	this->esq = NULL;
	this->dir = NULL;
	this->pai = NULL;
	this->valor = v;
}
No::No(int v, No *pai)
{
	this->esq = NULL;
	this->dir = NULL;
	this->pai = pai;
	this->valor = v;
}
No::~No()
{
	if(this->esq != NULL)
		this->esq->~No();
	if(this->dir != NULL)
		this->dir->~No();
	free(this);
}
void No::insere(int v)
{
	if(v == this->valor)
	{
		printf ("Elemento repetido. \n");
		return;
	} else if(v < this->valor)
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
void No::insere(No *no)
{
	if(no->valor <= this->valor)
	{
		if(this->esq == NULL)
		{
			this->esq = no;
			no->pai = this;
		}
		else
			this->esq->insere(no);
	}
	else
	{
		if(this->dir == NULL)
		{
			this->dir = no;
			no->pai = this;
		}
		else
			this->dir->insere(no);
	}
}
void No::imprimePre()
{
	printf("%i", this->valor);
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
	printf("%i", this->valor);
	cout << endl;
}
void No::imprimeEm()
{
	if(this->esq != NULL)
		this->esq->imprimeEm();
	printf("%i", this->valor);
	cout << endl;
	if(this->dir != NULL)
		this->dir->imprimeEm();
}
int No::buscar(int num)
{
	if(this->valor == num)
		return 1;
	else if(num < this->valor && this->esq != NULL)
		return this->esq->buscar(num);
	else if(num > this->valor && this->dir != NULL)
		return this->dir->buscar(num);
	else
		return 0;
}

void No::remover(int num) 
{
	if (this->valor == num)
	{

		if(this->pai != NULL && this->esq != NULL)
		{
			if(this->valor < this->pai->valor)
				this->pai->esq = this->esq;
			else
				this->pai->dir = this->esq;
			
			if(this->dir != NULL)
				this->esq->insere(this->dir);
		}
		else if(this->pai != NULL && this->dir != NULL)	
		{
			if(this->valor < this->pai->valor)
				this->pai->esq = this->dir;
			else
				this->pai->dir = this->dir;
		}	
		free(this);
	}
	else if(num < this->valor && this->esq != NULL)
		this->esq->remover(num);
	else if(num > this->valor && this->dir != NULL)
		this->dir->remover(num);
}

int No::count(int num, int i)
{
	return 0;
}

int No::altura()
{
	// Cria 2 variaveis para determinar a altura
	int altura_esquerda = 0;
	int altura_direita  = 0;

	if(this->esq != NULL)
	{
		altura_esquerda = this->esq->altura();
	}
	
	if(this->dir != NULL)
	{
		altura_direita = this->dir->altura();
	}
	
	// Determina qual dos lados da Arvore é mais alto
	if (altura_esquerda < altura_direita)
		return altura_direita + 1;
	else
		return altura_esquerda + 1;

}

