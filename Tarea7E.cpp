#include<iostream>
using namespace std;
int rusa(int a, int b){
	int res; 
	if(a==1)res = b;
	else if(a%2 == 0)res = rusa(a/2, b*2);
	else res= rusa(a/2, b*2)+b;
	return res;
}
int main(){
	int n1, n2;
	cout<<"Ingresa el primer numero: ";
	cin>>n1;
	cout<<"Ingresa el segundo numero: ";
	cin>>n2;
	cout<<"El resultado de la multiplicacion rusa es: "<<rusa(n1, n2)<<endl;
	return 0;
}
