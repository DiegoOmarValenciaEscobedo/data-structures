#include<iostream>
using namespace std;
int limit;
int main(){
	cout<<"Ingresa el numero limite: ";
	cin>>limit;
	cout<<"Los numeros multiplos de tres son: "<<endl;
	for(int i=1;i<=limit;i++){
		if(i%3 == 0)cout<<i<<"\n";
	}
}
