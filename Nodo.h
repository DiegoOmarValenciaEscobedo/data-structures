#include<iostream>
using namespace std;
template<class T>
struct Nodo{
	T info;
	Nodo<T> *sig;
	Nodo(T);
};
template<class T>
Nodo<T>::Nodo(T v){
	info = v;
	sig = NULL;
}
