#include<iostream>
#include "cola.h"
using namespace std;
Cola<int> c1;
int cont=1;
void convertir(int x){//va convirtiendo el indice en binario y lo agrega a una cola llamada c1
	if(x==0){
	}else if(x==1){
		c1.Put(1);
	}else{
		convertir(x/2);
		if(x%2 == 0) c1.Put(0);
		else if(x%2 == 1) c1.Put(1);
	}
}
template<class T>
struct NodoHeap{
	NodoHeap<T> *HD;	
	NodoHeap<T> *HI;
	NodoHeap<T> *Padre;
	T info;
	public: NodoHeap(T);
};
template<class T>
NodoHeap<T>::NodoHeap(T v){
	HD = HI = Padre = NULL;
	info = v;
}
template<class T>
class Heap{
	public: NodoHeap<T> *cima;
	public: Heap();
	void Insertar(NodoHeap<T> *&pa, NodoHeap<T> *&tmp,T);
	void OrdenarInsercion(NodoHeap<T> *&padre, NodoHeap<T> *&hijo);
	void Eliminar(NodoHeap<T> *&tmp);
	T NodoReemplazar(NodoHeap<T> *&padre, NodoHeap<T> *&hijo);
	void OrdenarEliminacion(NodoHeap<T> *&tmp);
	void Mostrar(NodoHeap<T> *&tmp);
};
template<class T>
Heap<T>::Heap(){
	cima = NULL;
}
template<class T>
void Heap<T>::Insertar(NodoHeap<T> *&pa, NodoHeap<T> *&tmp, T v){
	NodoHeap<T> *nvo = new NodoHeap<T>(v);
	int aux=3;//valor cualquiera para que no entre en ningun caso si es que esta vacia la cola
	if(!c1.Vacia()) aux = c1.Get();	
	
	if(cont == 1){//si es el primer valor a insertar lo inserta en la cima
		cout<<"Nodo insertado en la cima"<<endl;
		cima=nvo;
		cont++;
	}else{
		if(aux == 1){//si el indice binario es 1 se va por la derecha
			cout<<"Derecha"<<endl;
			Insertar(tmp, tmp->HD, v);
		}else if(aux == 0){//si el indice binario es 0 se va por la izquierda
			cout<<"Izquierda"<<endl;
			Insertar(tmp, tmp->HI, v);
		}else if(c1.Vacia()){//si ya se vacio la pila lo inserta en la posicion de tmp
			tmp = nvo;
			tmp->Padre = pa;
			cont++;
			cout<<"Nodo insertado"<<endl;
			OrdenarInsercion(tmp->Padre, tmp);
		}
	}
}
template<class T>
void Heap<T>::Mostrar(NodoHeap<T> *&tmp){
	if(cima == NULL || cont==1)cout<<"El arbol esta vacio"<<endl;
	else if(tmp != NULL){
		if(tmp->info != 0)cout<<"\t"<<tmp->info;
		Mostrar(tmp->HI);
		Mostrar(tmp->HD);
	}
}
template<class T>
void Heap<T>::Eliminar(NodoHeap<T> *&tmp){
	convertir(cont-1);//convierte a binario el contador para mandarlo a nodoreemplazar
	c1.Get();//se elimina el primer uno que es el de la raiz
	T a = NodoReemplazar(tmp, tmp);
	tmp->info = a;//se reemplaza la informacion del nodo final en la cima
	OrdenarEliminacion(tmp);//se ordena la nueva cima;
}
template<class T>
T Heap<T>::NodoReemplazar(NodoHeap<T> *&padre, NodoHeap<T> *&hijo){
	int aux=3;//valor cualquiera
	if(!c1.Vacia()){
		aux = c1.Get();
		if(aux == 1){//si el indice binario es 1 se va por la derecha
		NodoReemplazar(hijo, hijo->HD);
		}else if(aux == 0){//si el indice binario es 0 se va por la izquierda
		NodoReemplazar(hijo, hijo->HI);
		}
	}else{//si ya se vacio la pila retorna la informacion del nodo actual
		T ret = hijo->info;
		if(cont == 2){
			return 0;	
		}else if(padre->HD == hijo) padre->HD = NULL;//para que el hijo derecho de padre apunte a null
		else if(padre->HI == hijo) padre->HI = NULL;//hijo izquierdo de padre apuntara a null
		cont--;
		cout<<"Nodo Eliminado"<<endl;
		if(cont == 1) cout<<"El heap se ha quedado vacio"<<endl;
		delete hijo;
		return ret;
	}
}
template<class T>
void Heap<T>::OrdenarEliminacion(NodoHeap<T> *&tmp){
	T aux, cambio;
	if(!tmp->HD && !tmp->HI) cout<<endl;//si el nodo no tiene hijos esta ordenado
	else if(!tmp->HD && tmp->HI) aux = tmp->HI->info;//si solo tiene hijo derecho se le asigna a aux
	else if(!tmp->HI && tmp->HD) aux = tmp->HD->info;//si solo tiene hijon izquierdo de le asigna a aux
	else if(tmp->HD->info < tmp->HI->info) aux = tmp->HI->info;//si tiene los 2 hijos pero izquierdo es mayor que derecho, derecho se le asigna a aux
	else if(tmp->HD->info > tmp->HI->info) aux = tmp->HD->info;//si tiene 2 hijos pero el derecho es mayor, izquierdo se asigna a aux
	
	if((tmp->HD || tmp->HI) && (aux> tmp->info)){//si tiene algun hijo y alguno de los 2 es mayor entonces entra en intercambio
		if(tmp->HD->info == aux){
			cambio = tmp->info;
			tmp->info = tmp->HD->info;
			tmp->HD->info = cambio;
			OrdenarEliminacion(tmp->HD);
		}else if(tmp->HI->info == aux){
			cambio = tmp->info;
			tmp->info = tmp->HI->info;
			tmp->HI->info = cambio;
			OrdenarEliminacion(tmp->HI);
		}
		
	}else cout<<endl;
}
template<class T>
void Heap<T>::OrdenarInsercion(NodoHeap<T> *&padre, NodoHeap<T> *&hijo){
	T cambio;
	if(hijo->info > padre->info){
		cambio = padre->info;
		padre->info = hijo->info;
		hijo->info = cambio;
		if(padre->Padre)OrdenarInsercion(padre->Padre, padre);
	}else cout<<endl;
}
int main(){
	char op;
	int valor;
	Heap<int> H1;
	do{
		cout<<"1. Ingresar"<<endl;
		cout<<"2. Eliminar"<<endl;
		cout<<"3. Mostrar monticulo"<<endl;
		cout<<"4. salir"<<endl;
		cout<<": "; cin>>op;
		switch(op){
			case '1': cout<<"Ingresa el valor del nodo: "; cin>>valor;
					convertir(cont);//convierte el contador a binario
					c1.Get();//Extrae el primer uno para no tomar la derecha primero
					H1.Insertar(H1.cima, H1.cima, valor);
				break;
			case '2':
					H1.Eliminar(H1.cima);
				break;
			case '3': H1.Mostrar(H1.cima);
				break;
			case '4':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default: cout<<"Opcion invalida"<<endl;
		}
		cout<<endl;
	}while(op != '4');
}
