/*	2. Escribe una función que acepte un valor de tipo node y un 
	árbol general T y devuelva el nivel del nodo en el arbol.	*/

#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T>
void recorridos(const bintree<T> &arb) {
  cout << endl << "Tamaño: " << arb.size() << endl;
  cout << "preorden: ";
  for (bintree<int>::const_preorder_iterator it= arb.begin_preorder(); it!=arb.end_preorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "postorden: ";
  for (bintree<int>::const_postorder_iterator it= arb.begin_postorder(); it!=arb.end_postorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "inorden: ";
  for (bintree<int>::const_inorder_iterator it= arb.begin_inorder(); it!=arb.end_inorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "niveles: ";
  for (bintree<int>::const_level_iterator it= arb.begin_level(); it!=arb.end_level(); ++it)
	  cout << *it << " ";
  cout << endl;
}

template <typename T>
int nivel_nodo(const bintree<T> & A, const typename bintree<T>::node &v) {
	int nivel = 0;
	typename bintree<T>::node aux = v.parent();

	while(!aux.null()){
		nivel ++;
		aux = aux.parent();
	}

	return nivel;
}

int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().right().right(), 6);

  bintree<int>::node n = arb.root().right().left(); // nodo con etiqueta 6
  
  recorridos(arb);

  int nivel = nivel_nodo(arb, n);

  cout << "El nivel del nodo es: " << nivel << endl;

  return 0;
}