/*	15. Implementa una función bintree<int>::node ancestro_comun(bintree<int>::node n1,
	bintree<int>::node n2)  que devuelva el nodo que sea el primer ancestro común a los 
	nodos n1 y n2. La eficiencia debe ser proporcional a la altura del árbol.		*/


#include <iostream>
#include <queue>
#include <bintree.h>
using namespace std;


bintree<int>::node ancestro_comun(bintree<int>::node n1, bintree<int>::node n2){
	queue<bintree<int>::node> cola;
	bool encontrado = false;
	bintree<int>::node n,	aux1 = n1, aux2;

	while(!aux1.parent().null()){
		aux1 = aux1.parent();
		cola.push(aux1);
	}

	while(!cola.empty() && !encontrado){
		aux2 = n2;
		while(!aux2.null() && !encontrado){
			if(cola.front() == aux2){
				n = cola.front();
				encontrado = true;
			}
			aux2 = aux2.parent();
		}
		cola.pop();
	}

	return n;
}


int main(){
	bintree<int>::node n1, n2;
  // BST
  bintree<int> arb(7);
  arb.insert_left(arb.root(), 4);
  arb.insert_left(arb.root().left(), 2);
  arb.insert_left(arb.root().left().left(), 1);
  arb.insert_right(arb.root().left().left(), 3);
  arb.insert_right(arb.root().left(), 6);
  arb.insert_left(arb.root().left().right(), 5);
  arb.insert_right(arb.root(), 12);
  arb.insert_left(arb.root().right(), 10);
  arb.insert_left(arb.root().right().left(), 9);
  arb.insert_right(arb.root().right().left(), 11);
  arb.insert_right(arb.root().right(), 14);
  arb.insert_left(arb.root().right().right(), 13);
  arb.insert_right(arb.root().right().right(), 15);

  n1 = arb.root().left().left().left();
  n2 = arb.root().right().left().right();

	cout << "Los nodos son : " << *n1 << " y " << *n2 << endl;
  bintree<int>::node n = ancestro_comun(n1, n2);

  if(!n.null())
  	cout << "El ancestro común es el nodo con etiqueta: " << *n << endl;
  else
  	cout << "No tienen ancestro común." << endl; 

  return 0;
}