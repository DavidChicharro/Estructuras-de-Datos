/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef CRONOLOGIA
#define CRONOLOGIA

#include <iostream>
#include <string>
#include <map>
#include "fecha_historica.h"
using namespace std;

/**
  * @brief T.D.A. Cronología
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * que contiene una cronología de acontecimientos, hechos o eventos, ordenados
  * cronológicamente por años. Cada objeto posee una secuencia de fechas históricas
  * en la que cada una tiene los diversos hechos.
  *
  * @author David Carrasco Chicharro
  * @date Diciembre 2017
  *
  */

class Cronologia {

private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de representación
  * El invatiente es \e anio > 0
  * 
  * @section faConjunto Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Cronología representa el valor
  *
  * Fecha: \n
  * Hechos:
  *
  */

  map<int, FechaHistorica> fechas; /**< Año y conjunto de fechas históricas asociadas */


/**
  * @brief Copia otro objeto de la misma clase
  * @param otra_cronologia Objeto de la cronología a copiar
  */
	void Copia(const Cronologia &otra_cronologia);

/**
  * @brief Busca un año en la cronología y dice si está en ella o no
  * @param anio Año que se desea saber si existe en la cronología
  * @return Devuelve true si existe la fecha y false en caso contrario
  */
	bool ExisteFecha(int anio) const;

/**
  * @brief Menor año
  * @return Devuelve el primer año de una cronología
  */
	int MenorAnio() const;

/**
  * @brief Mayor año
  * @return Devuelve el último año de una cronología
  */
	int MayorAnio() const;

public:

typedef typename map<int, FechaHistorica>::iterator iterator;
typedef typename map<int, FechaHistorica>::const_iterator const_iterator;

/**
  * @brief Constructor por defecto de la clase.
  * Crea una cronología vacía.
  */
	Cronologia();

/**
  * @brief Constructor de copia de la clase.
  * @param crono Cronología que será copiada
  */
	Cronologia(const Cronologia &crono);

/**
  * @brief Constructor de la clase.
  * @param fecha_historica Fecha Histórica que será copiada
  */
  Cronologia(const FechaHistorica &fecha_historica);

/**
  * @brief Constructor de la clase
  * @param crono Cronología desde la que se copian una serie 
  * de fechas históricas en un rango de años
  * @param anio_ini Año inicial desde el que se va a copiar
  * @param anio_fin Año final desde el que se va a copiar
  */
	Cronologia(const Cronologia &crono, int anio_ini, int anio_fin);

/**
  * @brief Constructor de la clase. Crea una cronología relativa a un hecho
  * @param crono Cronología en la que se busca el hecho
  * @param hecho Suceso del que se quiere encontrar una cronología
  */
	Cronologia(const Cronologia &crono, string hecho);

/**
  * @brief Destructor de la clase
  */
	~Cronologia();

/**
  * @brief Número de fechas históricas
  * @return Devuelve el número de fechas históricas almacenadas
  */
	int NumFechas();

/**
  * @brief Número de acontecimientos
  * @return Devuelve el número total de acontecimientos
  * que hay entre todas las fechas históricas almacenadas
  */
  int GetNumTotalAcontecimientos();

/**
  * @brief Máximo número de acontecimientos
  * @return Devuelve máximo número de acontecimientos que
  * se da entre todas las fechas históricas almacenadas
  */
  int GetMaxAcontecimientosAnio();

/**
  * @brief Promedio de acontecimientos
  * @return Devuelve número promedio de acontecimientos que
  * se da entre todas las fechas históricas de la cronología
  */
  double GetPromedioAcontecimientos();

/**
  * @brief Inserta una nueva fecha histórica en la cronología
  * @param acont FechaHistorica que se inserta
  */
  void SetFechaHistorica(const FechaHistorica &acont);

/**
  * @brief Eventos acaecidos en un año
  * @param anio Año del que se desea obtener una fecha histórica
  * @return Devuelve una fecha histórica con todos sus eventos de un año dado
  */
  FechaHistorica GetEventos(int anio);

/**
  * @brief Añade un conjunto de eventos en un año concreto. 
  * Si existe el año, se añade en la fecha histórica 
  * de dicha fecha; en caso de no existir, crea una nueva 
  * fecha histórica y añade el evento.
  * @param anio Año en el que ocurren los eventos
  * @param sucesos Conjunto de acontecimientos que se desean añadir
  * @pre Debe existir el año que se va a copiar en el objeto original
  */
	void AniadirEventos(int anio, set<string> sucesos);

/**
  * @brief Dada una cronología original, establece una subcronología
  * de un año o un rango de años
  * @param crono Cronología desde el que van a ser copiadas las fechas históricas
  * @param anio_ini Año desde el que se va a copiar la cronología
  * @param anio_fin Año hasta el que se va a copiar la cronología
  */
	void DevolverCronologia(const Cronologia &crono, int anio_ini, int anio_fin);

/**
  * @brief Busca en la cronología un acontecimiento y en caso de existir
  * añadel el evento a un conjunto de éstos
  * @param fecha Fecha Histórica donde se desea buscar el evento
  * @param hecho Palabra clave del que desea hallar
  * @return Devuelve el conjunto de acontecimientos de la fecha histórica
  * en el que se hallaba la palabra clave
  */
	set<string> BuscarAcontecimientos(FechaHistorica fecha, string hecho) const;

/**
  * @brief Devuelve una cronología asociada a un hecho, suceso, evento, personaje, etc.
  * @param crono Cronología en la que se desea buscar un evento
  * @param hecho Evento que se desea buscar
  */
	void DevolverHechos(const Cronologia &crono, string hecho);

/**
  * @brief Une dos cronologías en una sola
  * @param c1 Primera cronología
  * @param c2 Segunda cronología
  */
  void Union(const Cronologia & c1, const Cronologia & c2);

/**
  * @brief Sobrecarga del operador de asignación
  * @param otra_cronologia Cronología a asignar
  * @pre otra_cronologia no debe ser el mismo objeto de la clase
  */
	Cronologia& operator=(const Cronologia &otra_cronologia);

/**
  * @brief Sobrecarga del operador de suma
  * @param crono Cronología que se desea añadir a la ya existente
  * @return Devuelve una cronología a la que se han añadido otras varias
  */
	Cronologia operator+(const Cronologia &crono);

/**
 * @brief Iterador al inicio de la cronología
 * @return Devuleve el iterador
 */
  iterator begin ();

/**
 * @brief Iterador constante al inicio de la cronología
 * @return Devuleve el iterador
 */
  const_iterator begin () const;

/**
 * @brief Iterador al final (siguiente al últimio) de la cronología
 * @return Devuleve el iterador
 */
  iterator end ();

/**
 * @brief Iterador constante al final (siguiente al últimio) de la cronología
 * @return Devuleve el iterador
 */
  const_iterator end () const;

/**
  * @brief Entrada de una Cronología desde istream
  * @param is stream de entrada
  * @param cr Crolonología que recibe el valor
  * @retval La Cronología leída en cr
  */
	friend istream& operator>> (istream& is, Cronologia &cr);

/**
  * @brief Salida de una cronología a ostream
  * @param os stream de salida
  * @param mi_crono Cronología a escribir
  */
	friend ostream& operator<< (ostream& os, const Cronologia &mi_crono);
};

#endif