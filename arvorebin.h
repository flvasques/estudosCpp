
#ifndef ARVOREBIN
#define ARVOREBIN
#include "listaenc.h"
class No
{
	public:
		ListaEnc *valor;
		No *esq;
		No *dir;
		No(ListaEnc *v);
		void insere(ListaEnc *v);
		void imprimePre();
		void imprimePos();
		void imprimeEm();
		int buscar(int num);
	private:
		int count();
};
#endif