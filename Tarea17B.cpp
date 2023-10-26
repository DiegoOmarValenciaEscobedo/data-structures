#include<iostream>
#include "Pila.h"
#include<math.h>
using namespace std;
Pila<int> pila[3];
void VerPilas();
void Mover ();
int main(){
	int N, movimientos = 0;
	cout<<"Bienvenido al juego de la torres de hanoi"<<endl;
	cout<<"¿cuantos discos vas a usar? ";  cin>>N;
	for(int i=N; i>0; i--) pila[0].Push(i); 
	do{
		VerPilas();
		Mover();
		movimientos++;
	}while(!pila[0].Vacia() || !pila[1].Vacia());
	cout<<"\n\nHas Terminado el juego\n\nNumero minimo de movimientos: "<<pow(2, N)-1<<" \nNumero de movimientos realizados: "<<movimientos<<endl;
}
void Mover (){
	int ind, ind2;
		do{
			cout<<"¿A cual pila vas a extraer el caracter? 1, 2 o 3:  "; cin>>ind;	
		}while(ind<1 || ind>3);
		do{
			cout<<"¿A cual pila vas a insertar el caracter? 1, 2 o 3:  "; cin>>ind2;	
		}while(ind2<1 || ind2>3);	
		int cima1 = pila[ind-1].VerCima(), cima2;
		if(ind == ind2){
			cout<<"La pila de origen y de destino es la misma"<<endl;
		}else if(pila[ind-1].Vacia()){
			cout<<"La pila "<<ind<<" no tiene elementos para mover"<<endl;
		}else{
			if(!pila[ind2-1].Vacia()){
				cima2 = pila[ind2-1].VerCima();
				if(cima1 > cima2){
				cout<<"No se puede mover Un disco mas grande sobre uno mas pequeno"<<endl;
				}else{
					pila[ind2-1].Push(pila[ind-1].Pop());
					cout<<"Se ha movido el caracter de la pila "<<ind<<" a la pila"<<ind2<<endl;	
				}
			}else{
				pila[ind2-1].Push(pila[ind-1].Pop());
				cout<<"Se ha movido el caracter de la pila "<<ind<<" a la pila"<<ind2<<endl;		
			}
		}
}
void VerPilas(){
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
}
