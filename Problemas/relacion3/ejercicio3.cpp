/*	Ejercicio 3	*/
// Fichero para ejemplo de uso: fichero.txt

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> mapa;

mapa contador_palabras(char *nombre_fich){
	ifstream fich (nombre_fich);	
	mapa contador;

   if (fich){
		string palabra;
		while (fich >> palabra){
			mapa::iterator it;
			it = contador.find(palabra);
			if(it != contador.end())
				it->second++;
			else
				contador.insert(make_pair(palabra, 1));
		}
	}

	fich.close();
	return contador;
}

int main(){
   const int TAM = 20;
   char nombre_fich[TAM];
   cout << "Introduce el nombre del fichero: ";
   cin >> nombre_fich;

 	mapa contador;
   contador = contador_palabras(nombre_fich);

   mapa::iterator it;
   for(it=contador.begin() ; it!=contador.end() ; ++it)
   	cout << "Palabra: " << it->first << "\t\tNumero apariciones: " << it->second << endl;

   return 0;
}