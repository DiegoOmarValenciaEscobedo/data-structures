#include<iostream>
#include "Nodo.h"
using namespace std;
template<class T>
class Lista{
	private: Nodo<T> *ini, *fin;
	public: 
	Lista();
	void Insertar(T);
	T Eliminar();
	T Buscar(T);
	void Ver();
	bool Vacia();
		
};
template<class T>
Lista<T>::Lista(){
	ini = fin = NULL;
}
template<class T>
void Lista<T>::Insertar(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(Vacia()){
	ini=nvo; 
	nvo->sig = fin; 
	fin =ini;
	}else{
		nvo->sig=ini;
		ini=nvo;
		fin = ini;
	} 
}
template<class T>
T Lista<T>::Eliminar(){
	Nodo<T> *sale;
	sale = ini;
	ini = sale->sig;
	fin = ini;
	T val = sale->info;
	delete(sale);
	return val;
}
template<class T>
bool Lista<T>::Vacia(){
	return ini==NULL;
}
template<class T>
void Lista<T>::Ver(){
	Nodo<T> *actual;
	actual = ini;
	do{
		cout<<"\t"<<actual->info;
		actual = actual->sig;
	}while(actual);
	cout<<endl;
}
template<class T>
T Lista<T>::Buscar(T v){
	Nodo<T> * aux =ini;
	bool c = false;
	do{
	if(aux->info == v){
		cout<<"Dato encontrado"<<endl; 	c = true;
		break;	
	}
	aux = aux->sig;
	}while(aux);
	if(!c)cout<<"Dato no encontrado"<<endl;
}
