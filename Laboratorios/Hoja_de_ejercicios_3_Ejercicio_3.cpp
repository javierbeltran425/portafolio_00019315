/*Hoja de ejercicios 3. Ejercico 3.
Laboratorio de Viernes 18.
NOTA: Hable con el licenciado sobre la subida tardia del laboratorio debido a que me chocaron mis horarios con 
con mi parcial de Calculo 3 y me dijo que estaba bien y que lo podia subir cuando pudiera ya que todo se me acumulo 
y necesitaba tiempo para salir con todo.
*/
#include<iostream>
#include<stack>
using namespace std;

//EJERCICIO 3
struct Tlista{
	string titulo;
	int numPaginas;
};
typedef struct Tlista libro;

stack<libro> s;
stack<libro> pivote;

libro solicitarLibro(){
	libro p;
	cin.ignore();
	cout << "Ingresar datos del libro." << endl;
	cout << "\tTitulo: ";
	getline(cin, p.titulo);
	cout << "\tNumero de paginas: ";
	cin >>  p.numPaginas;
	return p;
}

void mostrarLibro(string unLibro){
	libro p = s.top();
	while(p.titulo != unLibro){
		p = s.top();
		s.pop();
		pivote.push(p);
		
	}
	if(p.titulo == unLibro){
		cout << "\tTitulo: " << p.titulo << endl;
		cout << "\tPaginas: " << p.numPaginas << endl;
	}
	
	while(!pivote.empty()){
		p = pivote.top();
		pivote.pop();
		s.push(p);
		
	}
}

void agregarLibro(){
	libro p = solicitarLibro();
	s.push(p);
	
	cout << endl;
	cout << "Tamano de la pila: " <<s.size() << endl;
}

void buscarLibro(){
	string unLibro;
	cin.ignore();
	cout << "Nombre del libro: ";
	getline(cin, unLibro);
	mostrarLibro(unLibro);
}

int main(){
	bool continuar = true;
	int opcion = 0;

	do{
		cout << "Menu: " << endl;
		cout << "\t1. Agregar Libro a la pila\n\t2. Saber num de paginas de un libro\n\t3. Salir" << endl;
		cout << "Su opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1: agregarLibro(); break;
			case 2: buscarLibro(); break;
			case 3: continuar = false; break;
			default: cout << "Opcion erronea" <<endl;
		}
	}while(continuar);
	
	return 0;
}
