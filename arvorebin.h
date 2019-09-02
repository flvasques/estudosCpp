
#ifndef ARVOREBIN
#define ARVOREBIN
#include "listaenc.h"
class No
{
	public:
		ListaEnc *valor;
		No *esq;
		No *dir;
		No *pai;
		No(ListaEnc *v);
		No(ListaEnc *v, No *pai);
		~No();
		void insere(ListaEnc *v);
		void imprimePre();
		void imprimePos();
		void imprimeEm();
		int buscar(int num);
	private:
		int count(int num, int i);
};
#endif