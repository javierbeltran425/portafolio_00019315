#include<iostream>
using namespace std;


int a[8] = {1, 3, 4, 5, 17, 18, 31, 33};

int recibir(int x, int low, int high){
	int mid;
	
	if(low > high){
		return -1;
	}
	
	mid = (low + high)/2;
	
	if(x == a[mid]){
		return mid;
	}
	
	if(x < a[mid]){
		return recibir(x, low, mid -1);
		
	}else{
		return recibir(x, mid +1, high);
	}
}


int main(){
	
	int low = 0;
	int high = 8 - 1;
	int x = 0;
	
	cout << "Ingrese un numero entero a buscar en el arreglo: ";
	cin >> x;	
	
	int i = recibir(x, low, high);
	
	if(i == -1){
		cout << "Numero no encontrado";
	}else{
		cout << "el elemento se encuentrra en la casilla: " << i << endl;
	}
	
}
