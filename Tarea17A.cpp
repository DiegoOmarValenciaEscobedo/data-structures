#include<iostream>
#include "Pila.h"
using namespace std;
int main(){
	char op, valor;
	int ind, ind2;
	Pila<char> pila[3];
	do{
		cout<<"1 Insertar\n2 Eliminar\n3 Mover caracter\n4 Ver pilas\n5 salir\n.-";cin>>op;
		switch(op){
			case '1':
			do{
				cout<<"¿A cual pila vas a insertar el caracter? 1, 2 o 3:  "; cin>>ind;	
			}while(ind<1 || ind>3);
			cout<<"Ingresa el caracter a insertar: "; cin>>valor;
			pila[ind-1].Push(valor);
			cout<<"El caracter "<<valor<<" se ha agregado a la pila "<<ind<<endl;
				break;
			case '2':
			do{
				cout<<"¿A cual pila vas a eliminar el caracter? 1, 2 o 3:  "; cin>>ind;	
			}while(ind<1 || ind>3);
			cout<<"El caracter "<<pila[ind-1].Pop()<<" se ha eliminado de la pila "<<ind<<endl;
				break;
			case '3':
			do{
				cout<<"¿A cual pila vas a extraer el caracter? 1, 2 o 3:  "; cin>>ind;	
			}while(ind2<1 || ind2>3);
			do{
				cout<<"¿A cual pila vas a insertar el caracter? 1, 2 o 3:  "; cin>>ind2;	
			}while(ind<1 || ind>3);	
			if(ind == ind2) cout<<"La pila de origen y de destino es la misma"<<endl;
			else if(pila[ind-1].Vacia())cout<<"La pila "<<ind<<" no tiene elementos para mover"<<endl;
			else{
				pila[ind2-1].Push(pila[ind-1].Pop());
				cout<<"Se ha movido el caracter de la pila "<<ind<<" a la pila"<<ind2<<endl;	
			} 
				break;
			case '4':
				if(pila[0].Vacia()){
					cout<<"Pila 1\n vacia"<<endl;
				}else{
					cout<<"Pila 1\n";
					pila[0].Ver();
				}
				if(pila[1].Vacia()){
					cout<<"Pila 2\n vacia"<<endl;
				}else{
					cout<<"Pila 2\n";
					pila[1].Ver();
				}
				if(pila[2].Vacia()){
					cout<<"Pila 3\n vacia"<<endl;
				}else{
					cout<<"Pila 3\n";
					pila[2].Ver();
				}
				break;
			case '5':cout<<"Has salido de la aplicacion"<<endl;
				break;
			default: cout<<"Opcion invalida"<<endl;
		}
	}while(op != '5')	;
}
