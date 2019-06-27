/*	16. Dada una secuencia de claves S = {5; 8; 4; 13; 66; 2; 9; 12; 11; 17}

		* Inserta la secuencia anterior, en el orden indicado, en una tabla 
		hash cerrada con resolucion de colisiones lineal y que tiene tamaño 11. 
		A continuación, borrar los elementos 2 y 17.
*/

#include <iostream>
using namespace std;

const int TAM = 11;
enum estado{libre, ocupada,	borrada};

void inicializar(pair<int,estado> v[], const int TAM){
	for (int i=0 ; i<TAM ; i++)
		v[i] = make_pair(0,estado::libre);
}

bool esta_libre(pair<int,estado> v[], int pos){
	return v[pos].second == estado::libre || v[pos].second == estado::borrada;
}

int func_hash(int valor, int i){
	return (valor+(i-1))%TAM;
}

void insertar(pair<int,estado> v[], int valor){
	int pos, intento = 1;
	bool insertado = false;

	while(!insertado){
		pos = func_hash(valor, intento);

		if(esta_libre(v,pos)){
			v[pos] = make_pair(valor, estado::ocupada);
			insertado = true;
		}
		else
			intento++;
	}
}

void borrar(pair<int,estado> v[], int valor){
	int pos, intento = 1;
	bool encontrado = false;

	while(!encontrado){
		pos = func_hash(valor, intento);

		if(v[pos].first == valor){
			v[pos] = make_pair(0, estado::borrada);
			encontrado = true;
		}
		else
			intento++;
	}
}

void imprimir(pair<int,estado> v[]){
	for(int i=0 ; i<TAM ; i++)
		if(v[i].second == estado::ocupada)
			cout << "hash[" << i << "] = " << v[i].first << endl;
	cout << endl;
}

int main(){
	int s[] ={5, 8, 4, 13, 66, 2, 9, 12, 11, 17};
	pair<int,estado> hash[TAM];
	inicializar(hash, TAM);

	for(int i=0 ; i<10 ; i++)
		insertar(hash, s[i]);

	imprimir(hash);

	borrar(hash, 2);
	borrar(hash, 17);

	cout << "Se han eliminado 2 y 17" << endl;
	imprimir(hash);

	return 0;
}