#include<iostream>
#include<string>
using namespace std;
int ascii;
string cadena;
int main(){
cout<<"ingresa una cadena de caracteres: ";
getline(cin, cadena);
cout<<"\n\nCaracteres	codigo ASCII"<<endl;

	for(int i=0; i<cadena.length(); i++){
		printf("\n %c	\t %d", cadena.at(i), cadena.at(i));
		
	}
	
}
