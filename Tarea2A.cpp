#include<iostream>
#include<math.h>
using namespace std;
int x;
double res=1, restem=1;
int factorial(int b);
int procedimiento(int a);

int main(){
	cout<<"Programa para saber el valor de e^x"<<endl;
	cout<<"Ingresa el valor de X:";
	cin>>x;
	procedimiento(x);
}

int factorial(int b){
	int fac=1;
		for(int k=1; k<=b; k++){
			fac *= k;
		}
	
	return fac;
}

int procedimiento(int a){
	for(int j=1; restem>0.0000001;j++){
		restem= pow(a, j)/factorial(j);
		res+= restem;
	}
		printf("El resultado de la sumatoria es: %.4f", res);
}
