#include <iostream>
#include "vector_dinamico.h"

using namespace std;

void cargar_indices(Vector_Dinamico & v){
  for(int i=0; i<v.size(); i++)
    v[i] = i;
}

float maximo(const Vector_Dinamico &v){
  float max;
  if (v.size()==0){
    cerr << "Máximo de 0 elementos!! Asignamos 0 "<< endl;
    max = 0;
  }
  else{
    max = v[0];
    for(int i=1; i<v.size(); i++)
      if (max < v[i])
        max = v[i];
  }
  return max;
}

int main() {
  Vector_Dinamico vector;
  cargar_indices(vector);
  cout << "Máximo de " << vector.size() << " elementos: "
  << maximo(vector) << endl;

  vector.resize(10);
  cargar_indices(vector);
  cout << "Máximo de " << vector.size() << " elementos: "
  << maximo(vector) << endl;

  return 0;
}
