#include<iostream>
using namespace std;
template<class T>
class Cola{
	private: T Arreglo[6];
		int ini, fin;
	public: Cola();
	void Put(T);
	T Get(void);
	bool ColaLlena(void);
	bool ColaVacia(void);
	void VerCola(void);
};
template<class T>
Cola<T>::Cola(){
	ini=fin=0;
}
template<class T>
bool Cola<T>::ColaLlena(void){
	return ((fin+1)%6 == ini);
}
template<class T>
bool Cola<T>::ColaVacia(void){
	return (ini == fin);
}
template<class T>
void Cola<T>::Put(T v){
	Arreglo[fin] = v;
	fin = (fin+1)%6;
}
template<class T>
T Cola<T>::Get(void){
	T sale= Arreglo[ini];
	ini = (ini+1)%6;
	return sale;
}
template<class T>
void Cola<T>::VerCola(void){
	int aux=ini;
	do{
		cout<<Arreglo[aux]<<"\t";
		aux = (aux+1)%6;
	}while(aux!= fin);
}
int main(){
	char op;
	int valor;
    Cola<int> c1;
	do{
		cout<<"\n1 insertar valor"<<endl;
		cout<<"2 eliminar valor"<<endl;
		cout<<"3 Mostrar cola"<<endl;
		cout<<"4 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':	if(c1.ColaLlena()) cout<<"La cola esta llena"<<endl;
					 else{cout<<"Ingresa el numero: "; cin>>valor;c1.Put(valor);}
				break;
			case '2':if(c1.ColaVacia()) cout<<"La cola esta vacia"<<endl;
					 else cout<<"Se ha sacado el valor: "<<c1.Get()<<endl;
				break;
			case '3':if(c1.ColaVacia()) cout<<"La cola esta vacia"<<endl;
					 else c1.VerCola();
				break;
			case '4':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '4');
}
