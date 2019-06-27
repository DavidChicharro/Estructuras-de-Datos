#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_FIL_COL = 2000;

void Sintaxis() {
	cerr << "Sintaxis:" << endl;
	cerr << "  TAM: Tamaño de las filas y columnas (>0)" << endl;
	cerr << "  VMAX: Valor máximo (>0)" << endl;
	cerr << "Se genera una matriz cuadrada de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
	exit(EXIT_FAILURE);
}

void Inicializa (const int tam, int **m, int vmax) {
	for (int i=0 ; i<tam ; i++)
		for (int j=0 ; j<tam ; j++)
			m[i][j] = rand () % vmax;
}

void Multiplica (const int tam, int **A, int **B, int **Res) {
	for (int i=0 ; i<tam ; i++) {
		for (int j=0 ; j<tam ; j++) {
			Res[i][j]=0;
			for (int k=0 ; k<tam ; k++)
				Res[i][j] = Res[i][j] + A[i][k]*B[k][j];
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc!=3)
		Sintaxis();
	int tam=atoi(argv[1]);     // Tamaño de la matriz
	int vmax=atoi(argv[2]);    // Valor máximo
	if (tam<=0 || vmax<=0)
		Sintaxis();

	int **A = new int* [MAX_FIL_COL],
		**B = new int* [MAX_FIL_COL],
		**Res = new int* [MAX_FIL_COL];

	for (int i=0 ; i<MAX_FIL_COL ; i++) {
		A[i] = new int [MAX_FIL_COL];
		B[i] = new int [MAX_FIL_COL];
		Res[i] = new int [MAX_FIL_COL];
	}
	
	// Inicialización de las matrices A y Bcon valores enteros aleatorios
	Inicializa(tam, A, vmax);
	Inicializa(tam, B, vmax);

	srand(time(0));			// Inicialización del generador de números pseudoaleatorios
	clock_t inicio = clock();
	Multiplica(tam, A, B, Res);
	clock_t fin = clock();

	cout << tam << "\t" << (fin-inicio)/(double)CLOCKS_PER_SEC << endl;

	for (int i=0 ; i<MAX_FIL_COL ; i++) {
		delete A[i];
		delete B[i];
		delete Res[i];
	}

	delete [] A;
	delete [] B;
	delete [] Res;

	return 0;
}