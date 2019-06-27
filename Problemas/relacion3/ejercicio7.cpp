/*	Ejercicio 7	*/

#include <iostream>
#include <list>
#include <set>

using namespace std;

template <typename T>
void eliminar_duplicados(list<T> &lista){
	set<T> aux;
	list<T> nueva_lista;

	typename list<T>::iterator it_l;
	typename set<T>::iterator it_s;

	for(it_l = lista.begin() ; it_l != lista.end() ; ++it_l){
		it_s = aux.find(*it_l);
		if(it_s == aux.end()){
			nueva_lista.push_back(*it_l);
			aux.insert(*it_l);	
		}
	}

	lista = nueva_lista;
}

int main(){
	list<int> lista;
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(4);
	lista.push_back(6);
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(5);
	lista.push_back(1);
	lista.push_back(4);

	eliminar_duplicados(lista);

	list<int>::iterator it;
	for(it=lista.begin() ; it!=lista.end() ; ++it)
		cout << *it << " " << endl;
	cout << endl;

	return 0;
}