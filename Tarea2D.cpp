#include<iostream>
using namespace std;
int n, fac=1;
int factorial(int a){
	for(int i=1; i<=a; i++){
		fac *= i;
	}
	cout<<"\nEl factorial de: "<<a<<" es: "<<fac<<endl;	
	cout<<"\nTabla de factoriales del 1 al 10"<<endl;
	cout<<"Numero\t\tFactorial"<<endl;
	cout<<"0\t\t1"<<endl;
	fac=1;
		for(int j=1; j<=10; j++){
			fac *= j;
			cout<<"\n"<<j<<"\t\t"<<fac;
		}
}
int main(){
	cout<<"Ingresa un numero: ";
	cin>>n;
	factorial(n);
} 
