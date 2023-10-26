#include<iostream>
#include<math.h>
using namespace std;

struct Vector{
	double x, y, z;
}vector1, vector2, vectorres;

void Ingresavec1(), Ingresavec2();
double suma(struct Vector a, struct Vector b), vecescalar(struct Vector a), producvectorial(struct Vector a, struct Vector b), productopunto(struct Vector a, struct Vector b), magnitud(struct Vector a), angulo(struct Vector a, struct Vector b);

int main(){
int option;
	do{
		cout<<"Programa de operaciones con vectores"<<endl;
		cout<<"\nIngresa 1 para sumar dos vectores"<<endl;
		cout<<"Ingresa 2 para multiplicar un vector por un escalar"<<endl;
		cout<<"Ingresa 3 para obtener el producto vectorial de dos vectores"<<endl;
		cout<<"Ingresa 4 para obtener el producto punto de dos vectores"<<endl;
		cout<<"ingresa 5 para obtener la magnitud de un vector"<<endl;
		cout<<"ingresa 6 para obtener el angulo entre dos vectores"<<endl;
		cout<<"Ingresa 7 para salir"<<endl;
		cout<<".-";
		cin>>option;
		switch(option){
			case 1:Ingresavec1(); Ingresavec2(); suma( vector1, vector2);
			cout<<"\nLa suma de los vectores es igual al vector: ("<<vectorres.x<<", "<<vectorres.y<<", "<<vectorres.z<<")"<<endl;
				break;
			case 2:Ingresavec1();  vecescalar( vector1);
			cout<<"\nLa multiplicacion del vector por el escalar es: ( "<<vectorres.x<<", "<<vectorres.y<<", "<<vectorres.z<<")"<<endl;
				break;
			case 3:Ingresavec1(); Ingresavec2(); producvectorial( vector1, vector2);
			cout<<"El producto de los vectores es: ("<<vectorres.x<<", "<<vectorres.y<<", "<<vectorres.z<<")"<<endl;
				break;
			case 4:Ingresavec1(); Ingresavec2();
			cout<<"El producto punto de los dos vectores es: "<<productopunto( vector1, vector2)<<endl;
				break;
			case 5:Ingresavec1();
			cout<<"La magnitud del vector es: "<< magnitud(vector1)<<endl;
				break;
			case 6:Ingresavec1(); Ingresavec2();
			cout<<"El angulo entre dos vectores es: "<<angulo(vector1, vector2)<<endl;
				break;
			case 7:cout<<"\nHas salido de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion no valida"<<endl;
	}
	
	cout<<"\n\n";
	}while(option != 7);
}

void Ingresavec1(){
	cout<<"ingresa la coordenada x del vector uno: ";
	cin>>vector1.x;
	cout<<"ingresa la coordenada y del vector uno: ";
	cin>>vector1.y;
	cout<<"ingresa la coordenada z del vector uno: ";
	cin>>vector1.z;
}	

void Ingresavec2(){
	fflush(stdin);
	cout<<"\n";
	cout<<"ingresa la coordenada x del vector dos: ";
	cin>>vector2.x;
	cout<<"ingresa la coordenada y del vector dos: ";
	cin>>vector2.y;
	cout<<"ingresa la coordenada z del vector dos: ";
	cin>>vector2.z;
}
double suma(struct Vector a, struct Vector b){
	vectorres.x = a.x + b.x;
	vectorres.y = a.y + b.y;
	vectorres.z = a.z + b.z;
}
double vecescalar(struct Vector a){
	int n;
	cout<<"Ingresa el numero escalar: "; cin>>n;
	vectorres.x = n * a.x;
	vectorres.y = n * a.y;
	vectorres.z = n * a.z;
	
}
double producvectorial(struct Vector a, struct Vector b){
	vectorres.x = (a.y * b.z) - (a.z * b.y);
	vectorres.y =-1 *((a.x * b.z)-(a.z * b.x));
	vectorres.z =(a.x * b.y)-(a.y * b.x);
}
double productopunto(struct Vector a, struct Vector b){
	double n =(a.x * b.x)+(a.y * b.y)+(a.z * b.z);
	return n;
}
double magnitud(struct Vector a){
	double m = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
	return m;
}
double angulo(struct Vector a, struct Vector b){
	double promag = magnitud(a) * magnitud(b);
	double angulo = productopunto(a, b);
	double ca = 1/cos(angulo/promag);
	return ca;
}
