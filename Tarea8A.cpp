#include<iostream>
#include<cstring>
using namespace std;
bool r;
bool palindromo(string a){
	int f= a.size()-1;
	char x[0], y[0]; 
	x[0] = a[0];
	y[0] = a[f];
	if(f==0 || f == -1){
		r = true;	
		cout<<"La cadena es palindromo"<<endl;
		return r;
	}else if(a[0] == a[f]){
		r = false;
		return r;
		cout<<"La cadena no es un palindromo"<<endl;
	}else r =palindromo(a.substr(1, f));
}
int main(){
	string cad;
	cout<<"ingresa una cadena de texto: ";
	getline(cin, cad);
	palindromo(cad);
	
}
