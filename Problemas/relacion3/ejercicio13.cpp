/*	Ejercicio 13	*/

#include <iostream>
#include <string>
#include <list>
using namespace std;


template <typename T>
list<T> lista_posiciones(const list<T> &l, const list<T> &li){
	list<T> res;
	if(l.size() >= li.size()){
		typename list<T>::const_iterator it;
		typename list<T>::const_iterator it_li = li.begin();
		int i=0;
		for(it = l.begin(); it != l.end() ; ++it){
			if(i == *it_li){
				res.push_back(*it);
				it_li++;
			}
			i++;
		}
	}
	return res;
} 

int main(){
	list<int> l, li, res;

	for(int i=0 ; i<15 ; i++)
		l.push_back(i*i);

	li.push_back(2);
	li.push_back(3);
	li.push_back(5);
	li.push_back(7);
	li.push_back(11);

	res = lista_posiciones(l, li);

	list<int>::iterator it;
	for(it=res.begin() ; it!=res.end() ; ++it)
		cout << *it << " ";
	cout << endl;

}