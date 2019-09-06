#include<iostream>
using namespace std;

// EJECICIO 16

/*
float s = 0;

int suma(int a[]){
	
	for(int i = 0; i<10; i++){
		s = s + a[i];
	}	
	return s;
}

int promedio(int a[], float s){
	int prom = 0;
		
	prom = s / 10;
	
	return prom;
}

int main(){
	int a[10];
	
	cout << "Ingrese 10 enteros: " << endl << endl;
	
	for(int i = 0; i < 10; i++){
		cout << "Igrese el " << i + 1 << " entero: "<< endl;
		cin >> a[i];
	}	
	
	cout << "La suma de los enteros es: " << suma(a);
	cout << endl << endl;
	cout <<"El promedio es: " << promedio(a, s);
	
	return 0;
}
*/
// EJERCICIO 26

struct complejo{
	float r = 0;
	float i = 0;
};

int conjugada(complejo complex){
	float conjug = 0;
	
	conjug = -1 * complex.i;
	
	return conjug;
}


int main(){
	float c = 0, a = 0;
	complejo complex;
	cout << "Digite la parte real: ";
	cin >> complex.r;
	cout << endl << endl;
	cout << "Digite la parte imaginaria: ";
	cin >> complex.i;
	
	if(complex.i >= 0){
	cout << "El numero complejo ingresado es: " << complex.r << " + " << complex.i << "i";	
	}else{
		a = complex.i;
		a = -1 * complex.i;
		cout << endl;
		cout << "El numero complejo ingresado es: " << complex.r << " - " << a << "i";	
	}
	
	cout << endl << endl;
	
	if(conjugada(complex) >= 0){
	cout << "La conjugada del numero complejo es: " << complex.r << " + " << conjugada(complex) << "i";	
	}else{
		c = -1 * conjugada(complex);
		cout << "La conjugada del numero complejo es: " << complex.r << " - " << c << "i";	
	}

	return 0;	
}
