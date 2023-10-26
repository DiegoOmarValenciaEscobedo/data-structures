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

int main(){
	char op;
	int valor;
   	Lista<int> l1;
   	cout<<"-----Lista simple enlazada-----"<<endl;
	do{
		cout<<"\n1 insertar al inicio"<<endl;
		cout<<"2 insertar al final"<<endl;
		cout<<"3 eliminar al inicio"<<endl;
		cout<<"4 eliminar al final"<<endl;
		cout<<"5 mostrar los elementos"<<endl;
		cout<<"6 invertir los elementos"<<endl;
		cout<<"7 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el valor entero: "; cin>>valor;
					l1.ins_ini(valor);
				break;
			case '2':cout<<"Ingresa el valor entero: "; cin>>valor;
					l1.ins_fin(valor);
				break;
			case '3':if(l1.vacia()) cout<<"La lista esta vacia"<<endl;
					else cout<<"se elimino dato: "<<	l1.Eli_ini();
				break;
			case '4':if(l1.vacia()) cout<<"La lista esta vacia"<<endl;
					else cout<<"se elimino dato: "<<	l1.Eli_ini();
				break;
			case '5':if(l1.vacia()) cout<<"La lista esta vacia"<<endl;
					else l1.ver();
				break;
			case '6': invertir(l1); cout<<"Se invirtio la lista"<<endl;
				break;
			case '7': cout<<"has salido de la aplicacion";
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '7');
}
