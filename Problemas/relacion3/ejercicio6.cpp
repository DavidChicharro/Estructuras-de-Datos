/*	Ejercicio 6	*/

#include <iostream>
#include <list>

using namespace std;


template <typename T>
void eliminar_elemento(list<T> &lista, T x){
	T aux;
	list<T> lista_aux;
	while(!lista.empty()){
		aux=lista.front();
		if(aux != x)
			lista_aux.push_back(aux);
		lista.pop_front();
	}
	lista=lista_aux;
}

int main(){

	list<int> lista;
	for(int i=0 ; i<10 ; i++){
		lista.push_back(i);
		if(i%3 == 0)
			lista.push_back(3);
	}

	list<int>::iterator it;
	cout << "Lista original: \t";
	for(it = lista.begin() ; it != lista.end() ; ++it)
		cout << *it << " ";
	cout << endl;

	eliminar_elemento(lista, 3);

	cout << "Lista actualizada: \t";
	for(it = lista.begin() ; it != lista.end() ; ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}