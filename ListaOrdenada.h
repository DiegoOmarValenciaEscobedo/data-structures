#include<iostream>
#include "Nodo.h"
using namespace std;
template<class T>
class Lista{
	private: Nodo<T> *ini;
	public: 
	Lista();
	void Insertar(T);
	T Eliminar(T);
	void Ver();
	bool Vacia();	
};
template<class T>
Lista<T>::Lista(){
	ini = NULL;
}
template<class T>
void Lista<T>::Insertar(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(Vacia() || ini->info > v){
		nvo->sig = ini;
		ini = nvo;
		cout<<"Valor "<<v<<" insertado al inicio"<<endl;
	}else{
		Nodo<T> *ant, *tmp=ini;
		while(tmp->sig && tmp->info<v){
			ant = tmp;
			tmp = tmp->sig;	
		}
		if(tmp->info == v){
			cout<<"El valor " <<v<<" ya esta ingresado"<<endl;
		}else{
			if(tmp->info <v){
				tmp->sig = nvo;
			}else{
				nvo->sig = ant->sig;
				ant->sig = nvo;
			}
		cout<<"Se ha insertado el valor "<<v<<endl;
		}
	}
}
template<class T>
T Lista<T>::Eliminar(T v){
	Nodo<T> *tmp, *ant;
	ant = tmp = ini;
	while(tmp && tmp->info < v){
		ant = tmp;
		tmp = tmp->sig;
	}
	if(!tmp || tmp->info != v){
		cout<<"El valor "<<v<<" no se encuentra en la lista"<<endl;
	}else{
		if(tmp == ini){
			ini = tmp->sig;
		}else{
			ant->sig =tmp->sig;
		}
		delete tmp;
		cout<<"Se ha eliminado el valor "<<v<<endl;
		if(Vacia())cout<<"Lista vacia"<<endl;
	}
}
template<class T>
bool Lista<T>::Vacia(){
	return ini==NULL;
}
template<class T>
void Lista<T>::Ver(){
	Nodo<T> *actual;
	actual = ini;
		while(actual){	
			cout<<"\t"<<actual->info;
			actual = actual->sig;
		}
		cout<<endl;
	}
