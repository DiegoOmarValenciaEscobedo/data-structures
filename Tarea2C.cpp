#include<iostream>
using namespace std;
int n1, n2;
int exchange(int& a, int& b){
	int c;
	c=a;
	a=b;
	b=c;
	
}
int main(){
	cout<<"Ingresa el primer valor entero: ";
	cin>>n1;
	cout<<"\nIngresa el segundo valor entero: ";
	cin>>n2;
	cout<<"\nEl primer valor es:\t"<<n1<<endl;
	cout<<"\nEl segundo valor es:\t"<<n2<<endl;
	exchange(n1, n2);
	cout<<"\nLos numeros han intercambiado\n";
	cout<<"\nEl primer valor es:\t"<<n1<<endl;
	cout<<"\nEl segundo valor es:\t"<<n2<<endl;
}
