/*	10. Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la posición pos.
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)				  */

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void insertar(queue<T> &Q, unsigned pos, T x){
	if(pos <= Q.size()){
		queue<T> aux;

		while(!Q.empty()){
			aux.push( Q.front() );
			Q.pop();
		}

		unsigned tam = aux.size();
		for (unsigned i=0 ; i<=tam ; i++){
			if (i!=(pos)){
				Q.push( aux.front() );
				aux.pop();
			}
			else
				Q.push(x);
		}
	}
}

int main(){
	queue<int> Q;

	for(unsigned i=1 ; i<=10 ; i++)
		Q.push(i);

	insertar(Q, 5, 100);

	while(!Q.empty()){
		cout << Q.front() << " ";
		Q.pop();
	}
	cout << endl;

	return 0;
}