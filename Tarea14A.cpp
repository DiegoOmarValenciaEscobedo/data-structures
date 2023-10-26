#include<iostream>
using namespace std;
template<class T>
class Pila{
	private: T Arreglo[6];
		int cima;
	public: Pila();
	void Push(T);
	T Pop(void);
	bool PilaLlena(void);
	bool PilaVacia(void);
	void VerPila(void);
};
template<class T>
Pila<T>::Pila(){
	cima = -1;
}
template<class T>
bool Pila<T>::PilaLlena(void){
	return (cima == (5));
}
template<class T>
bool Pila<T>::PilaVacia(void){
	return (cima == -1);
}
template<class T>
void Pila<T>::Push(T v){
	Arreglo[++cima] = v;
}
template<class T>
T Pila<T>::Pop(void){
	return Arreglo[cima--];
}
template<class T>
void Pila<T>::VerPila(void){
	int aux=cima;
	do{
		cout<<Arreglo[aux--]<<"\t";
	}while(aux>= 0);
}
int main(){
	char op;
	int valor;
   	Pila<int> p1;
	do{
		cout<<"\n1 Apilar valor"<<endl;
		cout<<"2 Desapilar valor"<<endl;
		cout<<"3 Mostrar"<<endl;
		cout<<"4 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':	if(p1.PilaLlena()) cout<<"La pila esta llena"<<endl;
					 else{cout<<"Ingresa el numero: "; cin>>valor;p1.Push(valor);}
				break;
			case '2':if(p1.PilaVacia()) cout<<"La pila esta vacia"<<endl;
					 else cout<<"Se ha  desapilado el valor: "<<p1.Pop()<<endl;
				break;
			case '3':if(p1.PilaVacia()) cout<<"La pila esta vacia"<<endl;
					 else p1.VerPila();
				break;
			case '4':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '4');
}
