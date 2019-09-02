#ifndef LISTAENC
#define LISTAENC
#include "nodo.h"
class ListaEnc
{
	public:
		Nodo *primeiro;
		int tam;
		ListaEnc();
		~ListaEnc();
		void insere(int valor);
		int procurar(int num, int i);
		void imprime();
	private:	
};
#endif