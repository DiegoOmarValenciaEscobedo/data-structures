#include<iostream>
using namespace std;
string inversa(string);
string genera(string);
void identifica(string);
void balanceados(string);
void cerosyunos(string);
class Pila{
	public: string pila;
	public: Pila();
	void Push(char);
	char Pop();
	char VerCima();
	bool Vacia();
	void Ver();
};
Pila::Pila(){
	pila ="";
}
void Pila::Ver(){
	int i=0;
	while(i<pila.length()){
		cout<<pila[i++]<<"\t";
	}
	cout<<endl;
}
bool Pila::Vacia(){
	return (pila == "");
}
void Pila::Push(char a){
	pila = a + pila;
}
char Pila::Pop(){
	char sale = pila[0];
	pila = pila.substr(1);
	return sale;
}
char Pila::VerCima(){
	return pila[0];
}
string inversa(string aux){
Pila pila2;
	for(int i=0; i< aux.size(); i++){
	pila2.Push(aux[i]);
	}
return pila2.pila;
}
string genera(string a){
	Pila pila3;
	for(int i=(a.size())-1; i>=0; i--){
		pila3.Push(a[i]);
	}
	pila3.pila = pila3.pila + inversa(a);
	return pila3.pila;
}
void identifica(string b){
	Pila pila4;
	for(int j=(b.size())-1; j>=0; j--){
		pila4.Push(b[j]);
	}
	bool check = true;
	int i=0, f=(pila4.pila.size())-1 ;
	while(i<pila4.pila.size()){
		if(pila4.pila[i] == pila4.pila[f]){check = true;
		}else check = false; 
		i++; f--; 
	}
	if(check == true) cout<<"La cadena ingresada es un palindromo"<<endl;
	if(check == false) cout<<"La cadena no es un palindromo"<<endl;
}
void balanceados(string c){
	Pila pila5;
	Pila pila6;
	for(int i=(c.size())-1; i>=0; i--){
		pila5.Push(c[i]);
	}
	for(int j=0; j<pila5.pila.size(); j++){
		if(pila5.pila[j] == '(') pila6.Push('x');
	}
	for(int k=0; k<pila5.pila.size(); k++){
		if(pila5.pila[k] == ')') pila6.Pop();
	}
	if(pila6.pila == "") cout<<"La cadena esta balenceada"<<endl;
	else cout<<"La cadena no esta balanceada"<<endl;
}
void cerosyunos(string d){
	Pila pila7;
	Pila pila8;
	bool x=true; 
	for(int i=(d.size())-1; i>=0; i--){
		pila7.Push(d[i]);
	}
	for(int j=0; j<pila7.pila.size(); j++){
		if(pila7.pila[j] == '0') pila8.Push('x');
	}
	for(int k=0; k<pila7.pila.size(); k++){
		if(pila8.Vacia()){
			cout<<"La cantidad de unos es mayor a la de ceros"<<endl;
			x= false; break;
		} else if(pila7.pila[k] == '1') pila8.Pop();
	}
	if(x==true){
		if(pila8.Vacia()) cout<<"La cantidad de ceros y unos es igual"<<endl;
		else cout<<"La cantidad de ceros es mayor a la de unos"<<endl;	
	}
}
int main(){
	char op, valor;
	Pila pila1;
	string cad1;
	do{
		cout<<"1 Apilar valor"<<endl;
		cout<<"2 Desapilar valor"<<endl;
		cout<<"3 Mostrar"<<endl;
		cout<<"4 invertir pila"<<endl;
		cout<<"5 generar palindroma"<<endl;
		cout<<"6 identificar palindroma"<<endl;
		cout<<"7 parentesis balanceados"<<endl;
		cout<<"8 ceros y unos"<<endl;
		cout<<"9 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el caracter a apilar: "; cin>>valor; pila1.Push(valor);
				break;
			case '2':if(pila1.Vacia()) cout<<"La pila esta vacia"<<endl;
					 else cout<<"Se ha  desapilado: "<<pila1.Pop()<<endl;
				break;
			case '3':if(pila1.Vacia()) cout<<"La pila esta vacia"<<endl;
					 else pila1.Ver();
				break;
			case '4':if(pila1.Vacia()) cout<<"La pila esta vacia"<<endl;
					 else {
					 	pila1.pila = inversa(pila1.pila);
					 	cout<<"La pila invertida es:	"; pila1.Ver();
					 }	
				break;
			case '5':cout<<"Dame una cadena: "; cin>>cad1;
					cout<<"La palindroma de la cadena dada es: "<<genera(cad1)<<endl;
				break;
			case '6':cout<<"Dame una cadena: "; cin>>cad1;
					 identifica(cad1);
				break;
			case '7':cout<<"Dame una cadena: "; cin>>cad1;
					 balanceados(cad1);
				break;
			case '8':cout<<"Dame una cadena: "; cin>>cad1;
					 cerosyunos(cad1);
				break;
			case '9':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
		cout<<"\n"<<endl;
	}while(op != '9');
}
