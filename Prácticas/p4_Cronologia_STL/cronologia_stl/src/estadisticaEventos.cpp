#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[]){
  if (argc!=2){
    cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
    return 0;
  }

  ifstream fin (argv[1]);
    if (!fin){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  Cronologia c;
  fin >> c;

  cout << "\n************************ ESTADÍSTICAS DE EVENTOS ************************" << endl << endl;
  cout << "Número total de años para los que se especifican fechas históricas: "
      << c.NumFechas() << endl;
  cout << "Número total de acontecimientos: " << c.GetNumTotalAcontecimientos() << endl;
  cout << "Máximo de acontecimientos en un año: " << c.GetMaxAcontecimientosAnio() << endl;
  cout << "Promedio de acontecimientos en la cronología: " << c.GetPromedioAcontecimientos() << endl << endl;

  fin.close();
}