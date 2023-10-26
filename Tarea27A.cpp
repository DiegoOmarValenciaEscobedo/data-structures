#include<iostream>
#include<fstream>
#include "Grafo.h"
using namespace std;
int main(){
	//---LEER ARCHIVO-----
	Grafo Entrada;
	int NumVer, NumAr, i=0, cont=1, suma=0, c, in;
	ifstream fe("grafo3.txt"); // define el archivo de origen del flujo de entrada
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
	bool NAxV[NumVer]; for(int j=0; j<NumVer; j++) NAxV[j] = 0; //array de tamaño numver para verificar los nodos que ya recorrimos
	Nodo *aux;
	Grafo Circuito;
	while(cont < NumVer){//se va a repetir hasta que cont sea igual a numver-1 porque inicializamos cont en 1
		aux = Entrada.ini;
		if(Circuito.Vacia()){
			Nodo *inicial = Entrada.ini; 
			while(inicial->A1.Origen != 1) inicial = inicial->sig;//al inicio busca el arista que salga de A y sea de menor peso
			Circuito.Insertar(inicial->A1); suma += inicial->A1.Peso; in = inicial->A1.Origen;
			c = inicial->A1.Destino; NAxV[inicial->A1.Origen-1] = true; NAxV[inicial->A1.Destino-1] =true;
			Entrada.Eliminar(inicial->A1.Clave); cont++;
		}else{
			while(aux){
				if(aux->A1.Origen == c){//verifica el nodo que salga del ultimo vertice recorrido de menor peso 
					if(NAxV[aux->A1.Destino -1] == false){//y que no forme ciclos antes de tiempo
						Circuito.Insertar(aux->A1); suma+= aux->A1.Peso;
						c = aux->A1.Destino; NAxV[aux->A1.Origen-1] =true; NAxV[aux->A1.Destino-1] =true;//vuelve true los vertices que ya halla pasado
						Entrada.Eliminar(aux->A1.Clave); cont++; break; 
					}else Entrada.Eliminar(aux->A1.Clave); //lo elimina del grafo inicial para no volverlo a elegir
				}else if(aux->A1.Destino == c){
					if(NAxV[aux->A1.Origen -1] == false){
						Circuito.Insertar(aux->A1); suma+= aux->A1.Peso;
						c = aux->A1.Origen; NAxV[aux->A1.Origen-1] =true; NAxV[aux->A1.Destino-1] =true;
						Entrada.Eliminar(aux->A1.Clave); cont++; break;
					}else Entrada.Eliminar(aux->A1.Clave);
				} 
				aux = aux->sig;
			}
		}
	}
	while(aux){//cuando ya tiene vertices-1
		if(aux->A1.Origen == c){//busca el que valla del nodo final 
			if(aux->A1.Destino == in){//a el primer nodo que elegimos para cerrar el circuito
				Circuito.Insertar(aux->A1); 
				suma+= aux->A1.Peso; break;
			}
		}else if(aux->A1.Destino == c){
			if(aux->A1.Origen == in){
				Circuito.Insertar(aux->A1);
				suma+= aux->A1.Peso; break;
			}
		}
		aux = aux->sig;
	}
	cout<<"El agente viajero\nRecorrido: "<<suma<<endl;
	Circuito.Ver();
}
