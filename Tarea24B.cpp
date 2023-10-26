#include<iostream>
#include<fstream>
#include "Grafo.h">
using namespace std;
void CreaMatriz(int a, int [3][12]);
int main(){
	Grafo G1;
	int NumVer, NumAr, k=0;
	ifstream fe("grafo1.txt"); // define el archivo de origen del flujo de entrada
	fe>>NumVer; // lee el número de vértices del grafo
	fe>>NumAr; // lee el número de aristas del grafo
	while(k<NumAr) { // para cada arista lee sus cuatro atributos
		Arista a;
		a.Clave=++k;
		fe >> a.Origen;
		fe >> a.Destino;
		fe >> a.Peso;
		G1.Insertar(a); // llama al método insertar, para agregar esa arista
	}
	fe.close(); // cierra el archivo
	//G1.Ver();
	int ar[3][12];//matriz con los atributos de las aristas
	Nodo *aux; 
	for(int i=0; i<3;i++){
		aux = G1.ini;
		for(int j=0; j<NumAr; j++){
			if(i==0){
				ar[i][j] = aux->A1.Peso;	
				aux = aux->sig;
			}else if(i==1){
				ar[i][j] = aux->A1.Origen;	
				aux = aux->sig;
			}else if(i==2){
				ar[i][j] = aux->A1.Destino;	
				aux = aux->sig;
			}
		}
	}
	/*for(int l=0; l<3;l++){
		cout<<endl;
		for(int m=0; m<NumAr; m++){
			cout<<"\t"<<ar[l][m];
		}
	}*/
	CreaMatriz(NumVer, ar);
}
void CreaMatriz(int a, int b[3][12]){
	int Mat[a][a];
	int g=0;
	for(int i=0; i<a;i++){//rellena la matria con 999 y 0
		for(int j=0; j<a; j++){
			if(i==j){
				Mat[i][j] = 0;	
			}else{
				Mat[i][j] = 9999;	
			}
		}
	}
	for(int l=0; l<a;l++){//va rellenando la matriz con el peso segun origen y destino
		for(int m=0; m<a; m++){
			if(l != m){
				g=0;
				while(g<12){
					if(b[1][g] == l+1){
						if(b[2][g] ==m+1){
							Mat[l][m]= b[0][g];
						}
					}
					g++;
				}
			}
		}
	}
	int k=0;
	cout<<"Tabla de adyacencia\n\n"<<endl;
	cout<<"Verical = Vertice de Origen\n"<<endl;
	cout<<"Horizontal = Vertice de destino\n"<<endl;
	while(k<a){
		cout<<"\t*"<<k+1;
		k++;
	}
	cout<<"\n\n";
	for(int x=0; x<a;x++){
		cout<<"\n*"<<x+1;
		for(int y=0; y<a; y++){
			cout<<"\t"<<Mat[x][y];
		}
	}
}

