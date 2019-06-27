#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool configuracion_correcta(string expresion){
	stack<bool> parentesis;
	bool correcto = true;

	for(unsigned i=0 ; i<expresion.size() && correcto ; i++){
		if (expresion.at(i) == '(')
			parentesis.push(true);			// Si encuentra una apertura de paréntesis, añade 'true' a la pila
		if (expresion.at(i) == ')'){
			if (!parentesis.empty())		// Si encuentra un cierre de paréntesis estando llena la pila, elimina un elemento
				parentesis.pop();
			else
				correcto = false;			// Si encuentra un cierre de paréntesis estando la pila vacía, la configuración es incorrecta
		}
	}
	if (correcto && !parentesis.empty())	// Si la configuración de paréntesis es correcta en principio pero queda algún paréntesis de apertura
		correcto = false;					// la configuración será incorrecta

	return correcto;
}

int main(){
	string expresion;
	bool correcto;

	getline(cin, expresion);
	//expresion = "La eficiencia es O(n) y un ejemplo de formula correcta es: f(g(x),h(y))";
	//expresion = "Esto sin embargo )( no valdria";
	//expresion = "Esto (tampoco) (valdria";
	
	correcto = configuracion_correcta(expresion);

	if (correcto)
		cout << "\nConfiguracion de parentesis correcta." << endl;
	else
		cout << "\nConfiguracion de parentesis incorrecta." << endl;

	return 0;
}