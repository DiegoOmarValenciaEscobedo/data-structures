#include<iostream>
#include<fstream>
#include "Grafo.h"
using namespace std;
bool RetArista(Grafo, Nodo*);
int main(){
	//---LEER ARCHIVO-----
	Grafo Entrada;
	int NumVer, NumAr, i=0, cont=1, suma=0;
	ifstream fe("grafo2.txt"); // define el archivo de origen del flujo de entrada
	fe>>NumVer; // lee el número de vértices del grafo
	fe>>NumAr; // lee el número de aristas del grafo
	while(i<NumAr) { // para cada arista lee sus cuatro atributos
		Arista a;
		a.Clave=++i;
		fe >> a.Origen;
		fe >> a.Destino;
		fe >> a.Peso;
		Entrada.Insertar(a); // llama al método insertar, para agregar esa arista
	}
	fe.close(); // cierra el archivo
	//EMPIEZA METODO PRIM
	bool componente[NumVer]; //vector que verifica si se forman circuitos
	for(int j=0; j<NumVer; j++) componente[j] = false;//rellena el vector con falsos
	Grafo AEM;//Donde se van a guardar las aristas 
	Nodo *aux = Entrada.ini;
	while(cont < NumVer){//mientras los vertices en AEM sean menores que entrada
		fflush(stdin);
		if(AEM.Vacia()){//si esta vacia la inserta en AEM automaticamente
			AEM.Insertar(aux->A1); suma += aux->A1.Peso;//lo inserta en AEM
			Entrada.Eliminar(aux->A1.Clave);//Lo elimina en entrada
			cont++;
		}else{
			while(aux){
				if(RetArista(AEM, aux)){//Lo que hace es devolver la primer arista que encuentre que coincida con las que ya estan en el arbol de expansion minimo
					if(!componente[aux->A1.Destino -1] || !componente[aux->A1.Origen -1]){//si el destino de este nodo no forma un ciclo
						AEM.Insertar(aux->A1); suma+= aux->A1.Peso;//lo inserta en AEM
						componente[aux->A1.Origen -1] = true; componente[aux->A1.Destino -1] = true;
						Entrada.Eliminar(aux->A1.Clave); // lo elimina de entrada para no volverlo a seleccionar
						cont++;  break;
					}else Entrada.Eliminar(aux->A1.Clave);//si forma ciclos solo la elimina
				}
				aux = aux->sig;
			}
		}
		aux = Entrada.ini;
	}
	cout<<"El arbol de expansion minimo por el metodo de prim es:"<<endl;
	AEM.Ver();
	cout<<"Suma del camino: "<<suma<<endl;	
}
bool RetArista(Grafo a, Nodo* b){//compara cada vertice de los nodos, si alguna coincide manda true, si no false
	bool si=false;
	int o1 = b->A1.Origen, o2, d1 = b->A1.Destino, d2;
	Nodo *na = a.ini;
	while(na){
		o2 = na->A1.Origen; d2 = na->A1.Destino;
		if(d1 == o2){
			si = true; break;
		}else if(d1 == d2){
			si= true; break;
		}else if(o1 == o2){
			si= true; break;
		}else if(o1 == d2){
			si= true; break;
		}else na = na->sig;
	}
	return si;
}
