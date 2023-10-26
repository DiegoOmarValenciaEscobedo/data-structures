#include<iostream>
#include<math.h>
using namespace std;
class Cilindro;
class Cono;
class Esfera;

class Circulo{
	friend class Cilindro;
	friend class Cono;
	private:
	const double pi = 3.1416;
	double radio;
	public:
	Circulo(double);
	double perimetro();
	double area();
};
Circulo::Circulo(double _rad){
	radio = _rad;
}
double Circulo::perimetro(){
	return 2*(pi*radio);
}
double Circulo::area(){
	double rc = (radio * radio);
	return pi*rc;
}

class Cilindro{
	
	private:
	double radio, altura;
	public:
	Cilindro(double, double);
	double volumen();
	double superficie();
};
Cilindro::Cilindro(double _rad, double _alt){
	radio = _rad; altura = _alt;
}
double Cilindro::volumen(){
	Circulo base(radio);
	return altura * base.area();
}
double Cilindro::superficie(){
	Circulo base(radio);
	return (2*base.area())+(altura*base.perimetro());
}

class Cono{
	private:
	const double pi = 3.1416;
	double radio, altura;
	public:
	Cono(double, double);
	double volumen();
	double superficie();
	
	
};
Cono::Cono(double _rad, double _alt){
	radio = _rad; altura = _alt;
}
double Cono::volumen(){
	Circulo base(radio);
	return (altura * base.area())/3;
}
double Cono::superficie(){
	Circulo base(radio);
	double area_lateral = pi*radio*sqrt((radio*radio)+(altura*altura));
	return area_lateral+ base.area();
}

class Esfera{
	private:
	double radio;
	const double pi = 3.1416;
	public:
	Esfera(double);
	double volumen();
	double superficie();
};
Esfera::Esfera(double _rad){
	radio = _rad;
}
double Esfera::volumen(){
	return 4*pi*(radio*radio*radio)/3;
}
double Esfera::superficie(){
	return 4*pi*radio*radio;
}
int main(){
	double r, a;
	cout<<"CILINDRO"<<endl;
	cout<<"Ingresa el radio de la base del cilindro: :";
	cin>>r;
	cout<<"Ingresa la altura del cilindro: ";
	cin>>a;
	Cilindro cil1(r, a);
	cout<<"\nEl volumen del cilindro es: "<<cil1.volumen();
	cout<<"\nLa superficie del cilindro es de: "<<cil1.superficie();
	cout<<"\n\nCONO"<<endl;
	cout<<"Ingresa el radio de la base del cono: :";
	cin>>r;
	cout<<"Ingresa la altura del cono: ";
	cin>>a;
	Cono cono1(r, a);
	cout<<"\nEl volumen del cono es: "<<cono1.volumen();
	cout<<"\nLa superficie del cono es de: "<<cono1.superficie();
	cout<<"\n\nESFERA"<<endl;
	cout<<"Ingresa el radio de la esfera :";
	cin>>r;
	Esfera esf1(r);
	cout<<"\nEl volumen del cono es: "<<esf1.volumen();
	cout<<"\nLa superficie del cono es de: "<<esf1.superficie();
}
