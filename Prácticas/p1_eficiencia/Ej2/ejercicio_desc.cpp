#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>   // Recursos para medir tiempos

using namespace std;
using namespace std::chrono ;

void ordenar(int *v, int n) {
    for (int i=0 ; i < n-1 ; i++)       // 1 + 2  -- n-1 veces
        for (int j=0 ; j < n-i-1 ; j++)     // n + 2  -- n-i-1 veces
            if (v[j] > v[j+1]) {                // 3 |
                int aux = v[j];                 // 2 |
                v[j] = v[j+1];                  // 3  > 10
                v[j+1] = aux;                   // 2 |
            }
} 

// Recibe el vector, el tamaño, el tamaño+1, cota inferior (0) y cota superior(tam-1)
int operacion(int *v, int n, int x, int inf, int sup) {
    int med;
    bool enc = false;

    while ((inf<sup) && (!enc)) {
        med = (inf+sup)/2; 
        if (v[med]==x) 
            enc = true;
        else if (v[med] < x) 
            inf = med+1;
        else
            sup = med-1;
    }
    if (enc) 
        return med;
    else 
        return -1;
}

void imprime(int *v, int n) {
    for (int i=0 ; i<n ; i++)
        cout << v[i] << " ";
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
    // Lectura de parámetros
    if (argc!=2)
        sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    if (tam<=0)
        sintaxis();

    // Generación del vector aleatorio
    int *v = new int[tam];          // Reserva de memoria
    srand(time(0));                 // Inicialización del generador de números pseudoaleatorios
    for (int i=0 ; i<tam ; i++)     // Recorrer vector
        v[i] = i+2;                 // Introduce en el vector los numeros ordenados
    
    time_point<steady_clock> ini  = steady_clock::now();   // Anotamos el tiempo de inicio

    // Algoritmo a evaluar
    operacion(v,tam,tam+4,0,tam-1);

    time_point<steady_clock> fin = steady_clock::now();    // Anotamos el tiempo de finalización

    duration<float,milli> tiempo = fin - ini;

    // Mostramos resultados
    cout << tam << "\t" << tiempo.count() << endl;

    delete [] v;     // Liberamos memoria dinámica
}
