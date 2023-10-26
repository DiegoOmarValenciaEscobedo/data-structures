#include<iostream>
using namespace std;
int limit, n;
int main(){
	cout<<"Ingresa el numero limite: ";
	cin>>limit;
	cout<<"Los numeros multiplos de tres son: "<<endl;
	while(n<=limit){
		if(n%3 == 0) cout<<n<<"\n";
		n++;
	}
}
