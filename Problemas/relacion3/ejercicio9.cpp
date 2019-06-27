/*	Ejercicio 9	*/

#include <iostream>
#include <list>

using namespace std;

template <typename T>
list<T> cambiar(list<T> lista){
	list<T> lista_inversa;
	typename list<T>::reverse_iterator it;

	for(it=lista.rbegin() ; it!=lista.rend() ; ++it)
		lista_inversa.push_back(*it);
	
	return lista_inversa;
}

int main(){
	list<int> lista, lista_inversa;
	for(int i=0 ; i<10 ; i++)
		lista.push_back(i);	

	lista_inversa = cambiar(lista);

	list<int>::iterator it;
	for(it=lista_inversa.begin() ; it!=lista_inversa.end() ; ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}