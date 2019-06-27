/*	Ejercicio 12	*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

template <typename T>
bool contenida(const list<T> &l1, const list<T> &l2){
	bool esta_contenida = false;
	if(l1.size() <= l2.size()){
		int num_iguales = 0;
		typename list<T>::const_iterator it1 = l1.begin();
		typename list<T>::const_iterator it2;

		for(it2 = l2.begin() ; it2 != l2.end() ; ++it2)
			if(*it2 == *it1){
				num_iguales++;
				if(num_iguales==l1.size())
					esta_contenida = true;				
				it1++;
			}
	}
	return esta_contenida;
}

int main(){
	list<int> lista1, lista2;

	for(int i=3 ; i<6 ; i++)
		lista1.push_back(i);		// lista1: 3,4,5
	for(int i=1 ; i<10 ; i++)		// lista2: 1,2,3,4,5,6,7,8,9
		lista2.push_back(i);

	bool esta_contenida = contenida(lista1,lista2);

	if(esta_contenida)
		cout << "La lista 1 está contenida en la lista 2" << endl;
	else
		cout << "La lista 1 NO está contenida en la lista 2" << endl;

	return 0;
}