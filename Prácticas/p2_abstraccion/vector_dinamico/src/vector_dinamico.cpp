//
//  vector_dinamico.cpp
//  ejemplo_vector_dinamico
//
//  Created by Javier Abad on 15/8/17.
//  Copyright © 2017 Javier Abad. All rights reserved.
//

#include <cassert>
#include "vector_dinamico.h"

Vector_Dinamico::Vector_Dinamico(int n){
  assert(n>=0);
  if (n>0)
    datos = new float[n];
  nelementos = n;
}

Vector_Dinamico::Vector_Dinamico(const Vector_Dinamico & original){
  nelementos = original.nelementos;
  if(nelementos>0){
    datos = new float[nelementos];
    for(int i=0; i<nelementos; i++)
      datos[i] = original.datos[i];
  }
  else
    nelementos = 0;
}

Vector_Dinamico::~Vector_Dinamico(){
  if (nelementos>0)
    delete []datos;
}

int Vector_Dinamico::size() const{
  return nelementos;
}

void Vector_Dinamico::resize(int n){
  assert(n>=0);
  if(n != nelementos){
    if (n!=0){
      float* nuevos_datos = new float[n];
      if (nelementos>0){
        int minimo = n<nelementos?n:nelementos;
        for(int i=0; i<minimo; i++)
          nuevos_datos[i] = datos[i];
        delete[] datos;
      }
      nelementos = n;
      datos = nuevos_datos;
    }
    else{ //Si n==0
      if(nelementos>0)
        delete[] datos;
      datos = 0;
      nelementos=0;
    }
  }
}



float& Vector_Dinamico::operator[](const int i){
  assert(i>=0 && i<nelementos);
  return datos[i];
}

const float& Vector_Dinamico::operator[](const int i)const{
  assert(i>=0 && i<nelementos);
  return datos[i];
}

Vector_Dinamico& Vector_Dinamico::operator=(const Vector_Dinamico &original){
  if (this != &original)
    if (nelementos>0)
      delete[] datos;
  nelementos = original.nelementos;
  if (nelementos>0){
    datos = new float[nelementos];
    for(int i=0; i<nelementos; i++)
      datos[i] = original.datos[i];
  }
  return *this;
}


