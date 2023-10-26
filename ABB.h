#include<iostream>
using namespace std;
template<class T>
struct NodoArbol{
	NodoArbol<T> *HD;	
	NodoArbol<T> *HI;
	T info;
	public: NodoArbol(T);
};
template<class T>
NodoArbol<T>::NodoArbol(T v){
	HD = HI = NULL;
	info = v;
}
	template<class T>
	class Arbol{
		public: NodoArbol<T> *raiz;
		public: Arbol();
		void Insertar(NodoArbol<T> *&temp,T);
		void Eliminar(NodoArbol<T> *&padre, NodoArbol<T> *&hijo,T);
		void Buscar(NodoArbol<T> *&tmp, T);
		void Pre(NodoArbol<T> *&tmp);
		void In(NodoArbol<T> *&tmp);
		void Post(NodoArbol<T> *&tmp);
		T RemplazoI(NodoArbol<T> *&tmp);
	};
template<class T>
Arbol<T>::Arbol(){
	raiz = NULL;
}
template<class T>
void Arbol<T>::Insertar(NodoArbol<T> *&temp, T v){
	NodoArbol<T> *nvo = new NodoArbol<T>(v);
	if(raiz == NULL){
		raiz =nvo;
		cout<<"Se ha insertado el nodo como raiz"<<endl;	
	}else if(temp == NULL){
		 temp = nvo;
		cout<<"Se ha insertado el nodo"<<endl;	
	}else{
		if(nvo->info < temp->info){
			Insertar(temp->HI, v);
		}else if(nvo->info > temp->info){
			Insertar(temp->HD, v);
		}else if(nvo->info == v) cout<<"El nodo ya existe"<<endl;
	}
}
template<class T>
void Arbol<T>::Buscar(NodoArbol<T> *&tmp, T v){
	if(raiz == NULL) cout<<"El arbol esta vacio"<<endl;
	else if(v == raiz->info) cout<<"El valor buscado es la raiz del arbol"<<endl;
	else if(tmp == NULL){
		cout<<"\nNo se encontro el valor buscado"<<endl;
	}else{
		if(v==tmp->info) cout<<"\nEl valor buscado si existe en el arbol"<<endl;
		else if(v < tmp->info){
			cout<<"-"<<tmp->info;
			Buscar(tmp->HI, v);
		}else if(v > tmp->info){
			cout<<"-"<<tmp->info;
			Buscar(tmp->HD, v);
		}
	}
}
template<class T>
void Arbol<T>::Eliminar(NodoArbol<T> *&padre, NodoArbol<T> *&hijo, T v){
	if(raiz == NULL){
		cout<<"El arbol esta vacio"<<endl;
	}else if(hijo ==NULL){
		cout<<"El nodo no existe en el arbol"<<endl;
	}else if(hijo->info != v){
		if(v < hijo->info) Eliminar(hijo, hijo->HI, v);
		if(v > hijo->info) Eliminar(hijo, hijo->HD, v);
	}else{
		if(!hijo->HD && !hijo->HI){
			if(padre->HD == hijo){
				padre->HD = NULL;
				delete hijo;
				cout<<"Se elimino el nodo"<<endl;
			}else if(padre->HI == hijo){
				padre->HI = NULL;
				delete hijo;
				cout<<"Se elimino el nodo hoja"<<endl;
			}else if(hijo == raiz){
				cout<<"Se elimino la raiz del arbol\nArbol vacio"<<endl;
				raiz=NULL;
				delete padre; delete hijo;
			}
		}else if(hijo->HD && hijo->HI){
			T aux = RemplazoI(hijo->HD);
			hijo->info = aux;
			cout<<"Se elimino el nodo con 2 hijos"<<endl;
		}else if(!hijo->HD || !hijo->HI){
			if(padre->HD == hijo){
				if(!hijo->HD){
					hijo = hijo->HI;
					hijo->HI = NULL;
				}else if(!hijo->HI){
					hijo = hijo->HD;
					hijo->HD = NULL;
				}
			}else if(padre->HI == hijo){
				if(!hijo->HD){
					hijo = hijo->HI;
					hijo->HI = NULL;
				}else if(!hijo->HI){
					hijo = hijo->HD;
					hijo->HD = NULL;
				}
			}else if(padre == hijo){
				if(!hijo->HD){
					hijo = hijo->HI;
					hijo->HI = NULL;
					raiz = hijo;
				}else if(!hijo->HI){
					hijo = hijo->HD;
					hijo->HD = NULL;
					raiz = hijo;
				}
			}
		cout<<"Se elimino el nodo con 1 hijo"<<endl;
		}
	}
}
template<class T>
void Arbol<T>::Pre(NodoArbol<T> *&tmp){
	if(raiz == NULL)cout<<"El arbol esta vacio"<<endl;
	else if(tmp != NULL){
		cout<<"\t"<<tmp->info;
		Pre(tmp->HI);
		Pre(tmp->HD);
	}
}
template<class T>
void Arbol<T>::In(NodoArbol<T> *&tmp){
	if(raiz == NULL)cout<<"El arbol esta vacio"<<endl;
	else if(tmp){
		In(tmp->HI);
		cout<<"\t"<<tmp->info;
		In(tmp->HD);
	}
}
template<class T>
void Arbol<T>::Post(NodoArbol<T> *&tmp){
	if(raiz == NULL)cout<<"El arbol esta vacio"<<endl;
	else if(tmp != NULL){
		Post(tmp->HI);
		Post(tmp->HD);
		cout<<"\t"<<tmp->info;
	}
}
template<class T>
T Arbol<T>::RemplazoI(NodoArbol<T> *&tmp){
	if(tmp == NULL) return 0;
	else if(tmp->HI) RemplazoI(tmp->HI);
	else{
		T aux = tmp->info;
		Eliminar(raiz, raiz, aux);
		return aux;	
	} 
}
