/*Hoja de ejercicios 3. Ejercico 7.
Laboratorio de Viernes 11.
NOTA: Hable con el licenciado sobre la subida tardia del laboratorio debido a que me chocaron mis horarios con 
con un corto de Matematica discreta 2 y me dijo que estaba bien y que lo podia subir cuando pudiera ya que todo se me acumulo 
y necesitaba tiempo para salir con todo.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int>p;

int solicitarNumero(){
	int num = 0;
	cout << "Ingrese un entero: ";
	cin >> num;
	
	return num;
}

void agregarNumero(){
	int num = 0;
	int aux;
	num = solicitarNumero();
	
	p.push_back(num);

}

void mostrarLista(){
	cout << "Datos ingresados: " << endl;
	
	for(int i = 0; i < p.size(); i++){
		cout << "\t" << p.at(i) << endl;
	}
}

void recorrerLista(){
	vector<int>::iterator t;
	int pivote = 0;
	for(int i = 0; i < p.size(); i++){
		pivote = p.at(i);
		for(int j = i + 1; j < p.size(); j++){
			if(p.at(j) == pivote){
				t = p.begin() + j;
				p.erase(t);
			}
		} 
	}
}

int main(){
	bool continuar = true;
	
	do{
		char opcion;
		cout << "Menu: " << endl;
		cout << "\ta. Ingresar un entero.\n\tb. Mostrar lista.\n\tc. Eliminar ocurrencias.\n\td. Salir." << endl;
		cout << "Su opcion: ";
		cin >> opcion;
		switch(opcion){
			case 'A': ;
			case 'a': agregarNumero(); break;
			case 'B': ;
			case 'b': mostrarLista(); break;
			case 'C': ;
			case 'c': recorrerLista(); break;
			case 'D': ;
			case 'd': continuar = false; break;
			default: cout << "Opcion erronea" << endl;
		}
	}while(continuar);
	
	return 0;
}
