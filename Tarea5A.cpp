#include<iostream>
using namespace std;
class Rectangulo;

class Cuadrado{//clase cuadrado
	friend class Rectangulo;
	private:
	float lado;
	public:
	Cuadrado(float);
};
Cuadrado::Cuadrado(float _lado){//constructor cuadrado
	lado= _lado;
}

class Rectangulo{//clase rectangulo
	private:
	float base, altura;
	public:
	Rectangulo(float _b, float _a);
	float area();
	float perimetro();
	float convierte(Cuadrado clado);
};
Rectangulo::Rectangulo(float _b, float _a){//constructor rectangulo
	base = _b; altura = _a;
}
float Rectangulo::area(){// area del rectangulo
	return (base*altura);
}
float Rectangulo::perimetro(){//perimetro del rectangulo
	return ((2*base)+(2*altura));
}
float Rectangulo::convierte(Cuadrado clado){//convierte cuadrado a rectangulo
	altura = clado.lado;
	base = clado.lado;
}

int main(){
	float a, b,l;
	cout<<"Ingresa la base del rectangulo: ";
	cin>>b;
	cout<<"Ingresa la altura del rectangulo: ";
	cin>>a;
	Rectangulo rec1(a, b);
	cout<<"\nEl area del rectangulo es igual a: "<<rec1.area()<<endl;
	cout<<"\nEl perimetro del rectangulo es igual a: "<<rec1.perimetro()<<endl;
	cout<<"\nIngresa el lado del cuadrado: ";
	cin>>l;
	Cuadrado cua1(l);
	rec1.convierte(cua1);
	cout<<"\nConversion de Cuadrado a Rectangulo"<<endl;
	cout<<"\nEl area del rectangulo es igual a: "<<rec1.area()<<endl;
	cout<<"\nEl perimetro del rectangulo es igual a: "<<rec1.perimetro()<<endl;
	
}
