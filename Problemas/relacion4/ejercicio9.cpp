/*  9. Escribe una funcion no recursiva (usando una pila) para calcular la altura de un árbol binario.  */

// No funciona correctamente para todos los casos

#include <iostream>
#include <stack>
#include "bintree.h"

using namespace std;

template <typename T>
int altura(const bintree<T> &arb) {
  if (arb.root().null())
    return 0;

  stack< bintree<int>::node > pila;

  pila.push(arb.root());
  int altura = 0;

  while(true) {
    int num_nodos = pila.size();
    if (num_nodos == 0)
      return altura-1;

    altura++;

    while (num_nodos > 0) {
      bintree<int>::node n = pila.top();
      pila.pop();
      if(!n.left().null())
          pila.push(n.left());
      if(!n.right().null())
          pila.push(n.right());

      num_nodos--;
    }
  }

  return altura;
}

int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().right().right(), 6);

  int altura_arbol = altura(arb);

  cout << "La altura del árbol es: " << altura_arbol << endl;

  return 0;
}