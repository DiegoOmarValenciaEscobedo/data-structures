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
int main(){
	char op;
	int valor;
   	Lista<int> l1;
   	cout<<"-----Lista simple circular-----"<<endl;
	do{ fflush(stdin);
		cout<<"\n1 insertar"<<endl;
		cout<<"2 eliminar"<<endl;
		cout<<"3 buscar"<<endl;
		cout<<"4 mostrar"<<endl;
		cout<<"5 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el valor entero: "; cin>>valor;
					l1.Insertar(valor);
				break;
			case '2':if(l1.Vacia()) cout<<"La lista esta vacia"<<endl;
					else cout<<"se elimino dato: "<<	l1.Eliminar();
				break;
			case '3':cout<<"ingresa el valor a buscar: "; cin>>valor;
					l1.Buscar(valor);
				break;
			case '4': if(l1.Vacia()) cout<<"La lista esta vacia"<<endl;
					else l1.Ver();
				break;
			case '5': cout<<"has salido de la aplicacion";
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '5');
}
