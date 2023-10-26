#include<iostream>
using namespace std;
//funciones
void Ingresanum1(), Ingresanum2();
double suma(struct Complejos a, struct Complejos b), resta(struct Complejos a, struct Complejos b), multiplicacion(struct Complejos a, struct Complejos b), division(struct Complejos a, struct Complejos b), inverso(struct Complejos a); 
struct Complejos{//Estructura de los numeros complejos
	double ParteReal;
	double ParteImaginaria;	
}complejo1, complejo2, complejoResultado;

int main(){
	int option;
	do{
		cout<<"Programa de operaciones con numeros complejos"<<endl;
		cout<<"\nIngresa 1 para sumar dos numeros complejos"<<endl;
		cout<<"Ingresa 2 para restar dos numeros conplejos"<<endl;
		cout<<"Ingresa 3 para obtener el producto de dos numeros complejos"<<endl;
		cout<<"Ingresa 4 para obtener el cociente de dos numeros complejos"<<endl;
		cout<<"ingresa 5 para obtener el inverso de un numero complejo"<<endl;
		cout<<"Ingresa 6 para salir"<<endl;
		cout<<".-";
		cin>>option;
		switch(option){
			case 1:Ingresanum1(); Ingresanum2(); suma( complejo1, complejo2);
			cout<<"\nLa suma de los numeros complejos es: "<<complejoResultado.ParteReal<<" + "<<complejoResultado.ParteImaginaria<<" i"<<endl;
				break;
			case 2:Ingresanum1(); Ingresanum2(); resta(complejo1, complejo2);
			cout<<"\nLa resta de los numeros complejos es: "<<complejoResultado.ParteReal<<" + "<<complejoResultado.ParteImaginaria<<" i"<<endl;
				break;
			case 3:Ingresanum1(); Ingresanum2(); multiplicacion(complejo1, complejo2);
			cout<<"El producto de los numeros complejos es: "<<complejoResultado.ParteReal<<" + "<<complejoResultado.ParteImaginaria<<" i"<<endl;
				break;
			case 4:Ingresanum1(); Ingresanum2();division(complejo1, complejo2);
			cout<<"La division de los numeros complejos es: "<<complejoResultado.ParteReal<<" / "<<(complejo2.ParteImaginaria * complejo2.ParteImaginaria)+(complejo2.ParteReal * complejo2.ParteReal)<<" + "<<complejoResultado.ParteImaginaria<<" i / "<<(complejo2.ParteImaginaria * complejo2.ParteImaginaria)+(complejo2.ParteReal * complejo2.ParteReal)<<endl;
				break;
			case 5:Ingresanum1(); inverso(complejo1);
			cout<<"El inverso del numero complejo es: "<<complejoResultado.ParteReal<<" / "<<(complejo1.ParteImaginaria * complejo1.ParteImaginaria)+(complejo1.ParteReal * complejo1.ParteReal)<<" + "<<complejoResultado.ParteImaginaria<<" i / "<<(complejo1.ParteImaginaria * complejo1.ParteImaginaria)+(complejo1.ParteReal * complejo1.ParteReal)<<endl;
				break;
			case 6:cout<<"\nHas salido de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion no valida"<<endl;
	}
	
		
	}while(option != 6);
}
void Ingresanum1(){
	cout<<"ingresa la parte real del primer numero: ";
	cin>>complejo1.ParteReal;
	cout<<"ingresa la parte imaginaria del primer numero: ";
	cin>>complejo1.ParteImaginaria;
}
void Ingresanum2(){
	cout<<"ingresa la parte real del segundo numero: ";
	cin>>complejo2.ParteReal;
	cout<<"ingresa la parte imaginaria del segundo numero: ";
	cin>>complejo2.ParteImaginaria;
}
double suma(struct Complejos a, struct Complejos b){
	complejoResultado.ParteReal = a.ParteReal + b.ParteReal;
	complejoResultado.ParteImaginaria = a.ParteImaginaria + b.ParteImaginaria;
}
double resta(struct Complejos a, struct Complejos b){
	complejoResultado.ParteReal = a.ParteReal - b.ParteReal;
	complejoResultado.ParteImaginaria = a.ParteImaginaria - b.ParteImaginaria;
}
double multiplicacion(struct Complejos a, struct Complejos b){
	complejoResultado.ParteReal = (a.ParteReal * b.ParteReal)+ (-1 * a.ParteImaginaria * b.ParteImaginaria);
	complejoResultado.ParteImaginaria =(a.ParteReal * b.ParteImaginaria) + (a.ParteImaginaria * b.ParteReal);
}
double division(struct Complejos a, struct Complejos b){
	complejoResultado.ParteReal = (a.ParteReal * b.ParteReal)+ (a.ParteImaginaria * b.ParteImaginaria);
	complejoResultado.ParteImaginaria =(-1 * a.ParteReal * b.ParteImaginaria) + (a.ParteImaginaria * b.ParteReal);
}
double inverso(struct Complejos a){
	complejoResultado.ParteReal = a.ParteReal;
	complejoResultado.ParteImaginaria = a.ParteImaginaria * -1;
}
