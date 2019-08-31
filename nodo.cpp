#include <iostream>
#include "nodo.h"
Nodo::Nodo(int valor)
{
	this->info = valor;
	this->prox = NULL;
}
Nodo* Nodo::proximo()
{
	return this->prox;
}