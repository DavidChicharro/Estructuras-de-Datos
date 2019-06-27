// 3. Implementa un TDA cola usando como representacion dos pilas

#include <iostream>
#include <stack>

using namespace std;

template <class T>
class cola{
private:
	stack<T> pila_1;
	stack<T> pila_2;

public:
	cola() { }

	void push(T dato){
		pila_1.push(dato);
	}

	void pop(){
		while(!pila_1.empty()){
			pila_2.push( pila_1.top() );		// Se introducen los elementos de la pila 1 en la pila 2
			pila_1.pop();						// de modo que se reinvierten y quedan como una cola
		}

		pila_2.pop();

		while(!pila_2.empty()){
			pila_1.push( pila_2.top() );		// Se vuelven a introducir los datos en la pila 1, excepto el que había en el tope
			pila_2.pop();
		}
	}

	T front(){
		T dato;
		while(!pila_1.empty()){
			pila_2.push( pila_1.top() );
			pila_1.pop();
		}
		
		dato = pila_2.top();
		
		while(!pila_2.empty()){
			pila_1.push( pila_2.top() );
			pila_2.pop();
		}

		return dato;
	}

	T back() {
		return pila_1.top();
	}

	bool empty(){
		return pila_1.empty();
	}
};

int main(){
	cola<int> mi_cola;

	for (int i=0 ; i<10 ; i++){
		mi_cola.push(i);					// Se introducen los elementos en la cola
	}

	while (!mi_cola.empty()){
		cout << mi_cola.front() << " ";
		mi_cola.pop();
	}
	cout << endl;

	return 0;
}