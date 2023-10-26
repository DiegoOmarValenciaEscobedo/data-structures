#include<iostream>
using namespace std;

int cuadrado(int a){
	int res;
	if (a==1) res =1;
	else res = cuadrado(a-1)+((2*a)-1);
	return res;
}

int main(){
	int n;
	cout<<"Ingresa el numero que quieres elevar al cudrado: ";
	cin>>n;
	cout<<"El resultado es: "<<cuadrado(n)<<endl;
}
