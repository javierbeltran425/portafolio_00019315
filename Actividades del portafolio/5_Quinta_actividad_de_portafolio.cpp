/*
MARIO ORLANDO MOISA CANDRAY 00135115
RICARDO JAVIER BELTRAN MARTINEZ 00019315
*/


#include<iostream>
using namespace std;

int mult(int num1, int num2){
	
	if(num2 == 1){
		cout << "n= " << num2 << " caso base" << endl;
		return num1;
	}else{
		
		return num1 + mult(num1, num2-1);
	}


}


int main(){
	
	cout << "Introduzca dos numeros para multiplicar: ";
	int num1=0, num2=0;
	cin >> num1;
	cin >> num2;
	
	cout << "multiplicacion de " << num1 <<"y " << num2 ;
	int m = mult(num1, num2);
	cout << "Resultado: " << m ;
	
	return 0;
}
