#include<iostream>
using namespace std;
int arr[5];
int *apu = arr;
int masdiez(int *a);
int pordiez(int *a);
int cuadrado(int *a);
int main(){
	for(int i=0; i<5; i++){
		cout<<"ingresa un valor: ";
		cin>>arr[i];
	}
	masdiez(apu);
	pordiez(apu);
	cuadrado(apu);
}
int masdiez(int *a){
	cout<<"Valores del arreglo mas 10"<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]+10<<endl;
	}
}
int pordiez(int *a){
	cout<<"Valores del arreglo por 10"<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]*10<<endl;
	}
}
int cuadrado(int *a){
	cout<<"Valores del arreglo al cuadrado"<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]*a[i]<<endl;
	}
}
