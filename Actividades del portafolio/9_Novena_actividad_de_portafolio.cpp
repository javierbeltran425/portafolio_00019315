#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<string> s;
	string i;
	char next;
	do{
		cout << "Ingrese el elemento: ";
		cin >> i;
		s.push(i);
		cout << "Se ha agregado un elemento" << endl << endl << "Desea agregar otro elemento? s/n: ";
		cin >> next;
		cout << endl;
	}while(next == 's' || next == 'S');
	cout << "Cantidad de elementos en la pila: " << s.size() << endl;
	
	int tamano = s.size();
	
	for(int j = tamano; j > 0; j--){
		cout << "Elemento superior: " << s.top() << endl;
		s.pop();
		cout << "Cantidad de elementos en la pila: " << s.size() << endl;
	}
	cout << endl;
	
	if(s.empty()){
		cout << "La pila esta vacia" << endl;
	}else{
		cout << "La pila no esta vacia" << endl;
	}
	return 0;
}
