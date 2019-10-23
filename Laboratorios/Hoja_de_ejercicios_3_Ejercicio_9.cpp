/*
Hoja de ejercicios 3. Ejercico 9.
Laboratorio de Viernes 18.
NOTA: Hable con el licenciado sobre la subida tardia del laboratorio debido a que me chocaron mis horarios con 
con mi parcial de Calculo 3 y me dijo que estaba bien y que lo podia subir cuando pudiera ya que todo se me acumulo 
y necesitaba tiempo para salir con todo.
*/
#include<iostream>
#include<string>
using namespace std;

struct Persona{
	string carnet;
	int edad;
	int telefono;
	string nombre, apellido, correo;
};
typedef struct Persona personas;

personas solicitarPersonas(){
	personas p;
	cout << "Ingrese los datos de la persona:" <<endl;
	cout << "\t1. Carnet: ";
	cin >> p.carnet;
	cin.ignore();
	cout << "\t2. Nombres: ";
	getline(cin, p.nombre);
	cout << "\t3. Apellidos: ";
	getline(cin, p.apellido);
	cout << "\t4. Edad: ";
	cin >> p.edad;
	cout << "\t4. Telefono: ";
	cin >> p.telefono;
	cin.ignore();
	cout << "\t5. Correo: ";
	getline(cin, p.correo);
	cout << endl;
	return p;
}
struct TNodo{
    personas dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(personas p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(personas p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void insertarDespuesDe(personas p) {
    string unCarnet;
    cout << "Carnet de la persona de referencia: ";
    cin >> unCarnet;
    
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).carnet != unCarnet)
        s = s->sig;
    if(s == NULL){
        cout << "Persona de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;
    
    s->sig = nuevo;
    cout << "Persona insertada con exito" << endl;
}

void insertarAntesDe(personas p) {
    string unCarnet;
    cout << "Carnet de la persona de referencia: ";
    cin >> unCarnet;
    
    Nodo *s = pInicio, *q = NULL;
    
    while(s != NULL && (s->dato).carnet != unCarnet){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "La persona de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;
    
    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Persona insertada con exito" << endl;
}


void agregarPersonas(){
	personas p = solicitarPersonas();
	bool continuar = true;
	do{
		int opcion = 0;
		cout << "\t1. Al inicio\n\t2. Despues de...\n\t3. Antes de...\n\t4. Al final" << endl;
		cout << "Su opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1: insertarInicio(p); continuar = false; break;
			case 2: insertarDespuesDe(p); continuar = false; break;
			case 3: insertarAntesDe(p); continuar = false; break;
			case 4: insertarFinal(p); continuar = false; break;
			default: cout << "Opcion erronea" << endl; break;
		}
	}while(continuar);
}
void mostrarPersona(personas p){
    cout << "Carnet: " << p.carnet << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Telefono: " << p.telefono << endl;
    cout << "Correo: " << p.correo << endl;
    cout << endl;
}

void mostrarPersonas() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarPersona(s->dato);
        s = s->sig;
    }
}

void eliminarPersona(){
    string unCarnet;
    cout << "Carnet de la persona a eliminar: ";
    cin >> unCarnet;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).carnet != unCarnet){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "La persona a eliminar no existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Persona elimanada" << endl;
}

void actualizarPersona(){
    string unCarnet;
    cout << "Carnet de la persona a actualizar: ";
    cin >> unCarnet;
    
    Nodo *s = pInicio;

    while(s != NULL && (s->dato).carnet != unCarnet)
        s = s->sig;
    
    if(s != NULL){
    	s->dato = solicitarPersonas();
	}else{
		cout << "La personas no existe" << endl;
	}
}

int main(){
	bool continuar = true;
	pInicio = NULL;
	do{
		char opcion;
		cout << "Menu: " << endl;
		cout << "\n\ta. Llenar lista\n\tb. Eliminar persona\n\tc. Actualizar datos de una persona\n\td. Mostrar todas las personas\n\te. Salir" << endl;
		cout << "Su opcion: ";
		cin >> opcion;
		switch(opcion){
			case 'a': agregarPersonas(); break;
			case 'b': eliminarPersona(); break;
			case 'c': actualizarPersona(); break;
			case 'd': mostrarPersonas(); break;
			case 'e': continuar = false; break;
		}
	}while(continuar);
	return 0;
}
