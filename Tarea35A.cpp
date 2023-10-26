#include<iostream>
#include<fstream>
using namespace std;
void MezclaNatural(int *a, int n);
void MezclaDirecta(int *a, int n);
int Array[80], h=0;
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo de mezcla natural-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	while(!fe.eof()) {
		fe >> Array[I];
		I++;
	}
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	MezclaNatural(Array, I);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
}
void MezclaNatural(int *a, int n){
	int izquierda=0, izq=0, derecha =n-1, der=derecha;
	bool ord = false;
	do{
		ord=true; izquierda = 0;
		while(izquierda<derecha){
			izq=izquierda;
			while(izq<derecha && a[izq] <= a[izq+1]) izq++;
			der = izq+1;
			while((der == derecha-1) || (der < derecha && a[der]<=a[der+1])) der++;
			if(der<=derecha){
				ord = 0;
				MezclaDirecta(a, n);
			}
			izquierda = izq;
		}	
	}while(!ord);
}
void MezclaDirecta(int *a, int n){
	if(n==1) return;//cuando la longitud del subarreglo sea de un solo elemento acaba la recursividad 
	int medio = n/2;
	int *izq = new int[medio]; int *der = new int[n-medio]; //se declaran como apuntadores para poder pasarlos como parametros 
	for(int i=0;i<medio;i++) izq[i]=a[i];//se pasa la mitad del arreglo de lado izquierdo
	for(int i=medio; i<n; i++) der[i-medio]=a[i];//se pasa la mitad del arreglo de lado derecho
	MezclaDirecta(izq, medio);//recursividad con el subarreglo izquierdo
	MezclaDirecta(der, n-medio);//recursividad con el subarreglo derecho
	//aqui se vacian los subarreglos fusionandolos
	int i=0, j=0, k=0;
	while((i<medio)&&(j<n-medio)){
		if(izq[i] <= der[j]){//vacia los subarreglos en el arreglo original, hasta que alguno de los 2 se vacie 
			a[k] = izq[i]; i++; k++;
		}else{
			a[k] = der[j]; j++; k++;
		} 
	}	
	while(i < medio){//si alguno de los dos esta vacio, lo que resta del otro se vacia en el arreglo
		a[k] = izq[i]; i++;k++;
	}
	while(j < n-medio){
		a[k] = der[j]; j++;k++;
	}
}
