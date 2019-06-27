/*	Ejercicio 16	*/

#include <iostream>
#include <string>
#include <list>
using namespace std;


template <typename T>
list<pair<T, int> > comprimir(const list<T> &l){
	list<pair<T, int> > lista_comprimida;

	typename list<T>::const_iterator it;
	typename list<pair<T, int> >::iterator it_lc = lista_comprimida.begin();
	for(it=l.begin() ; it!=l.end() ; ++it){		
		if(it_lc->first == *it){
			int nueva_frec = it_lc->second + 1;
			lista_comprimida.pop_back();
			lista_comprimida.push_back(make_pair(*it, nueva_frec));
		}
		else{
			lista_comprimida.push_back(make_pair(*it, 1));
			it_lc++;
		}		
	}
	return lista_comprimida;
}

template <typename T>
list<T> descomprimir(const list<pair<T, int> > &lc){
	list<T> lista_descomprimida;

	typename list<pair<T, int> >::const_iterator it_lc;
	for(it_lc = lc.begin() ; it_lc != lc.end() ; ++it_lc)
		for(int i=0 ; i<it_lc->second ; i++)
			lista_descomprimida.push_back(it_lc->first);

	return lista_descomprimida;
}

int main(){
	list<int> lista;
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(2);
	lista.push_back(2);
	lista.push_back(2);
	lista.push_back(2);
	lista.push_back(2);
	lista.push_back(7);
	lista.push_back(7);
	lista.push_back(7);
	lista.push_back(7);
	lista.push_back(7);
	lista.push_back(12);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(5);

	list<pair<int, int> > lista_comprimida = comprimir(lista);
	list<int> lista_descomprimida = descomprimir(lista_comprimida);


	typename list<int>::iterator it;
	for(it=lista.begin() ; it!=lista.end() ; ++it)
		cout << *it << " ";
	cout << endl;

	typename list<pair<int, int> >::const_iterator it_lc;
	cout << "Compresion: <";
	for(it_lc = lista_comprimida.begin() ; it_lc != lista_comprimida.end() ; ++it_lc)
		cout << "(" << it_lc->first << ", " << it_lc->second << ")" << " ";
	cout << ">" << endl;

	cout << "Descompresion: ";
	for(it=lista_descomprimida.begin() ; it!=lista_descomprimida.end() ; ++it)
		cout << *it << ", ";
	cout << endl;

	return 0;
}