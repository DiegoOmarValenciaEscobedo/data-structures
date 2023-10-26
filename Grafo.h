#include<iostream>
using namespace std;
struct Arista{
	int Peso;
	int Origen;
	int Destino;
	int Clave;
};
struct Nodo{
	public:
	Arista A1;
	Nodo *sig;
	Nodo(Arista);
};
Nodo::Nodo(Arista a){
	A1 = a;
	sig = NULL;
}
class Grafo{
	public:
	Nodo *ini;
	Grafo();
	~Grafo();
	void Ver();
	bool Vacia();
	void Insertar(Arista);
	void Eliminar(int);
};
Grafo::Grafo(){
	ini = NULL;
}
Grafo::~Grafo(){
	Nodo *tmp;
	while(ini){
		tmp=ini;
		ini=ini->sig;
		delete(tmp);
	}
}
void Grafo::Ver(){
	if(ini == NULL) cout<<"Grafo vacio"<<endl;
	else{
		Nodo *aux = ini;
		cout<<"\tClave\tOrigen\tDestino\tPeso"<<endl;
		while(aux){
			cout<<"\t"<<aux->A1.Clave<<"\t"<<aux->A1.Origen<<"\t"<<aux->A1.Destino<<"\t"<<aux->A1.Peso<<endl;
			aux = aux->sig;
		}
	}
}
bool Grafo::Vacia(){
	return ini==NULL;
}
void Grafo::Insertar(Arista x){
	Nodo *aux = ini;
	Nodo*ant;
	Nodo *nvo = new Nodo(x);
	if(ini == NULL || x.Peso <= aux->A1.Peso){
		if(ini == NULL)ini = nvo;
		else{
			nvo->sig = aux;
			ini = nvo;
		}
	}else{
		while(aux->sig && x.Peso > aux->A1.Peso){
			ant = aux;
			aux = aux->sig;	
		} 
		if(x.Peso>aux->A1.Peso) aux->sig=nvo;		
		else{
			ant->sig=nvo;
			nvo->sig=aux;
		}
	}
}
void Grafo::Eliminar(int v){
	Nodo *tmp, *ant;
	ant = tmp = ini;
	while(tmp && tmp->A1.Clave != v){
		ant = tmp;
		tmp = tmp->sig;
	}
	if(!tmp || tmp->A1.Clave != v){
		//cout<<"El vertice "<<v<<" no se encuentra en la lista"<<endl;
	}else{
		if(tmp == ini){
			ini = tmp->sig;
		}else{
			ant->sig =tmp->sig;
		}
		delete tmp;
		//cout<<"Se ha eliminado el Vertice "<<v<<endl;
		if(Vacia())cout<<"Lista vacia"<<endl;
	}
}
