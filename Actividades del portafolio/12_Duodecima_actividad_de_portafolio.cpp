#include <iostream>
#include <vector>
using namespace std;

struct Orden{
    int revueltas;
    int frijolConQueso;
    int queso;
    int arroz;
};
typedef struct Orden Ordenar;

Ordenar solicitarOrden(){
    Ordenar p;
    cout << "Revueltas: "; cin >> p.revueltas;
    cout << "Frijol con queso: "; cin >> p.frijolConQueso;
    cout << "Queso: "; cin >> p.queso;
    cout << "Arroz: "; cin >> p.arroz;
    return p;
}

void mostrarOrden(Ordenar p){
    cout << "Revueltas: " << p.revueltas << endl;
    cout << "Frijol con queso: " << p.frijolConQueso << endl;
    cout << "Queso: " << p.queso << endl;
    cout << "Arroz: " << p.arroz << endl;
    cout << endl;
}

vector<Ordenar> lista;

void agregarOrden(){
    Ordenar p = solicitarOrden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), p);
                continuar = false;
            break;
            case 2: lista.push_back(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++) 
        mostrarOrden(lista[i]);
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Orden\n\t2) Ver Ordenes"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarOrden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
