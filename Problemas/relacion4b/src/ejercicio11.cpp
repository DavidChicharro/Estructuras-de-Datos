/*  11. Dado un bintree T, organizado como un BST, implementa una funcion a la que se le pasen dos valores
    a y b y que determine de forma eficiente los valores presentes en el arbol y que estén comprendidos
    entre ambos. Tanto a como b no tienen porque aparecer en el árbol.                                  */


#include <iostream>
#include <set>
#include <bintree.h>

using namespace std;

template <typename T>
set<T> valores_entre(const bintree<T> &A, const T &a, const T &b){
  bool continuar = true;
  set<T> valores;
  typename bintree<T>::const_inorder_iterator it;

  for(it = A.begin_inorder() ; it!=A.end_inorder() && continuar ; ++it)
    if(*it == a)
      continuar = false;

  while(*it < b && it!=A.end_inorder()){
    if(*it >= a)
      valores.insert(*it);
    ++it;
  }

  return valores;
}


int main(){
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

  bintree<int>::inorder_iterator it;
  cout << "Recorrido del árbol inorden: " << endl;
  for(it=arb.begin_inorder() ; it!=arb.end_inorder() ; ++it)
    cout << *it << " " ;
  cout << endl << endl;

  set<int> valores = valores_entre(arb, 3, 8);
  set<int>::iterator v_it;

  cout << "Valores comprendidos entre los dos previamente dados: " << endl;
  for(v_it=valores.begin() ; v_it!=valores.end() ; ++v_it)
    cout << *v_it << " ";
  cout << endl;

  return 0;
}