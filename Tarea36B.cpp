#include<iostream>
#include<fstream>
using namespace std;
void Hash(int *a, int n, int k);
bool Primo(int);
int Array[74], cont=0;
int main(){
	int I=0, aux;
	cout<< "-----Busqueda por el metodo de funciones hash-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	while(!fe.eof()) {
		fe >> Array[I];
		I++;
	}
	fe.close(); aux = I;
	cout<<I<<" datos leidos."<<endl;
	while(!Primo(aux) || aux<(I+5)) aux++;//Se asigna aux como el numero N primo cercano al numero de elementos 
	int THash[aux], j=0;//se crea el vector que va a servir como tabla de hash
	for(int k=0; k<aux; k++) THash[k] = 0; //se rellena el vector con 0 para verificar si una celda esta vacia
	while(j<I){//se hace el ciclo para rellenar la tabla de hash
		Hash(THash, aux, Array[j]);// Los parametros que se mandan son (La tabla de hash, el valor de N, el valor K)
		j++;
	} 
	cout<<"N es igual a: "<<aux<<endl;
	cout<<"Numero de colisiones es igual a: "<<cont<<endl;
	cout<<"\n---Tabla de hash---"<<endl;
	cout<<"\nPosicion\tValor"<<endl;
	for(int i=0; i<aux; i++) cout<<i<<"\t\t"<<THash[i]<<endl;
}
void Hash(int *a, int n, int k){
	int b = k%n;
	if(a[b] == 0) a[b] = k; //si la casilla tiene un cero entonces se asigna en esa posicion el valor k
	else{
	Hash(a, n, k+1); cont++; //si la casilla esta ocupada se hace un ReHash con k+1
	}
}
bool Primo(int a){//verifica si aux es primo para usarse como N
	int b=0, c=a;
	while(c>0){
		if(a%c == 0) b++;
		c--;
	}
	return b<3;
}
