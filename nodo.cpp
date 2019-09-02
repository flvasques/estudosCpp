#include <iostream>
#include "nodo.h"
Nodo::Nodo(int valor)
{
	this->info = valor;
	this->prox = NULL;
}
Nodo::~Nodo()
{
	if(prox != NULL)
		this->prox->~Nodo();
	else
		free(this);
}
Nodo* Nodo::proximo()
{
	return this->prox;
}
int Nodo::procurar(int num, int i)
{
	if(num == this->info)
		i++;
	if(this->prox != NULL)
		return this->prox->procurar(num, i);
	else
		return i;
}