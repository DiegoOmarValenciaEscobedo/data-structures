#include<iostream>
#include<fstream>
using namespace std;
int Array[80], compa=0, inter=0;
void Burbuja(int);
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo de la burbuja-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> Array[I];
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	Burbuja(I);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	cout<<"\nNumero de comparaciones: "<<compa<<endl;
	cout<<"Numero de Intercambios: "<<inter<<endl;
}
void Burbuja(int n){
	int aux;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			compa++;
			if(Array[j] > Array[j+1]){
				aux = Array[j+1];
				Array[j+1] = Array[j];
				Array[j] = aux; 
				inter++;
			}
		}
	}
}

