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
	cout<<"se ha insertado el valor "<<v<<endl;
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
int main(){
	int valor;
	char op;
	Cola<int> c1;
	do{
		cout<<"1 Ingresar valor"<<endl;
		cout<<"2 Eliminar valor"<<endl;
		cout<<"3 Mostrar Cola"<<endl;
		cout<<"4 Mostrar el inicio de la cola"<<endl;
		cout<<"5 Salir"<<endl;
		cout<<".-"<<endl;
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el valor: "; cin>>valor;
				c1.Put(valor);
				break;
			case '2':if(c1.Vacia())cout<<"La cola esta vacia"<<endl;
				else cout<<"Se ha eliminado el valor: "<<c1.Get()<<endl;
				break;
			case '3':if(c1.Vacia())cout<<"La cola esta vacia"<<endl;
				else c1.Ver();
				break;
			case '4':if(c1.Vacia())cout<<"La cola esta vacia"<<endl;
				else cout<<"El inicio de la cola es: "<<c1.VerIni()<<endl;
				break;
			case '5':cout<<"Has salido de la aplicacion"<<endl;
				break;
			default: cout<<"Opcion invalida"<<endl;
		}
		cout<<"\n"<<endl;
	}while(op != '5');
}
