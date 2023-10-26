#include<iostream>
#include "Nodo.h"
using namespace std;
template<class T>
class Lista{
	private: Nodo<T> *ini;
	public: 
	Lista();
	void ins_ini(T);
	void ins_fin(T);
	T Eli_ini();
	T Eli_fin();
	void ver();
	bool vacia();	
};
template<class T>
Lista<T>::Lista(){
	ini = NULL;
}
template<class T>
void Lista<T>::ins_ini(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	nvo->sig = ini;
	ini=nvo;
}
template<class T>
void Lista<T>::ins_fin(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(vacia()) ini =nvo;
	else{
		Nodo<T> *tem = ini;
		while(tem->sig != NULL){tem = tem->sig;}
		tem->sig = nvo;
	}
}
template<class T>
T Lista<T>::Eli_ini(){
	Nodo<T> *sale;
	sale = ini;
	ini = sale->sig;
	T val = sale->info;
	delete(sale);
	return val;
}
template<class T>
T Lista<T>::Eli_fin(){
	Nodo<T> *sale = ini, *aux;
	if(ini->sig == NULL) ini = NULL;
	else{
		while(sale->sig != NULL){
			aux = sale;
			sale = sale->sig;
		}
		aux->sig = NULL;
	}
	T val = sale->info;
	delete(sale);
	return val;
}
template<class T>
bool Lista<T>::vacia(){
	return ini==NULL;
}
template<class T>
void Lista<T>::ver(){
	Nodo<T> *actual;
	actual = ini;
		while(actual){	
			cout<<"\t"<<actual->info;
			actual = actual->sig;
		}
		cout<<endl;
	}
template<class T>
void invertir(Lista<T> &l){
	Lista<T> t;
	while(!l.vacia()){
		t.ins_fin(l.Eli_fin());
	}
	while(! t.vacia()){
		l.ins_fin(t.Eli_ini());
		
	}
}
