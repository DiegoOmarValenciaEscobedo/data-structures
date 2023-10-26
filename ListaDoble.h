#include<iostream>
using namespace std;
template <class T>
struct Nodo{
	T info;
	Nodo <T> *sig, *ant;
	Nodo(T);
};
template <class T>
Nodo<T>::Nodo(T v){
	info = v;
	sig = ant = NULL;
}
template<class T>
class Lista{
	private: Nodo<T> *ini, *fin;
	public: 
	Lista();
	void ins_ini(T);
	void ins_fin(T);
	T Eli_ini();
	T Eli_fin();
	void ver();
	void ver_inver();
	bool vacia();	
};
template<class T>
Lista<T>::Lista(){
	ini = NULL;
	fin = NULL;
}
template<class T>
void Lista<T>::ins_ini(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(vacia()){
		ini=nvo;
		fin=nvo;
	}else{
		nvo->sig = ini;
		ini->ant = nvo;
		ini = nvo; 
	}
}
template<class T>
void Lista<T>::ins_fin(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(vacia()){
		ini =nvo; 
		fin =nvo;
	}
	else{
		nvo->ant=fin;
		fin->sig =nvo;
		fin = nvo;
	}
}
template<class T>
T Lista<T>::Eli_ini(){
	Nodo<T> *sale= ini;
	if(ini->sig == NULL){
		ini = fin = NULL;
	}else{	
		ini = sale->sig;
		ini->ant = NULL;
	}
	T val = sale->info;
		delete(sale);
		return val;
}
template<class T>
T Lista<T>::Eli_fin(){
	Nodo<T> *sale = fin;
	if(ini->sig == NULL) ini =fin= NULL;
	else{
		fin = sale->ant;
		fin->sig = NULL;
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
void Lista<T>::ver_inver(){
	Nodo<T> *actual;
	actual = fin;
		while(actual){	
			cout<<"\t"<<actual->info;
			actual = actual->ant;
		}
		cout<<endl;
}
