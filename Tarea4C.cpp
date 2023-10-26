#include<iostream>
using namespace std;

class Rectangulo{
	private:
	float base, altura;
	public:
	Rectangulo(float);
	Rectangulo(float, float);
	float area();
	float perimetro();
};
Rectangulo::Rectangulo(float _c){
	base = _c; altura = _c;
}
Rectangulo::Rectangulo(float _a, float _b){
	base = _b; altura = _a;
}
float Rectangulo::area(){
	return (base*altura);
}
float Rectangulo::perimetro(){
	return ((2*base)+(2*altura));
}
int main(){
	float a, b, c;
	cout<<"Ingresa un lado del cuadrado: ";
	cin>>c;
	cout<<"Ingresa la base del rectangulo: ";
	cin>>b;
	cout<<"Ingresa el area del rectangulo: ";
	cin>>a;
	Rectangulo *apu;
	apu = new Rectangulo(c);
	cout<<"\nEl area del cuadrado: "<<apu -> area()<<endl;
	cout<<"\nEl perimetro del cuadrado: "<<apu -> perimetro()<<endl;
	apu = new Rectangulo(b, a);
	cout<<"\nEl area del rectangulo es igual a: "<<apu -> area()<<endl;
	cout<<"\nEl perimetro del rectangulo es igual a: "<<apu->perimetro()<<endl;
}
