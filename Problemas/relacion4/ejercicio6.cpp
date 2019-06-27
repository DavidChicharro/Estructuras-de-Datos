/*	6. Definimos densidad de un árbol binario A como la suma de las profundidades de las hojas
		de un árbol. Construir un algoritmo para calcular la densidad de un árbol binario.		*/


#include <iostream>
#include "bintree.h"

using namespace std;

// Funcioń que recorre el árbol en preorden
template <typename T>
void siguiente_nodo(const bintree<T> & A, typename bintree<T>::node &v){

  if (!v.left().null())
    v = v.left();
  else if (!v.right().null())
      v = v.right();
  else {
    while ((!v.parent().null()) && (v.parent().right() == v || v.parent().right().null()))
      v = v.parent();
    if (v.parent().null())
      v = typename bintree<T>::node();
    else
      v = v.parent().right();
  }
}

// Función que calcula el nivel/profundidad de un nodo en un árbol
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

// Función que calcula la densidad del árbol
template <typename T>
int densidad_arbol(const bintree<T> & A){
	int densidad = 0;

	typename bintree<T>::node nodo = A.root();

	while(!nodo.null()){
		densidad += nivel_nodo(A,nodo);
		siguiente_nodo(A,nodo);
	}

	return densidad;
}


int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().right().right(), 6);

  bintree<int>::node n = arb.root().right().left();

  int densidad = densidad_arbol(arb);

  cout << "La densidad del árbol es: " << densidad << endl;

  return 0;
}		