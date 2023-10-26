#include<iostream>
using namespace std;

int modulo(int a, int b){
	int res;
	if(a<b) res =a;
	else res = modulo(a-b, b);
	return res;
}
int main(){
	int n1, n2;
	cout<<"Ingresa el primer numero: ";
	cin>>n1;
	cout<<"Ingresa el segundo numero: ";
	cin>>n2;
	cout<<"El resutado del modulo es: "<<modulo(n1, n2)<<endl;
}
