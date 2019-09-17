//TORRES DE HANOI
#include<iostream>
using namespace std;

void solucion(int disco, int torre1, int torre2, int torre3){
	if(disco == 1){
		cout << "Mover disco de la torre " << torre1 << " hacia la torre " << torre3 << endl;
	}else{
		solucion(disco - 1, torre1, torre3, torre2);
		cout << "Mover disco dela torre " << torre1 << " hacia la torre " << torre3 << endl;
		solucion(disco - 1, torre2, torre1, torre3);
	}
}

int main(){
	char jugar;
	
	do{
		int discos = 0, torre1 = 1, torre2 = 2, torre3 = 3;
		cout << "Numero de discos: "; //Definiendo la cantidad de discos en juego
		cin >> discos;
		solucion(discos, torre1, torre2, torre3);
		cout << endl;
		cout << "Desea volver a jugar?, presione 'S' para o 'N' para no: ";
		cin >> jugar;
	}while(jugar == 'S' || jugar =='s');
	
	
	return 0;
}
