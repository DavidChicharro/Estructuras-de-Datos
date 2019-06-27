/*	9. Implementa una función insertar(P, pos, x) que inserte un elemento en una pila P en la posición pos.
La pila debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)				*/

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void insertar(stack<T> &P, unsigned pos, T x){
	if (pos < P.size()){
		stack<T> aux;

		for(unsigned i=P.size() ; i>=pos ; i--){
			aux.push( P.top() );				// Se vacía en una pila auxiliar el contenido de P hasta la posicion pos
			P.pop();
		}

		P.push(x);								// Se introduce el elemento en la posicion deseada

		while(!aux.empty()){
			P.push( aux.top() );				// Se reintroducen los elementos de la pila auxiliar en P
			aux.pop();
		}
	}
}

int main(){
	stack<int> P;

	for(int i=0 ; i<12 ; i++){
		P.push(i);
	}

	insertar(P, 5, 1000);

	while(!P.empty()){
		cout << P.top() << " ";
		P.pop();
	}
	cout << endl;

	return 0;
}