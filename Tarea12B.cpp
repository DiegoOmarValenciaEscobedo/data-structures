#include<iostream>
using namespace std;
struct Persona{
	int Clave;
	string Nombre;
	float Sueldo;
};
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
	if(Vacia() || ini->info.Clave > v.Clave){
		nvo->sig = ini;
		ini = nvo;
		cout<<"Se ha registrado a la persona con la clave "<<v.Clave<<endl;
	}else{
		Nodo<T> *ant, *tmp=ini;
		while(tmp->sig && tmp->info.Clave<v.Clave){
			ant = tmp;
			tmp = tmp->sig;	
		}
		if(tmp->info.Clave == v.Clave){
			cout<<"La clave " <<v.Clave<<" ya se ha ingresado"<<endl;
		}else{
			if(tmp->info.Clave <v.Clave){
				tmp->sig = nvo;
			}else{
				nvo->sig = ant->sig;
				ant->sig = nvo;
			}
		cout<<"Se ha insertado el valor "<<v.Clave<<endl;
		}
	}
}
template<class T>
T Lista<T>::Eliminar(T v){
	Nodo<T> *tmp, *ant;
	ant = ant = ini;
	while(tmp && tmp->info.Clave < v.Clave){
		ant = tmp;
		tmp = tmp->sig;
	}
	if(!tmp || tmp->info.Clave != v.Clave){
		cout<<"El valor "<<v.Clave<<" no se encuentra en la lista"<<endl;
	}else{
		if(tmp == ini){
			ini = tmp->sig;
		}else{
			ant->sig =tmp->sig;
		}
		delete tmp;
		cout<<"Se ha eliminado el valor "<<v.Clave<<endl;
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
			cout<<"\t"<<actual->info.Clave<<"\t"<<actual->info.Nombre<<"\t"<<actual->info.Sueldo<<endl;
			actual = actual->sig;
		}
		cout<<endl;
}
int main(){
	char op;
	Lista<Persona> l1;
	Persona p1;
	do{
		cout<<"\n1 Insertar"<<endl;
		cout<<"2 Eliminar"<<endl;
		cout<<"3 Mostrar"<<endl;
		cout<<"4 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa la clave: "; cin>>p1.Clave;
					 cout<<"Ingresa el nombre: "; cin>>p1.Nombre;
					 cout<<"Ingresa el sueldo: "; cin>>p1.Sueldo;
					 l1.Insertar(p1);
				break;
			case '2':cout<<"Ingresa la clave de la persona a eliminar: "; cin>>p1.Clave;
					l1.Eliminar(p1);
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
