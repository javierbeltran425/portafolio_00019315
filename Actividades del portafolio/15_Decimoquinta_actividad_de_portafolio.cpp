/* DECIMOQUINTA ACTIVIDAD DE PORTAFOLIO*/
#include<iostream>
using namespace std;

struct nodo{
	int info;
	struct nodo *izq;
	struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

int numero = 0;	

Arbol crearArbol(int x){
	Arbol p = new Nodo;
	p->info = x;
	p->izq = NULL;
	p->der = NULL;
	return p;
}

void asignarIzq(Arbol a, int unDato){
	if(a == NULL){
		cout << "Error: arbol vacio" << endl;
	}else if(a->izq != NULL){
		cout << "Error: Subarbol IZQ ya existe" << endl;
	}else{
		a->izq = crearArbol(unDato);
	}
}

void asignarDer(Arbol a, int unDato){
	if(a == NULL){
		cout << "Error: arbol vacio" << endl;
	}else if(a->der != NULL){
		cout << "Error: subarbol DER ya existe" << endl;
	}else{
		a->der = crearArbol(unDato);
	}
}

void agregarNodo(Arbol a, Arbol b){

	cout << "Numero a agregar: ";
	cin >> numero;
	Arbol p = a;
	Arbol q = b;
	while(true){
		if(numero == p->info && numero == q->info){
			cout << "Error: " << numero << " ya existe" << endl;
			return;
		}else if(numero < p->info){
			if(p->izq == NULL){
				break;
			}else{
				p = p->izq;
				q = q->der;
			}
		}
		else{
			if(p->der == NULL){
				break;
			}else{
				p = p->der;
				q = q->izq;
			}
		}
	}
	if(numero < p->info){
		asignarIzq(p, numero);
		asignarDer(q, numero);
	}else{
		asignarDer(p, numero);
		asignarIzq(q, numero);
	}
}


void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}

void inordenEspejo(Arbol b){
    if(b != NULL){
        inorden(b->izq);
        cout << " " << b->info;
        inorden(b->der);
    }
}

int main(){
	int variable = 0;
	bool continuar = true;
	cout << "Iniciando arbol...\nValor contenido en la raiz: ";
	cin >> variable;
	Arbol arbol = crearArbol(variable);
	Arbol arbolEspejo = crearArbol(variable);
	do{
		int opcion;
		cout << "\nMenu: " << endl;
		cout << "\t1. Agregar elemento\n\t2. Recorrer arbol (inorden)\n\t3. Ver espejo\n\t4. salir\nOpcion: ";
		cin >> opcion;
		switch(opcion){
			case 1: agregarNodo(arbol, arbolEspejo); break;
			case 2: inorden(arbol); break;
			case 3: inordenEspejo(arbolEspejo); break;
			case 4: continuar = false; false;
		}
	}while(continuar);
}
