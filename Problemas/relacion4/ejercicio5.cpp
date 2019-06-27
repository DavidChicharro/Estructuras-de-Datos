/*	5. Escribe una función que realice la reflexión de un árbol binario. Es decir,
	una función a la que se le pase un árbol y se modifique de forma que para
	cada nodo su hijo a la izquierda pase a ser el derecho y viceversa.			*/

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
void reflexion(bintree<T> &arb){
	bintree<T> arb_izq, arb_dcha;

	if(!arb.root().null()){
		arb.prune_left(arb.root(), arb_izq);
		arb.prune_right(arb.root(), arb_dcha);
		reflexion(arb_izq);
		arb.insert_right(arb.root(), arb_izq);
		reflexion(arb_dcha);
		arb.insert_left(arb.root(), arb_dcha);
	}
}


int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().right().right(), 6);


  recorridos(arb);
  
  reflexion(arb);

  cout << "Árbol después de la reflexión: " << endl;
  recorridos(arb);

  return 0;
}