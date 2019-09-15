#include<iostream>
using namespace std;

int mcd(int mayor, int menor){
	int res = -1;
	
	res = mayor % menor;
	
	if(res == 0){
		return menor;
	}else{
		mayor = menor;
		menor = res;
		
		return mcd(mayor, menor);
	}
}

int main(){
	int mayor = 0;
	int menor = 0;
	
	cout << "introduzca dos numeros enteros." << endl << endl;
	cout << "Numero mayor: ";
	cin >> mayor;
	cout << endl;
	cout << "Numero menor: ";
	cin >> menor;
	cout << endl;
	cout << "El MCD es: " << mcd(mayor, menor);
}
