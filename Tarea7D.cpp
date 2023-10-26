#include<iostream>
using namespace std;

int division(int a, int b){
	int res;
	if(a<b) res=0;
	else res = division(a-b, b)+1;
	return res;
}
int main(){
	int n1, n2;
	cout<<"Ingresa el primer numero: ";
	cin>>n1;
	cout<<"Ingresa el segundo numero: ";
	cin>>n2;
	cout<<"El resultado de la division es: "<<division(n1, n2)<<endl;
	
}
