#include<iostream>
using namespace std;
template <class T>
struct Nodo{
	T info;
	Nodo <T> *sig;
	Nodo(T);
};
template <class T>
Nodo<T>::Nodo(T v){
	info = v;
	sig = NULL;
}
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
int main(){
	char op;
	int valor;
   	Lista<int> l1;
   	cout<<"-----Lista simple Ordenada-----"<<endl;
	do{
		cout<<"\n1 Insertar"<<endl;
		cout<<"2 Eliminar"<<endl;
		cout<<"3 Mostrar"<<endl;
		cout<<"4 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el numero: "; cin>>valor;
					l1.Insertar(valor);
				break;
			case '2':cout<<"Ingresa el numero a eliminar: "; cin>>valor;
					l1.Eliminar(valor);
				break;
			case '3':if(l1.Vacia()) cout<<"La lista esta vacia"<<endl;
					else l1.Ver();
				break;
			case '4':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '4');
}
