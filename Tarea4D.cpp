#include<iostream>
#include<cmath>
using namespace std;

class poligono{
	private:
	int num_lados;
	double lon_lados;
	const float pi=3.1416;
	public:
	poligono(int _nl, double _ll);
	double perimetro();
	double area(); 
};
poligono::poligono(int _nl, double _ll){
	num_lados = _nl; lon_lados = _ll;
}
double poligono::perimetro(){
	return (num_lados * lon_lados);
}
double poligono::area(){
	double pii = pi/num_lados;
	double tangente = tan(pii);
	double oa = num_lados * (lon_lados*lon_lados);
	return oa/(4*tangente);
}
int main(){
	int nl;
	double ll;
	cout<<"Ingresa el numero de lados del poligono: ";
	cin>>nl;
	cout<<"Ingresa la longitud de lado del poligono: ";
	cin>>ll;
	poligono p1(nl, ll);
	cout<<"\nEl perimetro del poligono es: "<<p1.perimetro()<<endl;
	cout<<"\nEl area del poligono es: "<<p1.area()<<endl;
	
}
