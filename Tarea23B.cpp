#include<iostream>
using namespace std;
template<class T>
class ArrayHeap{
	private:
	T Array[30];
	int cont;
	public:
	ArrayHeap();
	void Insertar(T);
	void Eliminar();
	void Ver();
};
template<class T>
ArrayHeap<T>::ArrayHeap(){
	cont = 0;
}
template<class T>
void ArrayHeap<T>::Insertar(T v){
	if(cont == 0){
		Array[cont] = v;
		cont++;
	}else{
		int padre, hijo;
		T cambio;
		Array[cont] = v;
		hijo = cont;
		padre = (hijo-1)/2;
		cont++;
		while(hijo != 0 && Array[hijo] < Array[padre]){
			cambio = Array[hijo];
			Array[hijo] = Array[padre];
			Array[padre] = cambio;
			hijo = padre;
			padre = (hijo-1)/2;	
		}
	}
	cout<<"Se inserto el valor"<<endl;
}	
template<class T>
void ArrayHeap<T>::Eliminar(){
	if(cont == 0) cout<<"Heap vacio"<<endl;
	else{
		/*int j=1;
		for(int i=0; i<cont; i++){
			Array[i] = Array[j];
			j++;
		}*/
		
		int padre, hijo1, hijo2, menor;
		T aux;
		Array[0] = Array[cont-1];
		Array[cont-1] = Array[cont];
		padre=0; hijo1 = (2*padre)+1; hijo2 = (2*padre)+2;
		if(Array[hijo1] > Array[hijo2]) menor = hijo2;
		else menor = hijo1;
		while((Array[hijo1] != 0 && Array[hijo2] != 0) || Array[menor]>Array[padre]){
			if(Array[hijo1] > Array[hijo2]){
				aux = Array[padre];
				Array[padre] = Array[hijo2];
				Array[hijo2] = aux;
				padre = hijo2; hijo1 = (2*padre)+1; hijo2 = (2*padre)+2;
			}else{
				aux = Array[padre];
				Array[padre] = Array[hijo1];
				Array[hijo1] = aux;
				padre = hijo1; hijo1 = (2*padre)+1; hijo2 = (2*padre)+2;
			}
		}
		cont--;
		cout<<"Se elimino la cima del heap"<<endl;
	}
}
template<class T>
void ArrayHeap<T>::Ver(){
	if(cont == 0)cout<<"Heap vacio"<<endl;
	else{
		for(int i=0; i<cont;i++){
			if(Array[i] != 0)cout<<"\t"<<Array[i];
		}
		cout<<endl;
	}
}
int main(){
	char op;
	int valor;
	ArrayHeap<int> H1;
	do{
		cout<<"1. Ingresar"<<endl;
		cout<<"2. Eliminar"<<endl;
		cout<<"3. Mostrar monticulo"<<endl;
		cout<<"4. salir"<<endl;
		cout<<": "; cin>>op;
		switch(op){
			case '1': cout<<"Ingresa el valor del nodo: "; cin>>valor;
					H1.Insertar(valor);
				break;
			case '2':
					H1.Eliminar();
				break;
			case '3': H1.Ver();
				break;
			case '4':cout<<"Saliste de la aplicacion"<<endl;
				break;
			default: cout<<"Opcion invalida"<<endl;
		}
		cout<<endl;
	}while(op != '4');
}
