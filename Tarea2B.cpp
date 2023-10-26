#include<iostream>
#include<math.h>
using namespace std;
double res=0, restem=1, x=1;
double factorial(double b);
double procedimiento(double a);

int main(){
	cout<<"Programa para saber el valor del seno (x)"<<endl;
	cout<<"Ingresa el valor de X:";
	cin>>x;
	procedimiento(x);
}

double factorial(double b){
	double fac=1;
		for(int k=1; k<=b; k++){
			fac *= k;
		}
	
	return fac;
}

double procedimiento(double a){
	bool it =false;
	for(int j=1; restem>=(1/10000);j+=2){
		
		if(it == true){
			restem= pow(a, j)/factorial(j);
			res-= restem;	
			it=false;
		}else if(it==false){
			restem= pow(a, j)/factorial(j);
			res+= restem;
			it=true;	
		}
		restem= pow(a, j)/factorial(j);
		
		res-= restem;
	}
		printf("El resultado de la sumatoria es: %.4f", res);
}
