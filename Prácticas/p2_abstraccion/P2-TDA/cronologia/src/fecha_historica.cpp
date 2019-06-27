#include <iostream>
#include <string>
#include <cassert>
#include "fecha_historica.h"
using namespace std;

void FechaHistorica::Reserva(int num){
	ptr_acont = new string[num];
}

void FechaHistorica::Inicializa(int fecha, int num_aconts){
	if (num_aconts >= 0){
		this->fecha = fecha;
		this->num_aconts = num_aconts;
		Reserva(num_aconts);
	}
}

void FechaHistorica::Resize(int n){
	assert(n>=0);
	if(n != num_aconts){
		if (n!=0){
			string *nuevos_aconts = new string[n];
			if (num_aconts>0){
				int minimo = n<num_aconts?n:num_aconts;
				for(int i=0 ; i<minimo ; i++)
					nuevos_aconts[i] = ptr_acont[i];
				delete[] ptr_acont;
			}
			num_aconts = n;
			ptr_acont = nuevos_aconts;
		}
		else{ //Si n==0
		  if(num_aconts>0)
		    delete[] ptr_acont;
		  ptr_acont = 0;
		  num_aconts = 0;
		}
	}
}

void FechaHistorica::Copia(const FechaHistorica &otra_fecha){
	Inicializa(otra_fecha.fecha, otra_fecha.num_aconts);
	for (int i=0 ; i<num_aconts ; i++)
		ptr_acont[i] = otra_fecha.ptr_acont[i];
}

void FechaHistorica::Destruye(){
	if (num_aconts > 0){
		delete [] ptr_acont;
		ptr_acont = 0;
	}
}

bool FechaHistorica::Es_Mayor(const FechaHistorica &otra_fecha) {
	bool es_mayor;

	if(fecha > otra_fecha.fecha)
		es_mayor = true;
	else
		es_mayor = false;
	
	return es_mayor;
}

bool FechaHistorica::Es_Menor(const FechaHistorica &otra_fecha) {
	bool es_menor;

	if(fecha < otra_fecha.fecha)
		es_menor = true;
	else
		es_menor = false;
	
	return es_menor;
}

FechaHistorica::FechaHistorica() { }

FechaHistorica::FechaHistorica(const FechaHistorica &otra_fecha){
	Copia(otra_fecha);
}

FechaHistorica::FechaHistorica(int fecha, int num_aconts){
	Inicializa(fecha, num_aconts);
}

FechaHistorica::~FechaHistorica(){
	Destruye();
}


void FechaHistorica::Aniadir_Acontecimiento(string suceso, int pos_suceso){
	if (pos_suceso >= 0)
		ptr_acont[pos_suceso] = suceso;
}

int FechaHistorica::Get_Anio(){
	return fecha;
}

int FechaHistorica::Get_Num_Aconts(){
	return num_aconts;
}

string FechaHistorica::Get_Puntero_Acont(int indice){
	assert (indice >= 0);
	return ptr_acont[indice];
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &otra_fecha){
	if (this != &otra_fecha)
		Copia(otra_fecha);
	return *this;
}


bool FechaHistorica::operator>(const FechaHistorica &otra_fecha) {	
	return Es_Mayor(otra_fecha);
}

bool FechaHistorica::operator<(const FechaHistorica &otra_fecha) {
	return Es_Menor(otra_fecha);
}

bool FechaHistorica::operator==(const FechaHistorica &otra_fecha) {
	return !(Es_Mayor(otra_fecha) || Es_Menor(otra_fecha) );
}