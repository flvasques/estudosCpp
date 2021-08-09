#include <iostream>
#include "arvoreavl.h"
using namespace std;
NoAVL::NoAVL(int v)
{
	this->esq = NULL;
	this->dir = NULL;
	this->valor = v;
	this->fatBal = 0;
	this->raiz = NULL;
}

NoAVL::NoAVL(int v, NoAVL *pai)
{
	this->esq = NULL;
	this->dir = NULL;
	this->valor = v;
	this->fatBal = 0;
	this->raiz = pai;
}

NoAVL::~NoAVL()
{
	if(this->esq != NULL)
		this->esq->~NoAVL();
	if(this->dir != NULL)
		this->dir->~NoAVL();
	free(this);
}

void NoAVL::insere(int elem, bool status)
{
	if(elem == this->valor)
	{
		printf ("Elemento repetido. \n");
		return;
	} 
	else if (elem < this->valor)
	{
		if(this->esq == NULL)
		{
			this->esq = new NoAVL(elem, this);
			if (status == true)
			{
				switch (this->fatBal)
				{
					case 1 : this->fatBal = 0; status = false; break;
					case 0 : this->fatBal = -1; break;
					case -1 : this->rotacionarDir(this, status); break;
				}
			}
		}
		else
			this->esq->insere(elem, status);
	}
	else
	{
		if(this->dir == NULL)
		{
			this->dir = new NoAVL(elem, this);
			if (status == true)
			{
				switch (this->fatBal)
				{
					case -1 : this->fatBal = 0; status = false; break;
					case 0 : this->fatBal = 1; break;
					case 1 : this->rotacionarEsq(this, status); break;
				}
			}
		}
		else
			this->dir->insere(elem, status);
	}
}
void NoAVL::rotacionarDir (NoAVL *a, bool status)
{
	NoAVL *b, *c;
	b = a->esq;
	if (b->fatBal == -1)
	{ // rotação simples
		a->esq = b->dir;
		b->dir = a;
		a->fatBal = 0;
		a = b;
	}
	else
	{ // rotação dupla
		c = b->dir;
		b->dir = c->esq;
		c->esq = b;
		a->esq = c->dir;
		c->dir = a;
		if (c->fatBal == -1)
		a->fatBal = 1;
		else a->fatBal = 0;
		if (c->fatBal == 1)
		b->fatBal = -1;
		else b->fatBal = 0;
		a = c;
	}
	a->fatBal = 0;
	status = false;
}

void NoAVL::rotacionarEsq(NoAVL *a, bool status)
{
	NoAVL *b, *c;
	b = a->dir;
	if(b->fatBal == 1) 
	{ // rotação simples
		a->dir = b->esq;
		b->esq = a;
		a->fatBal = 0;
		a = b;
	}
	else 
	{ // rotação dupla
		c = b->esq;
		b->esq = c->dir;
		c->dir = b;
		a->dir = c->esq;
		c->esq = a;
		if (c->fatBal == 1)
		a->fatBal = -1;
		else a->fatBal = 0;
		if (c->fatBal == -1)
			b->fatBal = 1;
		else
			b->fatBal = 0;
		a = c;
	}
	a->fatBal = 0;
	status = false;
}
void NoAVL::imprimePre()
{
	printf("%i", this->valor);
	cout << endl;
	if(this->esq != NULL)
		this->esq->imprimePre();
	if(this->dir != NULL)
		this->dir->imprimePre();
}
void NoAVL::imprimePos()
{
	if(this->esq != NULL)
		this->esq->imprimePos();
	if(this->dir != NULL)
		this->dir->imprimePos();
	printf("%i", this->valor);
	cout << endl;
}
void NoAVL::imprimeEm()
{
	if(this->esq != NULL)
		this->esq->imprimeEm();
	printf("%i", this->valor);
	cout << endl;
	if(this->dir != NULL)
		this->dir->imprimeEm();
}

int NoAVL::buscar(int num)
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

int NoAVL::altura()
{
	// Cria 2 variaveis para determinar a altura
	int altura_esquerda = 0;
	int altura_direita  = 0;

	if(this->esq != NULL )
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

void NoAVL::remover(int num) 
{
	if (this->valor == num)
	{

		if(this->raiz != NULL && this->esq != NULL)
		{
			if(this->valor < this->raiz->valor)
				this->raiz->esq = this->esq;
			else
				this->raiz->dir = this->esq;
			
			if(this->dir != NULL)
				this->esq->insere(this->dir);
		}
		else if(this->raiz != NULL && this->dir != NULL)	
		{
			if(this->valor < this->raiz->valor)
				this->raiz->esq = this->dir;
			else
				this->raiz->dir = this->dir;
		}
		else if(this->raiz != NULL && (this->dir == NULL && this->dir == NULL))	
		{
			if(this->valor < this->raiz->valor)
				this->raiz->esq = NULL;
			else
				this->raiz->dir = NULL;
		}	
		free(this);
	}
	else if(num < this->valor && this->esq != NULL)
		this->esq->remover(num);
	else if(num > this->valor && this->dir != NULL)
		this->dir->remover(num);
}

void NoAVL::insere(NoAVL *no)
{
	if(no->valor <= this->valor)
	{
		if(this->esq == NULL)
		{
			this->esq = no;
			no->raiz = this;
			switch (this->fatBal)
			{
				case 1 : this->fatBal = 0; break;
				case 0 : this->fatBal = -1; break;
				case -1 : this->rotacionarDir(this, true); break;
			}
		}
		else
			this->esq->insere(no);
	}
	else
	{
		if(this->dir == NULL)
		{
			this->dir = no;
			no->raiz = this;
			switch (this->fatBal)
			{
				case -1 : this->fatBal = 0; break;
				case 0 : this->fatBal = 1; break;
				case 1 : this->rotacionarEsq(this, true); break;
			}
		}
		else
			this->dir->insere(no);
	}
}