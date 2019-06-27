/*	Ejercicio 4	*/
// Fichero para ejemplo de uso: fichero.txt

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> mapa;
typedef multimap<int, string> m_map;

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

m_map consultar_palabras(mapa palabras, int frec){
	m_map frecuencias;
	mapa::iterator it;
	for(it=palabras.begin() ; it!=palabras.end() ; ++it)
		if(it->second == frec)
			frecuencias.insert(make_pair(it->second, it->first));

	return frecuencias;
}

int main(){
   const int TAM = 20;
   char nombre_fich[TAM];
   cout << "Introduce el nombre del fichero: ";
   cin >> nombre_fich;

 	mapa contador = contador_palabras(nombre_fich);

   int frec_aparicion;
   cout << "\nIntroduce la frecuencia de aparicion: ";
   cin >> frec_aparicion;

   m_map frecuencias = consultar_palabras(contador, frec_aparicion);

   m_map::iterator mm_it;
   for(mm_it=frecuencias.begin() ; mm_it!=frecuencias.end() ; ++mm_it)
   	cout << mm_it->second << endl;

   return 0;
}