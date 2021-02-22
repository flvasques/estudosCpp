
#ifndef ARVOREBIN
#define ARVOREBIN
class No
{
	public:
		int valor;
		No *esq;
		No *dir;
		No *pai;
		No(int v);
		No(int v, No *pai);
		~No();
		void insere(int v);
		void insere(No *no);
		void imprimePre();
		void imprimePos();
		void imprimeEm();
		int buscar(int num);
		void remover(int num);
	private:
		int count(int num, int i);
};
#endif