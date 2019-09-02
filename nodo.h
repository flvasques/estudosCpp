#ifndef NODO
#define NODO
class Nodo
{
	public:
		int info;
		Nodo *prox;
		Nodo(int valor);
		~Nodo();
		Nodo *proximo();
		int procurar(int num, int i);
	private:
		
};
#endif