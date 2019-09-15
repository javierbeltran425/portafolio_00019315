#include<iostream>
using namespace std;

int digitos(int n){
	
	if(n < 10){
		return 1;
	}else{
		return 1 + digitos(n/10);
	}
}

int main(){
	int entero;
	
	cout << "Introduzca un numero entero: ";
	cin >> entero;
	
	cout << "El numero tiene " << digitos(entero) << " digitos.";
	return 0;
}
