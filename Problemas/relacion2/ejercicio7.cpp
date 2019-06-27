/*	7. Se llama expresion en postfijo a una expresión matemática 
	en la que cada operación aparece con sus dos operandos seguidos 
	por el operador. Por ejemplo: 2 3 + 5 * 
	Escribe un programa que evalue una expresion en postfijo.

	abˆc*d/e+ donde a = 5, b = 3, c = d = 2, e = 9
	abcde+*+ donde a = 12, b = 4, c = 7, d = 5, e = 2
	ab+cd*+e* donde a = 2, b = 6, c = 3, d = 5, e = 9			*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

int a=5, b=3, c=2, d=2, e=9;
//int a=12, b=4, c=7, d=5, e=2;
//int a=2, b=6, c=3, d=5, e=9;

int transformar(char caracter){
	int num;
	switch (caracter){
		case 'a': num = a; break;
		case 'b': num = b; break;
		case 'c': num = c; break;
		case 'd': num = d; break;
		case 'e': num = e; break;
		default: num = 0;	break;
	}

	return num;
}

int evalua_postfijo (string exp){
	stack<int> st;	

	for (unsigned i=0 ; i<exp.size() ; i++){
		int izq, dcha;
		int c = transformar(exp[i]);
		if(exp[i]>='a' && exp[i]<='e')
			st.push(c);
		else{
			dcha = st.top(); st.pop();
			izq = st.top() ; st.pop();
			switch (exp[i]){
				case '+': st.push(izq+dcha); break;
				case '-': st.push(izq-dcha); break;
				case '*': st.push(izq*dcha); break;
				case '/': st.push(izq/dcha); break;
				case '^': st.push(pow(izq,dcha)); break;
				default: break;
			}
		}
	}
	
	return st.top();
}

int main(){
	string exp1 = "ab^c*d/e+";
	string exp2 = "abcde+*+";
	string exp3 = "ab+cd*+e*";

	int resultado = evalua_postfijo(exp1);

	cout << resultado << endl;

	return 0;
}