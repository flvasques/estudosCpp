#ifndef ARVOREAVL
#define ARVOREAVL
class NoAVL
{
	public:
		int valor;
		NoAVL *raiz;
		NoAVL *esq;
		NoAVL *dir;
		int fatBal;
		NoAVL(int v);
		NoAVL(int v, NoAVL *pai);
		~NoAVL();
		void insere(int elem, bool status);
		void imprimePre();
		void imprimePos();
		void imprimeEm();
		void insere(NoAVL *no);
		void remover(int num);
		int buscar(int num);
		int altura();
	private:
		void rotacionarDir(NoAVL *a, bool status);
		void rotacionarEsq(NoAVL *a, bool status);
};
#endif