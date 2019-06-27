/*	3. Construye una función que determine si un árbol es completo	*/

#include <iostream>
#include "math.h"
#include <queue>
#include "bintree.h"

using namespace std;

// Función que calcula el nivel del nodo
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

// Función que, dado un nodo, da el siguiente nodo en su recorrido por niveles
template <typename T>
void siguiente_nodo(const bintree<T> & A, typename bintree<T>::node &v, queue<typename bintree<T>::node> &cola){  
  typename bintree<T>::node aux;
  if(!v.null() && !cola.empty()){
		aux = cola.front();
		if(!aux.left().null()){
			aux = aux.left();
			cola.push(aux);
			if(!aux.parent().right().null())
				cola.push(aux.parent().right());
		}
		else if(!aux.right().null())
			cola.push(aux.right());

		cola.pop();
  }
  v = cola.front();
}

template <typename T>
bool es_arbol_completo(const bintree<T> &arb){
	int nivel_n, nivel_fila = -1;
	vector<int> niveles;
	typename bintree<T>::node n = arb.root();
	typename bintree<T>::node padre;


	queue<typename bintree<T>::node> cola; 
	cola.push(arb.root());
	
	// Se almacena en un vector el número de nodos que hay en cada nivel del árbol
	while(!n.null()){
		nivel_n = nivel_nodo(arb,n);

		if(nivel_fila != nivel_n){
			nivel_fila++;
			niveles.push_back(1);
		}
		else
			niveles[nivel_n]++;

		siguiente_nodo(arb, n, cola);
	}

	// Si el número de nodos en cada nivel es distinto a 2^(k-1) el árbol no es completo
	for(int i=0 ; i<niveles.size()-1 ; i++)
		if(niveles[i] != pow(2,i))
			return false;

	queue<typename bintree<int>::node> q;
	q.push(arb.root());
	n = arb.root();
	// Se sitúa el nodo n en el primero de la última fila
	for(int i=0 ; i<(pow(2,niveles.size()-1)-1) ; i++) {
		siguiente_nodo(arb, n, q);
	}

	while(!n.null()){
		nivel_n = nivel_nodo(arb,n);
		if(nivel_n == niveles.size()-1){
			padre = n.parent();

			if(n==padre.left()){ 										// si es hijo_izqdo
				// se comprueba que el padre de cada nodo es el hijo izquiero de su padre
				// y si no lo es, el árbol no es completo
				typename bintree<T>::node p = n;
				while(p.parent() != arb.root() ){
						if(p != p.parent().left())
							return false;
					p = p.parent();
				}
				if(p != p.parent().left()) 
					return false;

				if( padre.right().null()){					// si es hijo_izqdo y no tiene hermano_dcho
					typename bintree<T>::node aux = n;
					siguiente_nodo(arb, aux, q);
					if(aux.null())					// si el siguiente nodo es nulo
						return true;					// será árbol completo
					else
						return false;
				}
			}
			if(n==padre.right() && padre.left().null()) 	// si es hijo_dcho y no tiene hermano_izqdo
				return false;																// no será un árbol completo
		}
		siguiente_nodo(arb, n, q);
	}

	return true;
}


int main(){
  bintree<int> arb(30);
  arb.insert_left(arb.root(), 46);
  arb.insert_right(arb.root(), 58);
  arb.insert_left(arb.root().left(), 60);
  arb.insert_right(arb.root().left(), 9);
  arb.insert_left(arb.root().right(), 14);
  arb.insert_right(arb.root().right(), 8);
  arb.insert_left(arb.root().left().left(), 6);  
  arb.insert_right(arb.root().left().left(), 13);

  arb.insert_left(arb.root().right().left(), 100);		// con este nodo el árbol no es completo


  if(es_arbol_completo(arb))
  	cout << "El árbol es completo" << endl;
  else
  	cout << "El árbol no es completo" << endl;

  return 0;
}