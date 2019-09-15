#include <iostream>
using namespace std;

struct Tpila{
	float elements[100];
	int top;
};
typedef struct Tpila Pila;

void initialize(Pila *s){
	s->top = -1;
}

bool empty(Pila *s){
	return s->top < 0;
}

void push(Pila *s, float e){
	if(s->top < 99){
		(s->top)++;
		s->elements[s->top] = e;
	}
}

void pop(Pila *s, float *e){
	if(s->top >= 0){
		*e = s->elements[s->top];
		(s->top)--;
	}
}

float ultimoelemento(Pila *s){
	float a = 0;
	while(!empty(s))
		pop(s, &a);
	return a;
}

int main()
{
	Pila unaPila;
	initialize(&unaPila);
	
	if(empty(&unaPila))
		cout << "Esta vacia" << endl;
	
	float x = 5.6;
	push(&unaPila, x);
	
	if(empty(&unaPila))
		cout << "Esta vacia" << endl;
	
	float y = 0;
	pop(&unaPila, &y);
	
	if(empty(&unaPila))
		cout << "Esta vacia" << endl;
	
	push(&unaPila, 1.2);
	push(&unaPila, 3.4);
	push(&unaPila, 7.8);
	
	cout << "Ultimo elemento: " << ultimoelemento(&unaPila) << endl;

}
