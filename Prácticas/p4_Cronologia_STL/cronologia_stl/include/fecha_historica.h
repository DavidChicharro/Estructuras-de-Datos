/**
  * @file fecha_historica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */

#ifndef FECH_HIST
#define FECH_HIST

#include <iostream>
#include <set>
#include <string>
using namespace std;

/**
  * @brief T.D.A. Fecha Histórica
  * Una instancia @e f del tipo de datos abstracto @c FechaHistorica es un objeto
  * que contiene un año y una serie de acontecimientos de diversa índole
  *
  * @author David Carrasco Chicharro
  * @date Diciembre 2017
  *
  */

class FechaHistorica {
friend class Cronologia;

private:
/**
  * @page repConjunto Rep del TDA Fecha Histórica
  *
  * @section invConjunto Invariante de representación
  * El invatiente es \e anio > 0
  * 
  * @section faConjunto Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Fecha Histórica representa el valor
  *
  * Fecha: \n
  * Hechos:
  *
  */

  pair<int, set<string> > hechos; /**< Año y conjunto de acontecimientos */


/**
  * @brief Copia otro objeto de la misma clase
  * @param otra_fecha Objeto de la cronología a copiar
  */
	void Copia(const FechaHistorica &otra_fecha);

/**
  * @brief Compara si una fecha es mayor que otra, siendo la mayor aquélla más reciente
  * @param otra_fecha Fecha histórica a comparar
  */
	bool EsMayor(const FechaHistorica &otra_fecha);

/**
  * @brief Compara si una fecha es menor que otra, siendo la menor aquélla más lejana en el tiempo
  * @param otra_fecha Fecha histórica a comparar
  */
	bool EsMenor(const FechaHistorica &otra_fecha);

/**
  * @brief Crea una fecha histórica a partir de una serie de acontecimientos
  * @param aconts Conjunto de acontecimientos
  */
  void Crea(pair<int, set<string> > aconts);


public:
  
  typedef typename set<string>::iterator iterator;
  typedef typename set<string>::const_iterator const_iterator;

/**
  * @brief Constructor por defecto de la clase.
  */
  FechaHistorica( );

/**
  * @brief Constructor de la clase.
  * @param aconts Conjunto de acontecimientos
  */
	FechaHistorica(pair<int, set<string> > aconts);

/**
  * @brief Constructor de la clase con una fecha y un número de acontecimientos concretos
  * @param anio Año de la cronología a crear
  * @param hechos Conjunto de acontecimientos de la fecha histórica
  */
  FechaHistorica(int anio, set<string> hechos);

/**
  * @brief Constructor de copia de la clase.
  * @param otra_fecha Fecha Histórica que será copiada
  */
	FechaHistorica(const FechaHistorica &otra_fecha);


/**
  * @brief Destructor de la clase
  */
	~FechaHistorica();

/**
  * @brief Añade un acontecimiento a la fecha histórica
  * @param acont Acontecimiento a añadir
  */
	void AniadirAcontecimiento(string acont);


/**
  * @brief Año
  * @return Devuelve el año de la fecha histórica
  */
	int GetAnio() const;

/**
  * @brief Número de acontecimientos
  * @return Devuelve el número de acontecimientos de la fecha histórica
  */
	int GetNumAcontecimientos() const;

/**
  * @brief Sobrecarga del operador de asignación
  * @param otra_fecha Fecha Histórica a asignar  
  * @pre otra_fecha no debe ser el mismo objeto de la clase
  */
	FechaHistorica& operator=(const FechaHistorica &otra_fecha);

/**
  * @brief Sobrecarga del operador de comparación (mayor)
  * @param otra_fecha Fecha Histórica a comparar
  * @return Devuelve true si la fecha con la que se compara es más reciente 
  * y false en caso contrario
  */
	bool operator>(const FechaHistorica &otra_fecha);

/**
  * @brief Sobrecarga del operador de comparación (menor)
  * @param otra_fecha Fecha Histórica a comparar
  * @return Devuelve true si la fecha con la que se compara es más antigua 
  * y false en caso contrario
  */
	bool operator<(const FechaHistorica &otra_fecha);

/**
  * @brief Sobrecarga del operador de comparación (igualdad)
  * @param otra_fecha Fecha Histórica a comparar
  * @return Devuelve true si la fecha con la que se compara es la misma 
  * y false en caso contrario
  */
	bool operator==(const FechaHistorica &otra_fecha);

/**
 * @brief Iterador al inicio de la fecha histórica
 * @return Devuleve el iterador
 */
  iterator begin ();

/**
 * @brief Iterador constante al inicio de la fecha histórica
 * @return Devuleve el iterador
 */
  const_iterator begin () const;

/**
 * @brief Iterador al final (siguiente al últimio) de la fecha histórica
 * @return Devuleve el iterador
 */
  iterator end ();

/**
 * @brief Iterador constante al final (siguiente al últimio) de la fecha histórica
 * @return Devuleve el iterador
 */
  const_iterator end () const;
  
};

#endif