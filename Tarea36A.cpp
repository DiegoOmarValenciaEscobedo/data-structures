#include<iostream>
#include<fstream>
#include "Cola.h"
using namespace std;
void Hash(int n, string k);
bool Primo(int);
string Array[26];
Cola<string> Num[31];
int main(){
	int I=0, aux, j=0;
	cout<< "-----Busqueda por el metodo de funciones hash-----\n\nLeyendo los datos del archivo, ";
	fstream fe("nombres-2.txt");
	while(!fe.eof()) {
		fe >> Array[I];
		I++;
	}
	fe.close(); aux = I;
	cout<<I<<" datos leidos."<<endl;
	while(!Primo(aux) || aux<(I+5)) aux++;//Se asigna aux como el numero N primo cercano al numero de elementos 
	while(j<I){//se hace el ciclo para rellenar la tabla de hash
		Hash(aux, Array[j]);// Los parametros que se mandan son (El valor de N, el valor K)
		j++;
	} 
	cout<<"N es igual a: "<<aux<<endl;
	cout<<"\n------Tabla de hash------"<<endl;
	cout<<"\nPosicion\tValores"<<endl;
	for(int i=0; i<aux; i++){ cout<<i<<"\t\t"; Num[i].Ver(); cout<<"\n\n";} 
}
void Hash(int n, string k){
	int suma=0;
	for(int i=0; i<k.length(); i++){
		char c1=k[i], c2=k[++i];
		int x=int(c1);
		suma += x*100; suma+=int(c2);//concatena los codigos ASCII de cada caracter multiplicando por 100 el primero y sumando el segundo
	}
	int b= suma%n;
	Num[b].Put(k);//En vez de ReHash usa una cola para cada clave Hash
}
bool Primo(int a){//verifica si aux es primo para usarse como N
	int b=0, c=a;
	while(c>0){
		if(a%c == 0) b++;
		c--;
	}
	return b<3;
}
