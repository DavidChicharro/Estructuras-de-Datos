/* 4. Implementa un TDA pila usando dos colas
	¿Qué orden de eficiencia tienen las operacines push y pop?
*/

#include <iostream>
#include <queue>

using namespace std;

template <class T>
class pila{
private:
	queue<T> cola_1;
	queue<T> cola_2;

public:
	pila(){ };

	/*	Eficiencia O(1)	*/
	void push(T dato){
		cola_1.push(dato);
	}

	/*	Eficiencia O(n)	*/
	void pop(){
		while(!cola_1.empty()){
			cola_2.push( cola_1.front() );
			cola_1.pop();
		}

		int tam = cola_2.size();

		for (int i=0 ; i<tam-1 ; i++){
			cola_1.push( cola_2.front() );
			cola_2.pop();
		}
		cola_2.pop();
	}

	T top(){
		return cola_1.back();
	}

	bool empty(){
		return cola_1.empty();
	}
	
};

int main(){
	pila<int> mi_pila;

	for (int i=0 ; i<10 ; i++){
		mi_pila.push(i);
	}

	while (!mi_pila.empty()){
		cout << mi_pila.top() << " ";
		mi_pila.pop();
	}
	cout << endl;

	return 0;
}