#include<iostream>
using namespace std;
template <class T>
struct Nodo2{
	T info;
	Nodo2 <T> *sig;
	Nodo2(T);
};
template <class T>
struct Nodo{
	T info;
	Nodo <T> *sig;
	Nodo2 <T> *abajo; 
	Nodo(T);
};
template <class T>
Nodo<T>::Nodo(T v){
	info = v;
	sig = NULL;
	abajo = NULL;
	 
}
template <class T>
Nodo2<T>::Nodo2(T v){
	info = v;
	sig = NULL;
}
template<class T>
class Autos{
	private: Nodo<T> *ini;
	public: 
	Autos();
	~Autos();
	void Ins_marca(T);
	void Ins_mod(T, T);
	T Eli_marca(T);
	T Eli_mod(T, T);
	void Ver();
	bool Vacia();	
};
template<class T>
Autos<T>::Autos(){
	ini = NULL;
}
template<class T>
Autos<T>::~Autos(){
	while(!Vacia()){
		Nodo <T> *sale = ini;
		ini = ini->sig;
		if(sale->abajo){
			Nodo2<T> *ant2, *sale2=sale->abajo;
			while(sale2 != NULL){
				ant2 = sale2;
				sale2 = ant2->sig;
				delete(ant2);
			}
		}
		delete(sale);
	}
}
template<class T>
void Autos<T>::Ins_marca(T v){
	if(Vacia() || ini->info > v){
		Nodo<T> *nvo = new Nodo<T>(v);
		nvo->sig = ini;
		ini=nvo;	
		cout<<"Se ha insertado la marca "<<v<<endl;
	}
	else{
		Nodo<T> *ant, *tmp = ini;
		while(tmp->sig && tmp->info < v){
			ant = tmp;
			tmp = tmp->sig;
		}
		if(tmp->info != v){
			Nodo<T> *nvo= new Nodo<T>(v);
			if(tmp->info<v){
				nvo->sig = tmp->sig;
				tmp->sig = nvo;
			}else{
				nvo->sig = ant->sig;
				ant->sig = nvo;	
			}
		}
		
	}
}
template<class T>
void Autos<T>::Ins_mod(T v, T m){
	Nodo<T> *tmp = ini;
	while(tmp->sig && tmp->info<v)tmp=tmp->sig;
	if(tmp->info == v){
		if(!tmp->abajo || tmp->abajo->info > m){
			Nodo2<T> *nvo = new Nodo2<T>(m);
			nvo->sig = tmp->abajo;
			tmp->abajo=nvo; 
			cout<<"Hemos insertado el modelo "<<m<<" de la marca "<<v<<endl;
		}else{
			Nodo2<T> *ant2, *tmp2 = tmp->abajo;
			while(tmp2->sig && tmp2->info < m){
				ant2 = tmp2;
				ant2 = tmp2->sig;
			}
			if(tmp2->info == m) cout<<"El modelo "<<m<<" de la marca "<<v<<" ya estaba ingresada"<<endl;
			else{
				Nodo2<T> *nvo = new Nodo2<T>(m);
				if(tmp2->info<m){
					nvo->sig = tmp2->sig;
					tmp2->sig = nvo;
				}else{
					nvo->sig = ant2->sig;
					ant2->sig = nvo;
				}
			}
		}
	} 	
}
template<class T>
T Autos<T>::Eli_marca(T v){
	Nodo<T> *tmp, *ant;
	tmp = ant = ini;
	while(tmp && tmp->info<v){
		ant = tmp; 
		tmp = tmp->sig;
	}
	if(!tmp || tmp->info != v) cout<<"La marca "<<v<<" no existe en la lista"<<endl;
	else{
		if(tmp ==ini) ini = tmp->sig;
		else ant->sig = tmp->sig;
		if(tmp->abajo){
			Nodo2<T> *ant2, *tmp2 = tmp->abajo;
			while(tmp2 != NULL){
				ant2 = tmp2;
				tmp2 = tmp2->sig;
				cout<<"Se ha eliminado el modelo "<<ant2->info<<" de la marca "<<v<<endl;
				delete(ant2); 
			} 
		}
	delete(tmp);
	cout<<"Se ha eliminado la marca "<<v<<endl;
	}
	if(Vacia())cout<<"La lista esta vacia"<<endl;
}
template<class T>
T Autos<T>::Eli_mod(T v, T m){
	Nodo<T> *tmp, *ant;
	ant = tmp = ini;
	while(tmp && tmp->info<v){
		ant = tmp; 
		tmp = tmp->sig;
	}
	if(!tmp || tmp->info !=v)cout<<"La marca "<<v<<" no existe en la lista"<<endl;
	else{
		if(tmp->abajo){
			Nodo2<T> *ant2, *tmp2;
			ant2 = tmp2 = tmp->abajo;
			while(tmp2 && tmp2->info<m){
				ant2 = tmp2;
				tmp2 = tmp2->sig;
			}
			if(!tmp || tmp->info != m)cout<<"El modelo "<<m<<" de la marca "<<v<<" no existe"<<endl;
			else{
				if(tmp2 = tmp->abajo) tmp->abajo = tmp2->sig;
				else ant2->sig = tmp2->sig;
				cout<<"Se elimino el modelo "<<m<<" de la marca "<<v<<endl;
				delete(tmp2);
			}
		}
		else cout<<"La marca "<<v<<" no tiene modelos";
	}
}
template<class T>
bool Autos<T>::Vacia(){
	return ini==NULL;
}
template<class T>
void Autos<T>::Ver(){
	Nodo<T> *tmp = ini;
	while(tmp){
		cout<<tmp->info<<endl;
		if(tmp->abajo != NULL){
			Nodo2<T> *tmp2 = tmp->abajo;
			while(tmp2){
				cout<<tmp2->info<<endl;
				tmp2 = tmp2->sig;
			}
		}else cout<<"Sin modelos"<<endl;
		tmp = tmp->sig;
	}
	cout<<endl;
}
int main(){
    char op;
	string name1, name2;
    Autos<string> a1;
	do{
		cout<<"\n1 Insertar Marca"<<endl;
		cout<<"2 Insertar modelo"<<endl;
		cout<<"3 Eliminar marca"<<endl;
		cout<<"4 Eliminar modelo"<<endl;
		cout<<"5 Mostrar"<<endl;
		cout<<"6 salir"<<endl;
		cout<<".- ";
		cin>>op;
		switch(op){
			case '1':cout<<"Ingresa la nueva marca: "; cin>>name1;
					a1.Ins_marca(name1);
				break;
			case '2':cout<<"Ingresa la marca del modelo: "; cin>>name1;
					cout<<"Ingresa el nuevo modelo: "; cin>>name2;
					a1.Ins_mod(name1, name2);
				break;
			case '3':if(a1.Vacia()) cout<<"La lista esta vacia"<<endl;
					cout<<"Ingresa la marca a eliminar: "; cin>>name1;
					a1.Eli_marca(name1);
			case '4':if(a1.Vacia()) cout<<"La lista esta vacia"<<endl;
					cout<<"Ingresa la marca del modelo a eliminar: "; cin>>name1;
					cout<<"Ingresa el modelo a eliminar: "; cin>>name2;
					a1.Eli_mod(name1, name2);
				break;
			case '5':cout<<"<\nMarcas \n"<<endl; a1.Ver();
				break;
			case '6':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default:cout<<"Opcion invalida"<<endl;
		}
	}while(op != '6');	
}
