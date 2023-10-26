#include<iostream>
#include"pila.h"
#include"Cola.h"
using namespace std;
void Convierte(string);
int main(){
	string ex;
	cout<<"Ingresa la expresion infija sin espacios: "; cin>>ex;
	cout<<"La expresion resultante postfija es: "<<endl;
	Convierte(ex);
	
}
void Convierte(string a){
	Pila<char> PilaTrabajo;
	Cola<char> ColaSalida;
	char pos, temp;
	for(int i=0; i<a.size(); i++){
		pos = a[i];
		if(isdigit(pos) || isalpha(pos)) ColaSalida.Put(pos);
		else if(pos == '(') PilaTrabajo.Push(pos);
		else if(pos == ')'){
			temp = PilaTrabajo.VerCima();
			while(temp != '('){
				temp = PilaTrabajo.VerCima();
				if(temp != '(')	ColaSalida.Put(PilaTrabajo.Pop());
				else PilaTrabajo.Pop();
			}
		}else{
			if(pos=='+' || pos=='-'){
				if(PilaTrabajo.Vacia()) PilaTrabajo.Push(pos);
				else{
					while(!PilaTrabajo.Vacia()){
						if(PilaTrabajo.VerCima() != '(') ColaSalida.Put(PilaTrabajo.Pop());
						else break;
					}
					PilaTrabajo.Push(pos);
				}
			}else if(pos=='*' || pos=='/'){
				if(PilaTrabajo.Vacia()) PilaTrabajo.Push(pos);
				else{
					while(!PilaTrabajo.Vacia()){
						if(PilaTrabajo.VerCima()=='(' || PilaTrabajo.VerCima()=='+' || PilaTrabajo.VerCima()=='-'){
							break;
						}else ColaSalida.Put(PilaTrabajo.Pop());
					}
					PilaTrabajo.Push(pos);
				}
			}else if(pos=='^'){
				if(PilaTrabajo.Vacia()) PilaTrabajo.Push(pos);
				else{
					while(!PilaTrabajo.Vacia()){
						if(PilaTrabajo.VerCima()=='(' || PilaTrabajo.VerCima()=='+' || PilaTrabajo.VerCima()=='-' || PilaTrabajo.VerCima()=='*' || PilaTrabajo.VerCima()=='/'){
							break;
						}else ColaSalida.Put(PilaTrabajo.Pop());
					}
					PilaTrabajo.Push(pos);
				}
			}
		}
	}
	while(!PilaTrabajo.Vacia()) ColaSalida.Put(PilaTrabajo.Pop());
	ColaSalida.Ver();
}
