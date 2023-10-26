#include<iostream>
using namespace std;
int arr[5];
int *apu = arr;
double arre[5];
double *apun = arre;
char arreglo[5];
char *apunta = arreglo;



template <class T>
	T masdiez(T *a){
		cout<<"Valores del arreglo mas 10"<<endl;
		for(int i=0; i<5; i++){
			cout<<a[i]+10<<endl;
		}
	}
template <class T>
	T pordiez(T *a){
		cout<<"Valores del arreglo por 10"<<endl;
		for(int i=0; i<5; i++){
			cout<<a[i]*10<<endl;
		}
	}
template <class T>
	T cuadrado(T *a){
		cout<<"Valores del arreglo al cuadrado"<<endl;
		for(int i=0; i<5; i++){
		cout<<a[i]*a[i]<<endl;
		}
	}
int main(){
	for(int i=0; i<5; i++){
		cout<<"ingresa un valor para el vector de enteros: ";
		cin>>arr[i];
	}
	for(int i=0; i<5; i++){
		cout<<"ingresa un valor para el vector de decimales: ";
		cin>>arre[i];
	}
	for(int i=0; i<5; i++){
		cout<<"ingresa un valor para el vector de caracteres: ";
		cin>>arreglo[i];
	}
	cout<<"\n\n\nENTEROS"<<endl;
	masdiez<int>(apu);
	pordiez<int>(apu);
	cuadrado<int>(apu);
	cout<<"\n\n\nDECIMALES"<<endl;
	masdiez<double>(apun);
	pordiez<double>(apun);
	cuadrado<double>(apun);
	cout<<"\n\n\nCARACTERES"<<endl;
	masdiez<char>(apunta);
	pordiez<char>(apunta);
	cuadrado<char>(apunta);
}
