/*	7. Supongamos que tenemos una función valor tal que dado un valor de tipo char (una letra del alfabeto)
	devuelve un valor entero asociado a dicho identificador. Supongamos tambien la existencia de
	un arbol de expresión T cuyos nodos hoja son letras del alfabeto y cuyos nodos interiores son los
	caracteres *, +, -, /. Diseñar una función que tome como parámetros un nodo y un árbol binario y
	devuelva el resultado de la evaluación de la expresión representada.																	*/


#include <iostream>
#include <stack>
#include "bintree.h"

using namespace std;

bool es_operador(char op){
	return (op == '+' || op == '-' || op == '*' ||op == '/');
}

int valor(char letra){
	return letra%26;
}

template <typename T>
void siguiente_nodo(const bintree<T> & A, typename bintree<T>::node &v){
  if (v.parent().null())
    v = typename bintree<T>::node();
  else if (v.parent().left() == v) {
      if (!v.parent().right().null()) {
        v = v.parent().right();
        do {
	        while (!v.left().null())
	          v = v.left();
	        if (!v.right().null())
	          v = v.right();
	      } while ( !v.left().null() ||
		             !v.right().null());
      }
      else
        v = v.parent();
  }
	else // v es hijo a la derecha de su padre
    v = v.parent();
}

template <typename T>
double evalua(const bintree<T> & A){
	float op_izq, op_dcho, res=0.0;
	char operador;
	stack<float> st;
	typename bintree<T>::node nodo = A.root();

	while(!nodo.left().null())
		nodo = nodo.left();

	while (!nodo.null()){
		if (es_operador(*nodo)){
			operador = *nodo;
			op_dcho = st.top(); st.pop();
			op_izq = st.top(); st.pop();
			
			switch (operador){
				case '+':
					res = op_izq+op_dcho;
					break;
				case '-':
					res = op_izq-op_dcho;
					break;
				case '*':
					res = op_izq*op_dcho;
					break;
				case '/':
					res = op_izq/op_dcho;
					break;
			}
			st.push(res);
			siguiente_nodo(A,nodo);
		}
		else{
			if(nodo.parent().left() == nodo)
				st.push(valor(*nodo));
			else
				st.push(valor(*nodo));

			siguiente_nodo(A,nodo);
		}
	}
	return res;
}

int main(){
	// [(a+c)/(f-c)]+[(b+h)/(n*m)]  =  [(19+21)/(24-21)]+[(20+0)/(6*5)]  =  14
	bintree<char> arb('+');
  arb.insert_left(arb.root(), '/');
  arb.insert_right(arb.root(), '/');
  arb.insert_left(arb.root().left(), '+');
  arb.insert_right(arb.root().left(), '-');
  arb.insert_left(arb.root().right(), '+');
  arb.insert_right(arb.root().right(), '*');
  arb.insert_left(arb.root().left().left(), 'a');
  arb.insert_right(arb.root().left().left(), 'c');
  arb.insert_left(arb.root().left().right(), 'f');
  arb.insert_right(arb.root().left().right(), 'c');
  arb.insert_left(arb.root().right().left(), 'b');
  arb.insert_right(arb.root().right().left(), 'h');
  arb.insert_left(arb.root().right().right(), 'n');
  arb.insert_right(arb.root().right().right(), 'm');


	cout << "Resultado = " << evalua(arb) << endl;

	return 0;
}