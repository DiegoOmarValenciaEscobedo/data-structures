#include<iostream>
using namespace std;
template <class T>
	T minimo(T a[][4],T fil,T col){
		char menor;
		if(fil==0 && col==0)return a[0][0];
		if(col<0) return minimo<char>(a, fil-1, 3);
		menor = minimo<char>(a, fil, col-1);
		if(menor>a[fil][col]) menor = a[fil][col];
		return menor;
	}
int main(){
	char array[4][4];
	cout<<"Matriz de caracteres 4x4"<<endl;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			fflush(stdin);
			cout<<"Ingresa el caracter de la posicion ("<<i+1<<", "<<j+1<<"):";
			cin>>array[i][j];
		}
	}
	cout<<"El minimo de los caracteres en el arreglo es: "<<minimo<char>(array, 3, 3);
}
