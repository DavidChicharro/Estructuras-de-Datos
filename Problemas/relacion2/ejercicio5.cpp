// 5. Usando una pila y una cola, implementa una funcion que compruebe si un string es un palíndromo.

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// La función tiene en cuenta los espacios en blanco
bool es_palindromo(stack<char> &st, queue<char> &q){
	bool palindromo = true;

	while(!st.empty() && palindromo){
		if (st.top() == q.front()){
			st.pop();
			q.pop();
		}
		else
			palindromo = false;
	}

	return palindromo;
}

int main(){
	bool palindromo;
	string frase;
	stack<char> st;
	queue<char> q;

	cout << "Introduce una frase: ";
	cin >> frase;

	for (unsigned i=0 ; i<frase.size() ; i++){
		st.push(frase[i]);
		q.push(frase[i]);
	}

	palindromo = es_palindromo(st, q);

	if (palindromo)
		cout << "Es palíndromo" << endl;
	else
		cout << "No es palíndromo" << endl;

	return 0;
}
