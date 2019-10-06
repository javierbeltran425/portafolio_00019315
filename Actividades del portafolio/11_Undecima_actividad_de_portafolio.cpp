#include<iostream>
using namespace std;

int n = 0, frente = 0, maximo = 0, tamano = 0;
int menu(string unaCola[]);

int sacarDato(string unaCola[]){
	string aux = unaCola[frente];
	cout << "Sale el elemento: " << aux << endl << endl;
	frente=(frente+1)%maximo;
	n--;
	menu(unaCola);
	return 0;
}

int entradaDatos(string unaCola[]){

	string dato;
	char elemento;
	
	do{
		if(n==maximo){
			cout << "La cola esta llena" << endl << endl;
			menu(unaCola);
			
			return 0;
		}else{
			int ubicacion = (frente+n)%maximo;
			cout << "Ingrese el dato: ";
			cin >> dato;
			cout << endl;
			unaCola[ubicacion] = dato;
			n++;
			cout << "Desea agregar otro elemento? s/n: ";
			cin >> elemento;
			cout << endl;
		}

	}while(elemento == 's' || elemento == 'S');
	menu(unaCola);
}

void mostrarCola(string unaCola[]){
	for(int i = 0; i < tamano; i++){
		cout << unaCola[i] << endl;
	}
	menu(unaCola);
}
int menu(string unaCola[]){
	int opcion;
	
	cout << "Que desea hacer?" << endl;
	cout << "1. Ingresar dato. \n2. Sacar dato. \n3. Ver mi cola. \n" << endl<< "Elija la opcion: ";
	cin >> opcion;
	
	switch(opcion){
		case 1: entradaDatos(unaCola); break;
		case 2: sacarDato(unaCola); break;
		case 3: mostrarCola(unaCola); break;
	}
	return 0;
}

int main(){

	cout << "Especifique el tamano que tendra la cola: ";
	cin >> tamano;
	maximo = tamano;
	string unaCola[tamano];
	menu(unaCola);
	
	return 0;
}
