#include<iostream>
#include<sstream>
#include "pila.h"
#include<cstdlib>
#include<math.h>
using namespace std;
double Evalua(string);
int main(){
	string expresion;
	cout<<"Introduce la expresion separando cada componente con un ';' al final de la expresion: "; getline(cin, expresion);
	cout<<"El resultado de la expresion es: "<<Evalua(expresion)<<endl;
}
double Evalua(string ex){
	Pila<double> pila1;
	double a, x, y;
	stringstream ss(ex); //aqui el stringstream recibe como parametro un string
	string aux;
	while(ss>>aux){//aqui el ss recorre cada uno de las palabras y las inserta en aux
		if(aux == ";"){
		cout<<"Cadena terminada"<<endl; break;	
		}else if(isdigit(aux[0]) || (aux[0] == '-' && isdigit(aux[1]))){ 
			a = atof(aux.c_str());
			pila1.Push(a);
			cout<<"se introdujo a la pila: "<<a<<endl;
		}else if(!pila1.Vacia()){
			y = pila1.Pop();
			x = pila1.Pop();			
			if(aux == "+"){
				 pila1.Push(x+y);
				 cout<<"Se realizo la suma entre "<<x<<" y "<<y<<endl;	
			}else if(aux == "-"){
				pila1.Push(x-y);	
				cout<<"Se realizo la resta entre "<<x<<" y "<<y<<endl;
			}else if(aux == "*"){
				pila1.Push(x*y);
				cout<<"Se realizo la multiplicacion entre "<<x<<" y "<<y<<endl;	
			}else if(aux == "/"){
				pila1.Push(x/y);	
				cout<<"Se realizo la division entre "<<x<<" y "<<y<<endl;
			}else if(aux == "%"){
				pila1.Push(int(x)%int(y));	
				cout<<"Se realizo el modulo entre "<<x<<" y "<<y<<endl;
			}else if(aux == "^"){
				pila1.Push(pow(x,y));
				cout<<"Se realizo la potencia entre "<<x<<" y "<<y<<endl;
			}else cout<<"El caracter "<<aux<<" No es permitido en la expresion"<<endl;
		}else cout<<"Hay un error en la expresion"<<endl;
}
return double(pila1.VerCima());
}
