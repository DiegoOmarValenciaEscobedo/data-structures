#include<iostream>
#include<fstream>
#include"Cola.h"
using namespace std;
Cola<int> Entrada;
Cola<int> Num[10];
void Radix(int);
int main(){
	int I=0, a;
	cout<< "-----Ordenamiento por el metodo RadixSort-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> a;
	 	Entrada.Put(a);
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl; 
	Entrada.Ver();
	Radix(I);
	cout<<"\nTabla ordenada:"<<endl;
	Entrada.Ver();
}
void Radix(int n){
	int aux, b=10, c=1, d;
	while(b<=1000){
		for(int i=0; i<n; i++){
			aux = Entrada.Get();
			d = (aux%b)/c;
			Num[d].Put(aux);
		}
		for(int j=0; j<10; j++){
			while(!Num[j].Vacia()){
				Entrada.Put(Num[j].Get());
			}
		}
		b*=10; c*=10;
	}
}
