#include<iostream>
using namespace std;
int n;
int main(){
	do{
		cout<<"\nIngresa un numero: ";
		cin>>n;
			if(n<0){
				cout<<"\nEl numero ingresado es negativo"<<endl;
			}else if(n<100 && n>0){
				cout<<"\nEl numero ingresado es positivo menor que 100"<<endl;
			}else if(n>=100){
				cout<<"\nEl numero ingresado es positivo mayor que 100"<<endl;
			}
	}while(n != 0);
	cout<<"\nIngresaste un cero, programa terminado";
}
