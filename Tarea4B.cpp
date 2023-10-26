#include<iostream>
using namespace std;

class Rectangulo{
	private:
	float base, altura;
	public:
	Rectangulo(float _b, float _a);
	float area();
	float perimetro();
};
Rectangulo::Rectangulo(float _b, float _a){
	base = _b; altura = _a;
}
float Rectangulo::area(){
	return (base*altura);
}
float Rectangulo::perimetro(){
	return ((2*base)+(2*altura));
}
int main(){
	float a, b;
	cout<<"Ingresa la base del rectangulo: ";
	cin>>b;
	cout<<"Ingresa el area del rectangulo: ";
	cin>>a;
	Rectangulo rec1(a, b);
	cout<<"\nEl area del rectangulo es igual a: "<<rec1.area()<<endl;
	cout<<"\nEl perimetro del rectangulo es igual a: "<<rec1.perimetro()<<endl;
}
