#include<iostream>
using namespace std;

int mcd(int a, int b){
	int res;
	if(a == b) res = a;
	if(a>b) res = mcd(a-b, b);
	if(b>a) res = mcd(a, b-a);
	return res;
}
int main(){
	int n1, n2;
	cout<<"Ingresa el primer numero: ";
	cin>>n1;
	cout<<"Ingresa el segundo numero: ";
	cin>>n2;
	cout<<"El MCD es: "<<mcd(n1, n2)<<endl;
}

