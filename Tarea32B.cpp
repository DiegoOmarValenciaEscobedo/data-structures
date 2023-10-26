#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
void ShellSort(int);
int Array[80], compa=0, inter=0;
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo ShellSort-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> Array[I];
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	ShellSort(I);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	cout<<"\nNumero de comparaciones: "<<compa<<endl;
	cout<<"Numero de Intercambios: "<<inter<<endl;
}
void ShellSort(int a){
	int b, temp;
	int intervalo = round(a/2.2);
	while(intervalo>0){
		for(int i= intervalo; i<a; i++){
			b=i; temp = Array[i]; compa++;
			while(b>=intervalo && Array[b-intervalo] >temp){
				Array[b] = Array[b-intervalo];
				b = b-intervalo; inter++; compa++;
			}
			Array[b] = temp;
		}
		intervalo = round(intervalo/2.2);
	}
}
