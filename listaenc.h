#ifndef LISTAENC
#define LISTAENC
#include "nodo.h"
class ListaEnc
{
	public:
		Nodo *primeiro;
		int tam;
		ListaEnc();
		void insere(int valor);
		void imprime();
	private:	
};
#endif