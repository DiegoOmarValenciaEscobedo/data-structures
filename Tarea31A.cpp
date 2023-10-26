#include<iostream>
#include<fstream>
using namespace std;
void QuickSort(int, int);
int Particion(int, int);
int Array[80], compa=0, inter=0;
int main(){
	int I=0;
	cout<< "-----Ordenamiento por el metodo QuickSort-----\n\nLeyendo los datos del archivo, ";
	fstream fe("datos.txt");
	 while(!fe.eof()) {
	 	fe >> Array[I];
	 	I++;
	 }
	fe.close();
	cout<<I<<" datos leidos."<<endl;
	cout<<"Datos iniciales:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	QuickSort(0, I-1);
	cout<<"\nTabla ordenada:"<<endl;
	for(int i=0; i<I; i++) cout<<Array[i]<<"\t";
	cout<<"\nNumero de comparaciones: "<<compa<<endl;
	cout<<"Numero de Intercambios: "<<inter<<endl;
}
void QuickSort(int a, int b){
	int k;
	if (a < b) {
		k = Particion(a,b);
		QuickSort(a,k-1);
		QuickSort(k+1,b);
	}
}
int Particion(int a, int b){
	int p=Array[a];//p es el pivote, siempre toma a la primera posicion
	int i=a, j=b, aux;/para no modificar los valores de a y b se copian a i y j
	while(i < j){//hasta que los indices se crucen                                                    
    	while(Array[i] <= p && i < j){i++; compa++;}//mientras no halle un numero mayor o igual al pivote
    	while(Array[j] > p){j--; compa++;}//mientras no halle un numero menor que el pivote         
		if(i < j){//cuando ya tiene a uno menor y uno mayor que el pivote los intercambia                        
    	    aux= Array[i];                     
    	    Array[i]=Array[j];
    	    Array[j]=aux; inter++;
		}
	}
	Array[a] = Array[j];//en este ultimo paso se cambia de lugar el pivote dependiendo de i y j                                    
	Array[j] = p; inter++;
	return j;
}
