#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include "cronologia.h"
#include "fecha_historica.h"

using namespace std;
 

void Cronologia::Reserva(int num){
		vec_fechas = new FechaHistorica[num];
}

void Cronologia::Inicializa(int n) {
	if (n >= 0){	
		num_fechas = n;
		Reserva(num_fechas);
	}
}

void Cronologia::Resize(int n) {
  assert(n>=0);
  if(n != num_fechas){
    if (n!=0){
      FechaHistorica *nuevas_fechas = new FechaHistorica[n];
      if (num_fechas>0){
        int minimo = n<num_fechas?n:num_fechas;
        for(int i=0 ; i<minimo ; i++){
        	nuevas_fechas[i].fecha = vec_fechas[i].fecha;
        	int n_ac = vec_fechas[i].num_aconts;
        	nuevas_fechas[i].num_aconts = n_ac;
        	nuevas_fechas[i].ptr_acont = new string[n_ac];
        	for(int j=0 ; j<n_ac ; j++)
        		nuevas_fechas[i].ptr_acont[j] = vec_fechas[i].ptr_acont[j];
        }
        delete[] vec_fechas;
      }
      num_fechas = n;
      vec_fechas = nuevas_fechas;
    }
    else{ //Si n==0
      if(num_fechas>0)
        delete[] vec_fechas;
      vec_fechas = 0;
      num_fechas = 0;
    }
  }
}

void Cronologia::Copia(const Cronologia &otra_cronologia){
	Inicializa(otra_cronologia.num_fechas);
	for (int i=0 ; i<num_fechas; i++){
		vec_fechas[i].fecha = otra_cronologia.vec_fechas[i].fecha;
		vec_fechas[i].num_aconts = otra_cronologia.vec_fechas[i].num_aconts;
		vec_fechas[i].Reserva(vec_fechas[i].num_aconts);
		for (int j=0 ; j<vec_fechas[i].num_aconts ; j++)
			vec_fechas[i].ptr_acont[j] = otra_cronologia.vec_fechas[i].ptr_acont[j];
	}
}

void Cronologia::Destruye(){
	if (num_fechas > 0){
		delete [] vec_fechas;
		vec_fechas = 0;
	}
}

bool Cronologia::Esta_Ordenada(){
	bool esta_ordenada = true;
	int fecha_ant = vec_fechas[0].fecha;

	for (int i=1 ; i<num_fechas && esta_ordenada ; i++){
		if (vec_fechas[i].fecha > fecha_ant)
			fecha_ant = vec_fechas[i].fecha;
		else
			esta_ordenada = false;
	}

	return esta_ordenada;
}

int Cronologia::Posicion_Anio (int anio) const {
	bool continuar = true;
	int pos_anio = -1;
	for (int i=0 ; i<num_fechas && continuar ; i++)
		if(vec_fechas[i].fecha == anio){
			pos_anio = i;
			continuar = false;
		}

	return pos_anio;
}

bool Cronologia::Existe_Fecha(int anio) const{
	bool existe_fecha = false;

	for (int i=0 ; i<num_fechas && !existe_fecha ; i++)
		if(vec_fechas[i].fecha == anio)
			existe_fecha = true;

	return existe_fecha;
}

int Cronologia::Menor_Anio() const{
	return vec_fechas[0].Get_Anio();
}

int Cronologia::Mayor_Anio() const{
	return vec_fechas[num_fechas-1].Get_Anio();
}

void Cronologia::Ordenar(){
	if(!Esta_Ordenada()){
		bool cambio = true;
		for (int i=0 ; i<num_fechas-1 && cambio ; i++){
			cambio = false;
			for(int j=0 ; j < num_fechas-i-1 ; j++)
				if (vec_fechas[j] > vec_fechas[j+1]){
					cambio=true;
					FechaHistorica fecha_aux = vec_fechas[j];
					vec_fechas[j] = vec_fechas[j+1];
					vec_fechas[j+1] = fecha_aux;
				}
		}
	}
}


Cronologia::Cronologia() {
	Inicializa(0);
}

Cronologia::Cronologia(int n){
	Inicializa(n);
}

Cronologia::Cronologia(const Cronologia &crono){
	Copia(crono);
}

Cronologia::Cronologia(const Cronologia &crono, int anio){
	assert(crono.Existe_Fecha(anio));
	Devolver_Cronologia(crono, anio,0);
}

Cronologia::Cronologia(const Cronologia &crono, int anio_ini, int anio_fin){
	Devolver_Cronologia(crono, anio_ini, anio_fin);
}

Cronologia::Cronologia(const Cronologia &crono, string hecho){
	Devolver_Hechos(crono, hecho);
}

Cronologia::~Cronologia(){
	Destruye();
}

int Cronologia::Num_Fechas() {
	return num_fechas;
}

void Cronologia::Aniadir_Evento(int anio, string acont) {
	if (Existe_Fecha(anio)){
		int pos_anio = Posicion_Anio(anio);
		int n_ac = vec_fechas[pos_anio].Get_Num_Aconts();

		vec_fechas[pos_anio].Resize(n_ac+1);
		vec_fechas[pos_anio].Aniadir_Acontecimiento(acont, n_ac);
	}
	else{
		FechaHistorica nueva_fecha(anio, 1);
		nueva_fecha.Aniadir_Acontecimiento(acont, nueva_fecha.num_aconts-1);
		Resize(num_fechas+1);
		vec_fechas[num_fechas-1] = nueva_fecha;
	}
	Ordenar();
}


void Cronologia::Devolver_Cronologia(const Cronologia &crono, int anio_ini, int anio_fin) {
	int num_anios = anio_fin - anio_ini + 1;
	int ini = num_anios>0?num_anios:1;

	Inicializa(0);

	for (int i=0 ; i<ini ; i++){
		assert(crono.Existe_Fecha(anio_ini+i));
		int pos_anio = crono.Posicion_Anio(anio_ini+i);		
		for (int j=0 ; j<crono.vec_fechas[pos_anio].num_aconts ; j++)
			Aniadir_Evento(anio_ini+i, crono.vec_fechas[pos_anio].ptr_acont[j]);
	}
}

int Cronologia::Buscar_Acontecimientos(string hecho, int pos_fecha) const {
	int pos_acont = -1;
	for (int i=0 ; i<vec_fechas[pos_fecha].num_aconts ; i++){
		string evento = vec_fechas[pos_fecha].ptr_acont[i];
		int encontrado = evento.find(hecho);

		if (encontrado != -1)
			pos_acont = i;
	}
	return pos_acont;
}


void Cronologia::Devolver_Hechos(const Cronologia &crono, string hecho) {
	Inicializa(0);
	for (int i=0 ; i<crono.num_fechas ; i++){
		int pos_acont = crono.Buscar_Acontecimientos(hecho, i);
		if (pos_acont != -1)
			Aniadir_Evento(crono.vec_fechas[i].fecha, crono.vec_fechas[i].ptr_acont[pos_acont]);
	}
	if (num_fechas == 0)
		cerr << "No se han encontrado coincidencias con su busqueda." << endl;
}


Cronologia& Cronologia::operator=(const Cronologia &otra_cronologia) {
	if (this != &otra_cronologia)
		Copia(otra_cronologia);
	return *this;
}


Cronologia Cronologia::operator+(const Cronologia &crono) {
	Cronologia varias_cronos(0);

	int primer_anio = Menor_Anio()<crono.Menor_Anio() ? Menor_Anio():crono.Menor_Anio();
	int ultimo_anio = Mayor_Anio()>crono.Mayor_Anio() ? Mayor_Anio():crono.Mayor_Anio();

	int k=0; int l=0;
	for (int i=0 ; primer_anio+i <= ultimo_anio ; i++){
		if (Existe_Fecha(primer_anio + i)){			
			for (int j=0 ; j<vec_fechas[k].num_aconts ; j++)
				varias_cronos.Aniadir_Evento(vec_fechas[k].fecha, vec_fechas[k].Get_Puntero_Acont(j));
			k++;
		}		
		if (crono.Existe_Fecha(primer_anio + i)){
			for (int j=0 ; j<crono.vec_fechas[l].num_aconts ; j++)
				varias_cronos.Aniadir_Evento(crono.vec_fechas[l].fecha, crono.vec_fechas[l].Get_Puntero_Acont(j));
			l++;
		}
	}
	
	return varias_cronos;
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
				year.push_back(texto[i]);				// year almacena un string con el año
			anio = atoi(year.c_str());					// anio recibe el string del año convertido a entero
			cr.Resize(cr.num_fechas + 1);				// Redimensiona el vector de FechaHistorica añadiendo una casilla
			
			int num_eventos = 0;
			for (unsigned int i=0 ; i<texto.size() ; i++)	// Calcula el número de acontecimientos en una fecha
				if (texto.at(i) == '#')
					num_eventos++;

			FechaHistorica nueva_fecha(anio, num_eventos);
			hash++;

			int pos_suceso = 0;
			while (hash < texto.length()) {
				if (texto[hash] == '#'){
					nueva_fecha.Aniadir_Acontecimiento(suceso, pos_suceso);
					pos_suceso++;
					suceso.clear();
				}
				else
					suceso.push_back(texto[hash]);

				hash++;
			}

			nueva_fecha.Aniadir_Acontecimiento(suceso, pos_suceso);
			
			cr.vec_fechas[cr.num_fechas-1] = nueva_fecha;

			suceso.clear();
			texto.clear();
			year.clear();			
		}
	}
	return is;
}

ostream& operator<< (ostream& os, const Cronologia &mi_crono){
	for (int i=0 ; i<mi_crono.num_fechas ; i++) {
  		os << "Anio: " << mi_crono.vec_fechas[i].Get_Anio() << endl;
  		os << "Hechos: \n";
  		for (int j=0; j<mi_crono.vec_fechas[i].Get_Num_Aconts() ; j++)
    		os << mi_crono.vec_fechas[i].Get_Puntero_Acont(j) << endl;
    	os << endl;
    }
  	os << endl;

  	return os;
}