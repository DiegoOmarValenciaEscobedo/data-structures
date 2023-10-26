#include<iostream>
#include"pila.h"
using namespace std;
void Convierte(string);
int main(){
	string ex;
	cout<<"Ingresa la expresion infija sin espacios: "; cin>>ex;
	cout<<"La expresion resultante prefija es: "<<endl;
	Convierte(ex);
	
}
void Convierte(string a){
	Pila<char> PilaEntrada;
	Pila<char> PilaAuxiliar;
	Pila<char> PilaSalida;
	char aux, temp;
	for(int i=0; i<a.size(); i++)PilaEntrada.Push(a[i]);
	while(!PilaEntrada.Vacia()){
		aux =PilaEntrada.Pop();
		if(isdigit(aux) || isalpha(aux)) PilaSalida.Push(aux);
		else if(aux == ')') PilaAuxiliar.Push(aux);
		else if(aux == '('){
			temp = PilaAuxiliar.VerCima();
			while(temp != ')'){
				temp = PilaAuxiliar.VerCima();
				if(temp != ')')	PilaSalida.Push(PilaAuxiliar.Pop());
				else PilaAuxiliar.Pop();
			}	
		}else{
			if(PilaAuxiliar.Vacia()) PilaAuxiliar.Push(aux);
			else{
				if(aux=='+' || aux=='-'){
					PilaAuxiliar.Push(aux);
				}else if(aux=='*' || aux=='/'){
					while(!PilaAuxiliar.Vacia()){
						if(PilaAuxiliar.VerCima() != '+' || PilaAuxiliar.VerCima() != '-' || PilaAuxiliar.VerCima() == ')'){
							PilaAuxiliar.Push(aux);
							break;
						}
						else PilaSalida.Push(PilaAuxiliar.Pop());
					}
				}else if(aux=='^'){
					while(!PilaAuxiliar.Vacia()){
						if(PilaAuxiliar.VerCima() != '+' || PilaAuxiliar.VerCima() != '-' || PilaAuxiliar.VerCima() != '*' || PilaAuxiliar.VerCima() != '/' || PilaAuxiliar.VerCima() == ')'){
							PilaAuxiliar.Push(aux);
							break;
						}
						else PilaSalida.Push(PilaAuxiliar.Pop()); 
					}
					
				}
			}
		}
	}
	while(!PilaAuxiliar.Vacia()) PilaSalida.Push(PilaAuxiliar.Pop());
	PilaSalida.Ver(); 
}		
