#include<iostream>
using namespace std;

class Alumno{
	public:
	string nombre, carrera;
	int edad;
	int sexo;
	public:
	Alumno(string _n, int _e, int _s, string _c);//constructor
	void cambio(string _nc);// metodo cambio
};
Alumno::Alumno(string _n, int _e, int _s, string _c){
	nombre = _n;
	edad = _e;
	sexo = _s;
	carrera = _c;
}
void Alumno::cambio(string _nc){
	carrera = _nc;
}
int main(){
	string n, c, nc;	
	int e;	
	int s;
	cout<<"Ingresa el nombre: ";
	cin>>n;
	cout<<"Ingresa la edad: ";
	cin>>e;
	cout<<"Ingresa el sexo: ";
	cin>>s;
	cout<<"Ingresa la carrera: ";
	cin>>c;
	Alumno alumno1(n, e, s, c);
	cout<<"\nNombre: "<<alumno1.nombre<<"\nEdad: "<<alumno1.edad<<"\nSexo: "<<alumno1.sexo<<"\nCarrera: "<<alumno1.carrera<<endl;
	cout<<"\nCambio de carrera, ingresa la nueva carrera: ";
	cin>>nc;
	alumno1.cambio(nc);
	cout<<"\nNombre: "<<alumno1.nombre<<"\nEdad: "<<alumno1.edad<<"\nSexo: "<<alumno1.sexo<<"\nCarrera: "<<alumno1.carrera<<endl;
	
}
