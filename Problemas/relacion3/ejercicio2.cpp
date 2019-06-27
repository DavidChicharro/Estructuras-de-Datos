/*	Ejercicio 2	*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string desencripta(string cadena, map<char,char> desencripta){
	string salida = "";
	bool continuar;
	for(int i=0 ; i<cadena.size() ; i++){
		char caracter;
		bool continuar = true;
		map<char,char>::iterator it;
		for(it=desencripta.begin() ; it != desencripta.end() && continuar ; ++it){
			if(it->second == cadena[i]){
				caracter = it->first;
				continuar = false;
			}
		}		
		salida.push_back(caracter);
	}
	return salida;
}


string encripta(string cad, map<char,char> encriptacion){
	string salida = "";
	for(int i=0 ; i<cad.size() ; i++){
		char caracter = encriptacion[cad[i]];
		salida.push_back(caracter);
	}

	return salida;
}


int main(){
	string cadena;
	map<char, char> encriptacion;


	cout << "Introduzca una cadena de caracteres: ";
	getline(cin, cadena);	


	for(char i=' ' ; i<='z' ; i++)
		encriptacion.insert(make_pair(i, i+2));		// asigna en el mapa a cada caracter otro caracter del codigo ASCII


	string cad_encript = encripta(cadena, encriptacion);

	cout << "Cadena encriptada: ";
	for(int i=0 ; i<cad_encript.size() ; i++)
		cout << cad_encript[i];
	cout << endl;

	string cad_desencript = desencripta(cad_encript, encriptacion);

	cout << "Cadena desencriptada: ";
	for(int i=0 ; i<cad_desencript.size() ; i++)
		cout << cad_desencript[i];
	cout << endl;

	return 0;
}