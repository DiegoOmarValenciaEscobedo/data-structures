#include<iostream>
#include "Nodo.h"
using namespace std;
template<class T>
class Pila{
	private: Nodo<T> *cima;
	public: Pila();
	void Push(T);
	T Pop();
	void Ver();
	T VerCima();
	bool Vacia();
};
template<class T>
Pila<T>::Pila(){	
	cima = NULL;
}
template<class T>
void Pila<T>::Push(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	nvo->sig = cima;
	cima = nvo;
	cout<<"se ha apilado el valor "<<v<<endl;
}
template<class T>
T Pila<T>::Pop(){
	Nodo<T> *sale = cima;
	cima = cima->sig;
	T valor = sale->info;
	delete sale;
	return valor; 
}
template<class T>
T Pila<T>::VerCima(){
	return cima->info;
}
template<class T>
bool Pila<T>::Vacia(){
	return (cima == NULL);
}
template<class T>
void Pila<T>::Ver(){
	Nodo<T> *actual = cima;
	while(actual){
		cout<<actual->info<<"\t";
		actual = actual->sig;
	}
	cout<<"\n"<<endl;
}
int main(){
	int valor;
	char op;
	Pila<int> p1;
	do{
		cout<<"1 Apilar valor"<<endl;
		cout<<"2 Desapilar valor"<<endl;
		cout<<"3 Mostrar valor"<<endl;
		cout<<"4 Mostrar cima de la pila"<<endl;
		cout<<"5 Salir"<<endl;
		cout<<".-"<<endl;
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el valor a apilar: "; cin>>valor;
				p1.Push(valor);
				break;
			case '2':if(p1.Vacia())cout<<"La pila esta vacia"<<endl;
				else cout<<"Se ha desapilado el valor: "<<p1.Pop()<<endl;
				break;
			case '3':if(p1.Vacia())cout<<"La pila esta vacia"<<endl;
				else p1.Ver();
				break;
			case '4':if(p1.Vacia())cout<<"La pila esta vacia"<<endl;
				else cout<<"La cima de la cima es: "<<p1.VerCima()<<endl;
				break;
			case '5':cout<<"Has salido de la aplicacion"<<endl;
				break;
			default: cout<<"Opcion invalida"<<endl;
		}
		cout<<"\n"<<endl;
	}while(op != '5');
}
