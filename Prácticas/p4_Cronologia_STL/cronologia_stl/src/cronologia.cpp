#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include "cronologia.h"
#include "fecha_historica.h"

using namespace std;

void Cronologia::Copia(const Cronologia &otra_cronologia){
	fechas = otra_cronologia.fechas;
}

bool Cronologia::ExisteFecha(int anio) const{
	bool existe_fecha = false;

	if (fechas.count(anio)>0)
		existe_fecha = true;

	return existe_fecha;
}

int Cronologia::MenorAnio() const{
	Cronologia::const_iterator it;
	it = this->begin();
	return it->first;	
}

int Cronologia::MayorAnio() const{
	Cronologia::const_iterator it;
	it = this->end();
	it--;
	return it->first;
}


Cronologia::Cronologia() { }

Cronologia::Cronologia(const Cronologia &crono){
	Copia(crono);
}

Cronologia::Cronologia(const FechaHistorica &fecha_historica){
	SetFechaHistorica(fecha_historica);
}

Cronologia::Cronologia(const Cronologia &crono, int anio_ini, int anio_fin){
	DevolverCronologia(crono, anio_ini, anio_fin);
}

Cronologia::Cronologia(const Cronologia &crono, string hecho){
	DevolverHechos(crono, hecho);
}

Cronologia::~Cronologia(){ }


int Cronologia::NumFechas(){
	return fechas.size();
}

int Cronologia::GetNumTotalAcontecimientos(){
	int num_acontecimientos = 0;
	Cronologia::const_iterator it;
	for(it = this->begin() ; it != this->end() ; ++it)
		num_acontecimientos += (it->second).GetNumAcontecimientos();

	return num_acontecimientos;
}

int Cronologia::GetMaxAcontecimientosAnio(){
	int max_aconticimientos = 0;

	Cronologia::const_iterator it;
	for(it = this->begin() ; it != this->end() ; ++it){
		int num_aconts = (it->second).GetNumAcontecimientos();
		if( num_aconts > max_aconticimientos)
			max_aconticimientos = num_aconts;
	}

	return max_aconticimientos;
}

double Cronologia::GetPromedioAcontecimientos(){
	return (GetNumTotalAcontecimientos() * 1.0) / NumFechas();
}

void Cronologia::SetFechaHistorica(const FechaHistorica &acont){
	int anio = acont.GetAnio();
	fechas.insert(make_pair(anio, acont));
}

FechaHistorica Cronologia::GetEventos(int anio){
	Cronologia::iterator it;
	it = fechas.find(anio);
	assert(it != fechas.end());
		return it->second;
}

void Cronologia::AniadirEventos(int anio, set<string> sucesos){
	if(!ExisteFecha(anio)){
		pair<int, set<string> > acont = make_pair(anio, sucesos);
		FechaHistorica nueva_fecha(acont);
		SetFechaHistorica(nueva_fecha);
	}
	else{
		Cronologia::iterator it;
		set<string>::iterator it_set;

		it = fechas.find(anio);
		if(it != fechas.end())
			for( it_set=sucesos.begin() ; it_set!= sucesos.end() ; ++it_set)
				(it->second).AniadirAcontecimiento(*it_set);
	}
}

void Cronologia::DevolverCronologia(const Cronologia &crono, int anio_ini, int anio_fin) {
	Cronologia::const_iterator it_ini, it_fin, it_anio;
	it_ini = crono.fechas.find(anio_ini);
	it_fin = crono.fechas.find(anio_fin);
	if(it_ini != crono.end() && it_fin != crono.end())
		for(it_anio = it_ini ; it_anio->first <= it_fin->first ; it_anio++)
			if(crono.ExisteFecha(it_anio->first))
				SetFechaHistorica(it_anio->second);
}

set<string> Cronologia::BuscarAcontecimientos(FechaHistorica fecha, string hecho) const {
	FechaHistorica::const_iterator it;
	set<string> aconts;

	for (it = fecha.begin() ; it != fecha.end() ; ++it){
		string evento = *it;
		int encontrado = evento.find(hecho);

		if (encontrado != -1)
			aconts.insert(evento);
	}

	return aconts;
}

void Cronologia::DevolverHechos(const Cronologia &crono, string hecho) {
	Cronologia::const_iterator it_cr;
	for(it_cr = crono.begin() ; it_cr != crono.end() ; ++it_cr){
		set<string> aconts = crono.BuscarAcontecimientos(it_cr->second, hecho);
		if (!aconts.empty())
			AniadirEventos(it_cr->first, aconts);
	}
	if (NumFechas() == 0)
		cerr << "No se han encontrado coincidencias con su búsqueda." << endl;
}

void Cronologia::Union(const Cronologia & c1, const Cronologia & c2){
	int primer_anio = c1.MenorAnio()<c2.MenorAnio() ? c1.MenorAnio():c2.MenorAnio();
	int ultimo_anio = c1.MayorAnio()>c2.MayorAnio() ? c1.MayorAnio():c2.MayorAnio();
   
	set<string> hechos;
	for (int i=primer_anio ; i<=ultimo_anio ; i++){
		bool existe_alguna_fh = false;
   	hechos.clear();
   	Cronologia::const_iterator it;
    if (c1.ExisteFecha(i)){
    	existe_alguna_fh = true;
      it = c1.fechas.find(i);
      if (it != c1.fechas.end()){
        FechaHistorica::const_iterator it_ev;
        for(it_ev = it->second.begin() ; it_ev != it->second.end() ; it_ev++)
          hechos.insert(*it_ev);
      }
    }
    if (c2.ExisteFecha(i)){
    	existe_alguna_fh = true;
      it = c2.fechas.find(i);
      if (it != c2.fechas.end()){
        FechaHistorica::const_iterator it_ev;
        for(it_ev = it->second.begin() ; it_ev != it->second.end() ; it_ev++)
          hechos.insert(*it_ev);
      }
    }
    if(existe_alguna_fh){
    	pair<int, set<string> > acont = make_pair(i, hechos);
			FechaHistorica nueva_fecha(acont);
			SetFechaHistorica(nueva_fecha);
		}
  }
}

Cronologia& Cronologia::operator=(const Cronologia &otra_cronologia) {
	if (this != &otra_cronologia)
		Copia(otra_cronologia);
	return *this;
}

Cronologia Cronologia::operator+(const Cronologia &crono) {
	Cronologia varias_cronos;

	varias_cronos.Union(*this, crono);
	
	return varias_cronos;
}

Cronologia::iterator Cronologia::begin (){
	Cronologia::iterator it = fechas.begin();
	return it;
}

Cronologia::const_iterator Cronologia::begin () const{	
	Cronologia::const_iterator it = fechas.begin();
	return it;
}

Cronologia::iterator Cronologia::end (){
	Cronologia::iterator it = fechas.end();
	return it;
}

Cronologia::const_iterator Cronologia::end () const{
	Cronologia::const_iterator it = fechas.end();
	return it;
}

istream& operator>> (istream& is, Cronologia &cr) {
	bool continuar = true;

	while(continuar){
		string texto;
		string year;
		string suceso;
		int anio;

		getline(is, texto);		
		
		if (texto.empty())
			continuar = false;
		
		if (continuar){
			unsigned int hash = texto.find('#');		// hash almacena la posicion de la almohadilla

			for (unsigned int i=0 ; i<hash ; i++)
				year.push_back(texto[i]);					// year almacena un string con el año
			anio = atoi(year.c_str());					// anio recibe el string del año convertido a entero
			hash++;
			set<string> hecho;
			while (hash < texto.length()){
				if (texto[hash] == '#'){
					hecho.insert(suceso);
					suceso.clear();
				}
				else
					suceso.push_back(texto[hash]);

				hash++;
			}
			hecho.insert(suceso);
			pair<int, set<string> > acont = make_pair(anio, hecho);
			FechaHistorica nueva_fecha(acont);
			cr.SetFechaHistorica(nueva_fecha);

			suceso.clear();
			texto.clear();
			year.clear();			
		}
	}
	return is;
}

ostream& operator<< (ostream& os, const Cronologia &mi_crono){
	Cronologia::const_iterator crono_it;
	for(crono_it = mi_crono.begin() ; crono_it != mi_crono.end() ; ++crono_it){
		os << "Año: " << crono_it->first << endl;
		os << "Hechos: \n";
		FechaHistorica::const_iterator it_ev;
		for(it_ev = crono_it->second.begin() ; it_ev != crono_it->second.end() ; ++it_ev)
			os << *it_ev << endl;
		os << endl;
	}

  return os;
}