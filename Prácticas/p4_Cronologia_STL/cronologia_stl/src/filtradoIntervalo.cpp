#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char * argv[]){
  if (argc!=4 && argc!=5){
    cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
    cout<<"Un año como límite inferior del intervalo."<<endl;
    cout<<"Un año como límite superior del intervalo."<<endl;
    cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
    return 0;
  }

  ifstream fin (argv[1]);
    if (!fin){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  int anio_ini = atoi(argv[2]);
  int anio_fin = atoi(argv[3]);

  Cronologia c;
  fin >> c;

  Cronologia filtrado_intervalo(c, anio_ini, anio_fin);

  if (argc==4)
    cout << filtrado_intervalo;
  else{
    ofstream fout(argv[4]);  
    if (!fout){
       cout<<"No puedo crear el fichero "<<argv[4]<<endl;
       return 0;
    }
    fout << filtrado_intervalo;
    fout.close();      
  }

  fin.close();
}