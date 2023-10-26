#include<iostream>
#include<fstream>
#include "Grafo.h"
using namespace std;
int main(){
	Grafo Entrada;
	int NumVer, NumAr, i=0, cont=0, suma=0;
	ifstream fe("grafo2.txt"); // define el archivo de origen del flujo de entrada
	fe>>NumVer; // lee el número de vértices del grafo
	fe>>NumAr; // lee el número de aristas del grafo
	while(i<NumAr) { // para cada arista lee sus cuatro atributos
		Arista a;
		a.Clave =++i;
		fe >> a.Origen;
		fe >> a.Destino;
		fe >> a.Peso;
		Entrada.Insertar(a); // llama al método insertar, para agregar esa arista
	}
	fe.close(); // cierra el archivo
	Grafo AEM;
	Nodo *aux = Entrada.ini; //posiciona a aux en el primer elemento de la lista de grafos 
	int componente[NumVer], o, d;
	for(int j=0; j<NumVer; j++) componente[j] = j;
	while(cont<NumVer-1){//el ciclo va a terminar hasta que el numero de aristas sea = (numero de vertices - 1)
	o = aux->A1.Origen-1; d = aux->A1.Destino-1;
		if(componente[o] != componente[d]){ //Si origen y destino son de diferentes componentes en el arreglo
			componente[o] = NumVer+10; componente [d] = NumVer+10;//asigna en el arreglo un valor igual para identificarlos 
			AEM.Insertar(aux->A1);//la inserta en el arbol de expansion minimo
			suma = suma + aux->A1.Peso;
			cont++;
		}
		aux = aux->sig;
	}
	cout<<"Arbol de expansion minimo"<<endl;
	cout<<"Suma del camino: "<<suma<<endl;
	AEM.Ver();
}
