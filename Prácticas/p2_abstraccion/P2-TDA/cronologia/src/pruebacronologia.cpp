#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
	if (argc!=3){
		cout << "Dime el nombre del fichero con la cronologia" << endl;
		return 0;
	}

	ifstream f (argv[1]);
	if (!f){
		cout << "No puedo abrir el primer fichero " << argv[1] << endl;
		return 0;
	}
	ifstream f_2 (argv[2]);
	if (!f_2){
		cout << "No puedo abrir el segundo fichero " << argv[2] << endl;
		return 0;
	}
	
	ofstream out;
	out.open("salida.txt");
	
	Cronologia mi_cronologia; 
	f >> mi_cronologia;

	// Añadir a la cronología una pelicula en un año ya existente
	mi_cronologia.Aniadir_Evento(2017, "Annabelle 2");
	// Añadir a la cronología una pelicula en un año que no existe
	mi_cronologia.Aniadir_Evento(2018, "Deadpool 2");
	// Añadir a la cronología una película en un año que no existe, anterior al resto
	mi_cronologia.Aniadir_Evento(1899, "The Kiss in the Tunnel");
	out << mi_cronologia;

	// Obtener la cronología de un año
	Cronologia crono_2015(mi_cronologia, 2015);
	cout << crono_2015 << endl;
	// Obtener la cronología de un rango de años
	Cronologia crono_2000_2004(mi_cronologia, 2000, 2004);
	cout << crono_2000_2004 << endl;

	// Obtener toda la cronología relativa a un evento
	Cronologia hecho(mi_cronologia, "Star Wars");
	cout << hecho << endl;

	Cronologia otra_cronologia;
	f_2 >> otra_cronologia;

	// Unión de dos cronologías distintas
	Cronologia varias_cronos = mi_cronologia + otra_cronologia;
	cout << "Mezcla de Cronologías: " << endl;
	cout << varias_cronos;


	f.close();
	f_2.close();
	out.close();

	return 0;
}