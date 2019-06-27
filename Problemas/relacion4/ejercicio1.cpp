/*	1. Escribe una función que determine cuál es la hoja más profunda de un árbol binario.	*/

#include <iostream>
#include "bintree.h"

using namespace std;


template <typename T>
typename bintree<T>::node profundidad(const bintree<T> & A) {
	typename bintree<T>::node n;

	for (typename bintree<T>::const_level_iterator it= A.begin_level(); it!=A.end_level(); ++it)
		n = *it;

	return n;
}

int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().right().right(), 6);


  bintree<int>::node nodo_prof = profundidad(arb);

  cout << "El nodo más profundo es: " << *nodo_prof << endl;

  return 0;
}