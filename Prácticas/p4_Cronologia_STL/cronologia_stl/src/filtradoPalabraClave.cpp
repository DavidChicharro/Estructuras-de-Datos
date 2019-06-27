#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;


int main(int argc, char * argv[]){

  if (argc!=2 && argc!=3 && argc!=4){
    cout<<"Error: debe dar al menos el nombre de un fichero con cronología. "<<endl;
    cout<<"[Opcional]: una palabra clave para realizar la búsqueda de eventos relacionados."<<endl;
    cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
    return 0;
  }

  ifstream fin (argv[1]);
    if (!fin){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  string palabra_clave ;
  bool salida_estandar;

  Cronologia c;
  fin >> c;

  int num_arg_salida;
  char opt_arg;
  if (argc == 2){
    cout << "Introduzca la palabra clave: ";    // se introducirá por teclado la palabra clave
    getline(cin,palabra_clave);
    salida_estandar = true;                     // e imprimirá el resultado por la salida estándar
  }
  else if(argc == 3){                           // Si se especifican tres argumentos se preguntará al usuario cuál es el tercero
    do{
      cout << "¿Es el tercer argumento la palabra_clave? (S/n) " << endl;
      cin >> opt_arg;
      opt_arg = tolower(opt_arg);

    } while(opt_arg!='s' && opt_arg!='n');

    if(opt_arg=='s'){
      palabra_clave = argv[2];
      salida_estandar = true;
    }
    else{
      cout << "Introduzca la palabra clave: ";
      cin.ignore();
      getline(cin,palabra_clave);

      salida_estandar = false;
      num_arg_salida = 2;
    }
  }
  else{
    palabra_clave = argv[2];
    salida_estandar = false;
    num_arg_salida = 3;
  }

  Cronologia filtrado(c, palabra_clave);

  if(salida_estandar)
    cout << filtrado;
  else{
    ofstream fout (argv[num_arg_salida]);
    if (!fout){
      cout<<"No puedo crear el fichero "<<argv[num_arg_salida]<<endl;
      return 0;
    }
    fout << filtrado;
    fout.close();
  }

  fin.close();
}