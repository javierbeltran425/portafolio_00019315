#include<iostream>
using namespace std;

int n = 0;
int a = 0;
int c = 0;

int conteo(int n){
	
	if(n == 1){
		a = a + 1;
		cout << a << endl;
		for(int i = c - 1; i >= n; i--){
			cout << i << endl;
		}
	}else{
		if(n != 1){
			a = a + 1;
			cout << a << endl;
		}
		return conteo(n - 1);	
	}
}

int main(){
		
	cout <<"Digite un numero: ";
	cin >> n;
	c = n;
	
	conteo(n);
	
	return 0; 
}
