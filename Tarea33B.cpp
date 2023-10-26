#include<iostream>
#include<fstream>
#include"Cola.h"
using namespace std;
Cola<string> Entrada;
Cola<string> Alf[26];
void Radix(int);
int main(){
	int I=0;
	string a; 
	cout<< "-----Ordenamiento por el metodo RadixSort-----\n\nLeyendo los datos del archivo, ";
	fstream fe("nombres.txt");
	 while(!fe.eof()) {//se leen los datos del archivo
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
	int a, c=4;
	string aux;
	while(c>=0){//en este caso solo tomamos en cuenta los primeros 5 caracteres de la cadena
		for(int i=0; i<n; i++){
			aux = Entrada.Get();//se extrae un elemento de la cola de entrada
			a = int(aux[c]);//se cunvierte a ASCII el caracter en la posicion c
			Alf[a-65].Put(aux);//se le resta 65 ya que el primer caracter que es la A es el 65
		}
		for(int j=0; j<26; j++){
			while(!Alf[j].Vacia()){//se vacian las colas del alfabeto
				Entrada.Put(Alf[j].Get());
			}
		}
		c--;
	}
}
