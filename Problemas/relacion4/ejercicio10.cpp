/*	10. Dos arboles binarios son similares si son iguales en cuanto a su estructura, es decir, cada nodo en un
	árbol tiene los mismos hijos y en el mismo lugar que el correspondiente en el otro árbol (sin importar
	las etiquetas). Escribe una funcion que dados dos árboles binarios devuelva si son o no similares	*/

#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T>
bool similares(const bintree<T> &arb1, const bintree<T> &arb2, typename bintree<T>::node n1, typename bintree<T>::node n2 ){
	bool son_similares = true;

	if(!n1.left().null() && !n2.left().null()){				//si ambos tienen hijo a la izquierda
		son_similares = similares(arb1,arb2,n1.left(),n2.left());
	}
	else if((!n1.left().null() && n2.left().null()) || (!n2.left().null() && n1.left().null()) ){ // si uno tiene hijo a la izquierda pero el otro no
		return false;
	}

	if(!n1.right().null() && !n2.right().null()){			//si ambos tienen hijo a la derecha
		son_similares = similares(arb1,arb2,n1.right(),n2.right());
	}
	else if((!n1.right().null() && n2.right().null()) || (!n2.right().null() && n1.right().null()) ){ // si uno tiene hijo a la derecha pero el otro no
		return false;
	}

  return son_similares;
}


int main(){
  bintree<int> arb1(30);
  arb1.insert_left(arb1.root(), 46);
  arb1.insert_right(arb1.root(), 58);
  arb1.insert_left(arb1.root().left(), 60);
  arb1.insert_left(arb1.root().right(), 14);
  arb1.insert_right(arb1.root().right(), 8);
  arb1.insert_left(arb1.root().right().right(), 6);

  bintree<int> arb2(16);
  arb2.insert_left(arb2.root(), 15);
  arb2.insert_right(arb2.root(), 9);
  arb2.insert_left(arb2.root().left(), 79);
  arb2.insert_left(arb2.root().right(), 97);
  arb2.insert_right(arb2.root().right(), 1);
  arb2.insert_left(arb2.root().right().right(), 2);


  bool son_similares = similares(arb1, arb2, arb1.root(), arb2.root());

  if(son_similares)
		cout << "Los árboles son similares " << endl;
  else
  	cout << "Los árboles no son similares " << endl;

}