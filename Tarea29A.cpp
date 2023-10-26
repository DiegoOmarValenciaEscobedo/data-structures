#include<iostream>
#include<fstream>
#include"Grafo.h"
using namespace std;
int main(){
	//---LEER ARCHIVO-----
	Grafo Entrada;
	int NumVer, NumAr, I=0;
	ifstream fe("grafo5A.txt"); // define el archivo de origen del flujo de entrada
	fe>>NumVer; // lee el número de vértices del grafo
	fe>>NumAr; // lee el número de aristas del grafo
	while(I<NumAr) { // para cada arista lee sus cuatro atributos
		Arista a;
		a.Clave=++I;
		fe >> a.Origen;
		fe >> a.Destino;
		a.Peso = 0;//porque es no ponderado
		Entrada.Insertar(a); // llama al método insertar, para agregar esa arista
	}
	fe.close(); // cierra el archivo
	bool Adyacencia[NumVer][NumVer];//Matriz de adyacencia
	bool Conectividad[NumVer][NumVer];//Matriz de conectividad
	for(int i=0; i< NumVer; i++){//se inicializa con todos en 0
		for(int j=0; j<NumVer; j++){
			Adyacencia[i][j] = false;
			Conectividad[i][j] = false;
		}
	}
	Nodo *aux= Entrada.ini; I=0;
	while(I<NumAr){//rellena la matriz de adyacencia
		Adyacencia[aux->A1.Origen -1][aux->A1.Destino -1] = true;
		Conectividad[aux->A1.Origen -1][aux->A1.Destino -1] = true;
		aux = aux->sig; I++;
	}
	cout<<"Matriz Inicial\n\t-1\t-2\t-3\t-4\t-5\t-6\t-7\t-8"<<endl;
	for(int i=0; i< NumVer; i++){//muestra la tabla
	cout<<endl;
	cout<<"-"<<i+1;
		for(int j=0; j<NumVer; j++){
			cout<<"\t"<<Adyacencia[i][j];
		}
	}
	for(int k=0; k<NumVer; k++){
		cout<<"\n\nPaso "<<k+1<<endl;
		for(int i=0; i<NumVer; i++){
			for(int j=0; j<NumVer; j++){
				Conectividad[i][j] = Conectividad[i][j] || (Conectividad[i][k] && Conectividad[k][j]);
			}
		}
		cout<<"\n\t-1\t-2\t-3\t-4\t-5\t-6\t-7\t-8"<<endl;
		for(int l=0; l< NumVer; l++){//muestra la tabla
			cout<<endl;
			cout<<"-"<<l+1;
			for(int m=0; m<NumVer; m++){
				cout<<"\t"<<Conectividad[l][m];
			}
		}
	}
	
}
