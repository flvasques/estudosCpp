#include <iostream>
#include "listaenc.h"
#include "nodo.h"
ListaEnc::ListaEnc()
{
	this->tam = 0;
	this->primeiro = NULL;
}
ListaEnc::~ListaEnc()
{
	if(this->primeiro != NULL)
		delete[] this->primeiro;
	free(this);
}
void ListaEnc::insere(int valor)
{
	Nodo *n = new Nodo(valor);
	this->tam++;
	if(this->primeiro == NULL)
		this->primeiro = n;
	else
	{
		Nodo *aux = this->primeiro;
		if(this->primeiro != NULL)
		{
			while(aux->prox != NULL)
				aux = aux->prox;
			aux->prox = n;
		}
		else
			this->primeiro = n;
	}
}
void ListaEnc::imprime()
{
	printf("%i(", this->tam);
	Nodo *aux = this->primeiro;
	while(aux != NULL)
	{
		printf("%i", aux->info);
		aux = aux->prox;
		if(aux != NULL)
			printf(",");
	}
	printf(")");
}
int ListaEnc::procurar(int num, int i)
{
	if(this->primeiro != NULL)
		return this->primeiro->procurar(num, i);
	else
		return 0;
}