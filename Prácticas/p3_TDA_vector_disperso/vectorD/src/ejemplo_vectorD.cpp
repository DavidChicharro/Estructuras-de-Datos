#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "vectorD.h"

using namespace std;


int main() {
  vectorD<int> vec(0, 0);   // 0 elementos, valor nulo definido como 0
  vec.resize(98);          // 98 elementos
  cout << "Preparado vectorD para tamaño: "<<vec.size()<<endl;

  for (unsigned i=0; i<vec.size(); i+=10)
    vec.set(i, 20);         // componentes con posición múltiplo de 10 se ponen a 20, el resto nulos

  vec.push_back(0);     //componente 98 es 0
  vec.push_back (30);   //componente 99 es 20
  vec.push_back (50);   //componente 100 es 20
 
  cout << "vectorD tamaño: "<<vec.size()<< endl;   //tras insertar 3 nuevos elementos, tamaño debe ser 101

  //mostramos todo el vector para comprobar: 
  cout << "Iteramos sobre todas las componentes a través de los índices: "<<endl;
  for (unsigned i=0; i<vec.size(); i++)
    cout << "vec["<<i<<"]: "<<vec[i]<<endl; 

  cout << "Elimino el último elemento.";
  vec.pop_back();
  cout << " El tamaño de vectorD es ahora: "<<vec.size()<<endl;   //tras eliminar el último elemento, tamaño debe ser 100

  //Prueba con stored_iterator
  cout << "Iteramos sobre los elementos no nulos con stored_iterator: "<<endl;
  vectorD<int>::stored_iterator it_nonulo;
  for (it_nonulo = vec.sbegin(); it_nonulo != vec.send(); it_nonulo++)
    cout << "posicion "<<(*it_nonulo).first<<" valor: "<<(*it_nonulo).second << endl;


  //Prueba con iterator
  cout << "Iteramos sobre todos los elementos con iterator: "<<endl;
  vectorD<int>::iterator it_todos;

  for (it_todos = vec.begin(); it_todos != vec.end() ; ++it_todos)
    cout << "valor: "<<(*it_todos) << endl;


  vec.clear();
  cout << "Borrado el contenido. Nuevo tamaño: "<<vec.size() << endl;


  return 0;

}
