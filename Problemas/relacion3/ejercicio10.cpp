/*	Ejercicio 10	*/

#include <iostream>
#include <string>
#include <set>
#include <list>
using namespace std;

template<typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
	// funcion que mezcla las dos listas y las devuleve ordenadas
	set<T> mezcla;
	list<T> resultado;

	typename list<T>::const_iterator it;
	for(it=l1.begin() ; it!=l1.end() ; ++it)
		mezcla.insert(*it);
	for(it=l2.begin() ; it!=l2.end() ; ++it)
		mezcla.insert(*it);

	typename set<T>::iterator it_s;
	for(it_s=mezcla.begin() ; it_s!=mezcla.end() ; ++it_s)
		resultado.push_back(*it_s);

	return resultado;
}

int main(){
	list<int> lista_1, lista_2, lista_mezcla;
	lista_1.push_back(2);
	lista_1.push_back(5);
	lista_1.push_back(7);
	lista_1.push_back(4);
	lista_1.push_back(1);
	lista_1.push_back(3);

	lista_2.push_back(5);
	lista_2.push_back(2);
	lista_2.push_back(6);
	lista_2.push_back(7);
	lista_2.push_back(4);
	lista_2.push_back(5);

	lista_mezcla = mezclar(lista_1, lista_2);

	list<int>::iterator it;
	for(it=lista_mezcla.begin() ; it!=lista_mezcla.end() ; ++it)
		cout << *it << endl;
}