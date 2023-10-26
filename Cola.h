#include "Nodo.h"
template<class T>
class Cola{
	private: Nodo<T> *ini;
	public: Cola();
	void Put(T);
	T Get();
	void Ver();
	T VerIni();
	bool Vacia();
};
template<class T>
Cola<T>::Cola(){
	ini = NULL;
}
template<class T>
void Cola<T>::Put(T v){
	Nodo<T> *nvo = new Nodo<T>(v);
	if(Vacia()){
		nvo->sig = ini;
		ini = nvo;
	}else{	
		Nodo<T> *act;
		act = ini;
		while(act->sig != NULL){
			act = act->sig;
		}
		act->sig = nvo;
	} 
}
template<class T>
T Cola<T>::Get(){
	Nodo<T> *sale = ini;
	ini = ini->sig;
	T valor = sale->info;
	delete sale;
	return valor; 
}
template<class T>
T Cola<T>::VerIni(){
	return ini->info;
}
template<class T>
bool Cola<T>::Vacia(){
	return (ini == NULL);
}
template<class T>
void Cola<T>::Ver(){
	Nodo<T> *actual = ini;
	while(actual){
		cout<<actual->info<<"\t";
		actual = actual->sig;
	}
}
