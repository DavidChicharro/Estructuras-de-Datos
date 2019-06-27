#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
using namespace std;

void sintaxis() {
   	cerr << "Sintaxis:" << endl;
   	cerr << "  TAM: Tamaño del vector (>0)" << endl;
   	cerr << "  VMAX: Valor máximo (>0)" << endl;
   	cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
	exit(EXIT_FAILURE);
}

void OrdenarBurbuja(int *v, int n) {
	for (int i=0 ; i < n-1 ; i++)		// 1 + 2  -- n-1 veces
		for (int j=0 ; j < n-i-1 ; j++)		// n + 2  -- n-i-1 veces
			if (v[j] > v[j+1]) {				// 3 |
				int aux = v[j];					// 2 |
				v[j] = v[j+1];					// 3  > 10
				v[j+1] = aux;					// 2 |
			}
} 

int main(int argc, char * argv[]) {
  // Lectura de parámetros
	if (argc!=3)
		sintaxis();
	int tam=atoi(argv[1]);     // Tamaño del vector
	int vmax=atoi(argv[2]);    // Valor máximo
	if (tam<=0 || vmax<=0)
		sintaxis();
	  
	// Generación del vector aleatorio
	int *v=new int[tam];       // Reserva de memoria
	srand(time(0));            // Inicialización del generador de números pseudoaleatorios
	for (int i=0 ; i<tam ; i++)  // Recorrer vector
		v[i] = tam-i;
	  
	clock_t tini;    // Anotamos el tiempo de inicio
	tini=clock();
	  
	//int x = vmax+1;  // Buscamos un valor que no está en el vector
	OrdenarBurbuja(v, tam); // de esta forma forzamos el peor caso

	clock_t tfin;    // Anotamos el tiempo de finalización
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
	  
	delete [] v;     // Liberamos memoria dinámica
}
