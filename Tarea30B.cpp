#include<iostream>
#include<fstream>
using namespace std;
int Array[80], compa=0, inter=0;
void Insercion(int);
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo de insercion-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> Array[I];
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	Insercion(I);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	cout<<"\nNumero de comparaciones: "<<compa<<endl;
	cout<<"Numero de Intercambios: "<<inter<<endl;
}
void Insercion(int n){
	int j, aux;
	for(int i=1; i<n; i++){
		j=i; compa++;
		while(j>0 && (Array[j-1] > Array[j])){
			aux = Array[j]; Array[j] = Array[j-1]; 
			Array[j-1] = aux;
			j--; inter++;
		}
	}
}
