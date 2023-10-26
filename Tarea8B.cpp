#include<iostream>
using namespace std;
int suma(int a[], int b){
	if(b==1)  return a[0];
	else return a[b-1] * suma(a, b-1);
}
int main(){
	int n;
	cout<<"Ingresa la cantidad de numeros que tiene tu arreglo: ";
	cin>>n;
	int arreglo[n];
	for(int i=0; i<n; i++){
	cout<<"Ingresa el valor No. "<<i+1<<" : "; cin >> arreglo[i];}
	cout<<"La suma de los valores del arreglo es: "<<suma(arreglo, n);
}
