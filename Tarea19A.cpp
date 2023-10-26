#include<iostream>
#include<sstream>
#include "pila.h"
#include<cstdlib>
#include<math.h>
using namespace std;
double Evalua(string);
int main(){
	string expresion;
	cout<<"Introduce la expresion separando cada componente con ';' al final de la expresion: "; getline(cin, expresion);
	cout<<"El resultado de la expresion es: "<<Evalua(expresion)<<endl;
}
double Evalua(string ex){
	Pila<string> PilaEntrada;
	Pila<double> PilaOp;
	stringstream ss(ex);
	double a, x, y;
	string aux;
	while(ss>>aux) PilaEntrada.Push(aux);
	while(!PilaEntrada.Vacia()){
		aux = PilaEntrada.Pop();
		if(aux == ";"){	
		}else if(isdigit(aux[0]) || (aux[0] == '-' && isdigit(aux[1]))){ 
			a = atof(aux.c_str());
			PilaOp.Push(a);
			cout<<"se introdujo a la pila: "<<a<<endl;
		}else if(!PilaOp.Vacia()){
			x = PilaOp.Pop();
			y = PilaOp.Pop();			
			if(aux == "+"){
			    PilaOp.Push(x+y);
				cout<<"Se realizo la suma entre "<<x<<" y "<<y<<endl;	
			}else if(aux == "-"){
				PilaOp.Push(x-y);	
				cout<<"Se realizo la resta entre "<<x<<" y "<<y<<endl;
			}else if(aux == "*"){
				PilaOp.Push(x*y);
				cout<<"Se realizo la multiplicacion entre "<<x<<" y "<<y<<endl;	
			}else if(aux == "/"){
				PilaOp.Push(x/y);	
				cout<<"Se realizo la division entre "<<x<<" y "<<y<<endl;
			}else if(aux == "%"){
				PilaOp.Push(int(x)%int(y));	
				cout<<"Se realizo el modulo entre "<<x<<" y "<<y<<endl;
			}else if(aux == "^"){
				PilaOp.Push(pow(x,y));
				cout<<"Se realizo la potencia entre "<<x<<" y "<<y<<endl;
			}else cout<<"El caracter "<<aux<<" No es permitido en la expresion"<<endl;
		}else cout<<"Hay un error en la expresion"<<endl;
}
return double(PilaOp.VerCima());
}
