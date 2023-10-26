#include<iostream>
#include<fstream>
using namespace std;
int Array[80], compa=0, inter=0;
void Seleccion(int);
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo de seleccion-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> Array[I];
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	Seleccion(I);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	cout<<"\nNumero de comparaciones: "<<compa<<endl;
	cout<<"Numero de Intercambios: "<<inter<<endl;
}
void Seleccion(int n){
	int aux;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			compa++;
			if(Array[i]>Array[j]){
				aux = Array[i];
				Array[i] = Array[j];
				Array[j] = aux; 
				inter++;
			}
		}
	}
}
