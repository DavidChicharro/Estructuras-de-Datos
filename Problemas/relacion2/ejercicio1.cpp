/*	1. Construye una funcion a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo T y que ´
modifique la pila de forma que todas las veces que aparezca x se substituya por y (quedando la pila
en el mismo estado en el que estaba anteriormente).
*/

#include <iostream>
#include <stack>
using namespace std;


template <typename T>
void funcion(stack<T> &P, T x, T y){
	stack<T> aux;

	while (!P.empty()){
		T dato = P.top();
		if (dato == x)		// Si el dato es igual al que queremos cambiar
			dato = y;		// se hace la conversión y se almacena en una variable local

		P.pop();			// Se elimina el dato en el tope de pila
		aux.push(dato); 	// Se añade el dato en la pila auxiliar
	}

	while (!aux.empty()){
		P.push(aux.top());	// Se añade en la pila original el dato almacenado en el tope de la pila auxiliar
		aux.pop();
	}
}


int main(){
	stack<double> P;

	P.push(1.0);
	P.push(3.0);
	P.push(4.0);
	P.push(5.0);
	P.push(3.0);
	P.push(2.0);
	P.push(0.0);
	P.push(3.0);
	P.push(6.0);
	P.push(1.0);
	P.push(3.0);

	funcion(P, 3.0, 10.0);
	
	while (!P.empty()){
		cout << P.top() << " ";
		P.pop();
	}
	cout << endl;

	return 0;
}