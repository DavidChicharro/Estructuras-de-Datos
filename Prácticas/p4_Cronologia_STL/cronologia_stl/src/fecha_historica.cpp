#include <iostream>
#include <string>
#include <cassert>
#include "fecha_historica.h"

using namespace std;


void FechaHistorica::Copia(const FechaHistorica &otra_fecha){
	hechos = otra_fecha.hechos;
}

bool FechaHistorica::EsMayor(const FechaHistorica &otra_fecha) {
	bool es_mayor;

	if(hechos.first > otra_fecha.hechos.first)
		es_mayor = true;
	else
		es_mayor = false;
	
	return es_mayor;
}

bool FechaHistorica::EsMenor(const FechaHistorica &otra_fecha) {
	bool es_menor;

	if(hechos.first < otra_fecha.hechos.first)
		es_menor = true;
	else
		es_menor = false;
	
	return es_menor;
}


void FechaHistorica::Crea(pair<int, set<string> > aconts){
	hechos = aconts;
}

FechaHistorica::FechaHistorica( ){ }

FechaHistorica::FechaHistorica(pair<int, set<string> > aconts){
	Crea(aconts);
}

FechaHistorica::FechaHistorica(int anio, set<string> hechos){
	pair<int, set<string> > acont = make_pair(anio, hechos);
	Crea(acont);
}

FechaHistorica::FechaHistorica(const FechaHistorica &otra_fecha){
	Copia(otra_fecha);
}

FechaHistorica::~FechaHistorica(){ }

void FechaHistorica::AniadirAcontecimiento(string acont){
	hechos.second.insert(acont);
}

int FechaHistorica::GetAnio() const{
	return hechos.first;
}

int FechaHistorica::GetNumAcontecimientos() const{
	return (hechos.second).size();
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &otra_fecha){
	if (this != &otra_fecha)
		Copia(otra_fecha);
	return *this;
}


bool FechaHistorica::operator>(const FechaHistorica &otra_fecha) {	
	return EsMayor(otra_fecha);
}

bool FechaHistorica::operator<(const FechaHistorica &otra_fecha) {
	return EsMenor(otra_fecha);
}

bool FechaHistorica::operator==(const FechaHistorica &otra_fecha) {
	return !(EsMayor(otra_fecha) || EsMenor(otra_fecha) );
}


FechaHistorica::iterator FechaHistorica::begin(){
	FechaHistorica::iterator it = (hechos.second).begin();
	return it;
}

FechaHistorica::iterator FechaHistorica::end(){
	FechaHistorica::iterator it = (hechos.second).end();
	return it;
}

FechaHistorica::const_iterator FechaHistorica::begin() const{
	FechaHistorica::const_iterator it = (hechos.second).begin();
	return it;
}

FechaHistorica::const_iterator FechaHistorica::end() const{
	FechaHistorica::const_iterator it = (hechos.second).end();
	return it;
}
