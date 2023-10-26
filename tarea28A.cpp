#include<iostream>
#include<fstream>
#include"Grafo.h"
int Tabla[8][3];
void RellenaTabla(Grafo , int);
int main(){
	//---LEER ARCHIVO-----
	Grafo Entrada;
	int NumVer, NumAr, I=0, sale=1;
	ifstream fe("grafo4.txt"); // define el archivo de origen del flujo de entrada
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
	//-----COMIENZA ALGORITMO DIJKSTRA
	cout<<"-----Algoritmo de Dijkstra-----"<<endl;
	for(int i=0; i<NumVer; i++){
		Tabla[i][0]=0;   //anterior
		Tabla[i][1]=9999;  //Peso
		Tabla[i][2]=false; //definitivo
	}
	cout<<"*****Tabla inicial"<<endl;
	cout<<"\tInd\tAnt\tPeso\tDef"<<endl;//Muestra la tabla paso a paso en cada cambio
	for(int j=0; j<NumVer; j++){
		cout<<"\t"<<j+1<<"\t"<<Tabla[j][0]<<"\t"<<Tabla[j][1]<<"\t"<<Tabla[j][2]<<endl;
	}
	Tabla[0][1]= 0; Tabla[0][2]= true; 	//Marca al primero como definitivo
	I=1;
	while(Tabla[NumVer -1][2] != true){//para hasta que el nodo destino sea definitivo
		RellenaTabla(Entrada, sale);//rellena la tabla con los datos del nodo en el que esta
		int menor=999;
		for(int i=0; i<NumVer; i++){
			if(Tabla[i][2]!=true && Tabla[i][1]<menor){//busca al menor no definitivo 
				menor=Tabla[i][1];
				sale=i;
			}
		}
		Tabla[sale][2] = true;//y lo selecciona como definitivo
		cout<<"\n\n*****Paso "<<I++<<endl;
		cout<<"\tInd\tAnt\tPeso\tDef"<<endl;//Muestra la tabla paso a paso en cada cambio
		for(int j=0; j<NumVer; j++){
			cout<<"\t"<<j+1<<"\t"<<Tabla[j][0]<<"\t"<<Tabla[j][1]<<"\t"<<Tabla[j][2]<<endl;
		}
	}
		
}
void RellenaTabla(Grafo a, int b){
	Nodo* aux= a.ini;
	int pesotemp;
	while(aux){
		if(aux->A1.Origen == b){
			pesotemp = Tabla[b-1][1] + aux->A1.Peso;
			if(Tabla[aux->A1.Destino -1][1] > pesotemp){
				Tabla[aux->A1.Destino -1][0] = b; Tabla[aux->A1.Destino -1][1] = pesotemp;
			}
		}else if(aux->A1.Destino == b){
			pesotemp = Tabla[b-1][1] + aux->A1.Peso;
			if(Tabla[aux->A1.Origen -1][1] > pesotemp){
				Tabla[aux->A1.Origen -1][0] = b; Tabla[aux->A1.Origen -1][1] = pesotemp;
			}	
		}	
		aux = aux->sig;
	}
}
