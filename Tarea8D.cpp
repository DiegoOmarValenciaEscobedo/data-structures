#include<iostream>
using namespace std;
int suma(int a[][4], int b, int c){
	if(b==1)  return a[c][0];
	else return a[c][b-1] + suma(a, b-1,c);
}
int main(){
	int sumat;
	int arreglo[4][4];
	for(int j=0;j<4;j++){
		for(int i=0; i<4; i++){
			cout<<"Ingresa el valor de la posicion ("<<j+1<<", "<<i+1<<") : "; cin >> arreglo[j][i];
		}
	}
	sumat += suma(arreglo,4,0);
	sumat += suma(arreglo,4,1);
	sumat += suma(arreglo,4,2);
	sumat += suma(arreglo,4,3);
	cout<<"La suma de los valores del arreglo es: "<<sumat;
}
