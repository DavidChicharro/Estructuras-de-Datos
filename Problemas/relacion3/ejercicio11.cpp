/*	Ejercicio 11	*/

#include <iostream>
#include <string>
#include <list>
using namespace std;


void inserta_anterior(list<int> &lista, int x){
	list<int> aux;
	bool existe_valor = false;

	while(!lista.empty()){
		aux.push_back(lista.front());

		if(lista.front() == x)
			existe_valor = true;

		lista.pop_front();
	}

	if (existe_valor)
		while(!aux.empty()){
			lista.push_back(aux.front());
			if(aux.front() == x)
				lista.push_back(x-1);
			aux.pop_front();
		}
	else
		lista = aux;

}

int main(){
	list<int> lista;
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(6);
	lista.push_back(8);
	lista.push_back(1);
	lista.push_back(4);
	lista.push_back(6);
	lista.push_back(3);
	lista.push_back(1);	
	lista.push_back(7);

	inserta_anterior(lista, 1);

	list<int>::iterator it;
	for(it=lista.begin() ; it!=lista.end() ; ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}