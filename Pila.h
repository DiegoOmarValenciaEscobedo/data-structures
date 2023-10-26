#include "Nodo.h"
#include<iostream>
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
		cout<<actual->info<<" ";
		actual = actual->sig;
	}
	cout<<"\n"<<endl;
}
