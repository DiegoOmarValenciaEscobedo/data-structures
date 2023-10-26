#include<iostream>
#include<fstream>
#include"Grafo.h"
using namespace std;
int main(){
	//---LEER ARCHIVO-----
	cout<<"-----Algoritmo de Floyd-Warshall"<<endl;
	Grafo Entrada;
	int NumVer, NumAr, I=0;
	ifstream fe("grafo5B.txt"); // define el archivo de origen del flujo de entrada
	fe>>NumVer; // lee el número de vértices del grafo
	fe>>NumAr; // lee el número de aristas del grafo
	while(I<NumAr) { // para cada arista lee sus cuatro atributos
		Arista a;
		a.Clave=++I;
		fe >> a.Origen;
		fe >> a.Destino;
		fe >> a.Peso;
		Entrada.Insertar(a); // llama al método insertar, para agregar esa arista
	}
	fe.close(); // cierra el archivo
	int Adyacencia[NumVer][NumVer];//Matriz de adyacencia
	int Trayectoria[NumVer][NumVer];//Matriz de conectividad
	for(int i=0; i< NumVer; i++){//se inicializa la matriz
		for(int j=0; j<NumVer; j++){
			if(i==j){
				Trayectoria[i][j]=0;	Adyacencia[i][j]=0;
			}else{
				Trayectoria[i][j]=999;	Adyacencia[i][j]=999;
			} 
		}
	}
	Nodo *aux= Entrada.ini;
	while(aux){//rellena la matriz de adyacencia
		Adyacencia[aux->A1.Origen -1][aux->A1.Destino -1] = aux->A1.Peso;
		Trayectoria[aux->A1.Origen -1][aux->A1.Destino -1] = aux->A1.Peso;
		aux = aux->sig;
	}
	cout<<"Matriz Inicial (de adyacencia)\n\t-1\t-2\t-3\t-4\t-5\t-6\t-7\t-8"<<endl;
	for(int i=0; i< NumVer; i++){//muestra la matriz de adyacencia
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
				Trayectoria[i][j] = min(Trayectoria[i][j], Trayectoria[i][k] + Trayectoria[k][j]);
			}
		}
		cout<<"\n\t-1\t-2\t-3\t-4\t-5\t-6\t-7\t-8"<<endl;
		for(int l=0; l< NumVer; l++){//muestra la matriz, paso por paso
			cout<<endl;
			cout<<"-"<<l+1;
			for(int m=0; m<NumVer; m++){
				cout<<"\t"<<Trayectoria[l][m];
			}
		}
	}
}
