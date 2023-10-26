#include<iostream>
using namespace std;
class Cola{
	private: string cola;
	public:  Cola();
	void Put(char);
	char Get();
	bool Vacia();
	void Ver();
	
};
Cola::Cola(){
	cola ="";
}
void Cola::Ver(){
	int i=0;
	while(i<cola.length()){
		cout<<cola[i++]<<"\t";
	}
	cout<<endl;
}
bool Cola::Vacia(){
	return (cola == "");
}
void Cola::Put(char a){
	cola = cola + a;
}
char Cola::Get(){
	char sale = cola[0];
	cola = cola.substr(1);
	return sale;
}
int main(){
	char op, valor;
	Cola cola1;
	do{
		cout<<"1 ingresar valor"<<endl;
		cout<<"2 quitar valor"<<endl;
		cout<<"3 Mostrar"<<endl;
		cout<<"4 saber si la cola esta vacia"<<endl;	
		cout<<"5 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa el caracter : "; cin>>valor; cola1.Put(valor);
				break;
			case '2':if(cola1.Vacia()) cout<<"La cola esta vacia"<<endl;
					 else cout<<"Se ha  quitado: "<<cola1.Get()<<endl;
				break;
			case '3':if(cola1.Vacia()) cout<<"La cola esta vacia"<<endl;
					 else cola1.Ver();
				break;
			case '4':if(cola1.Vacia()) cout<<"La cola esta vacia"<<endl;
					 else{cout<<"La cola no esta vacia"<<endl;
					 	cola1.Ver();	
					 } 	
				break;
			case '5':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
		cout<<"\n"<<endl;
	}while(op != '5');
}
