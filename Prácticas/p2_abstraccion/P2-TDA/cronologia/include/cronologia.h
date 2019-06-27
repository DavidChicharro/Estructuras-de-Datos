/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef CRONOLOGIA
#define CRONOLOGIA

#include <iostream>
#include <string>
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
  * @date Octubre 2017
  *
  */

class Cronologia {

private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de representación
  * El invatiente es \e num_fechas > 0
  * 
  * @section faConjunto Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Cronología representa el valor
  *
  * Fecha: \n
  * Hechos:
  *
  */

	int num_fechas; /**< número de fechas */
	FechaHistorica *vec_fechas; /**< puntero al vector de fechas históricas */

/**
  * @brief Reserva un número determinado de fechas históricas
  * @param num número de fechas históricas a reservar
  */
	void Reserva(int num);

/**
  * @brief Establece el número de fechas y manda reservar tantas casillas
  * del vector de fechas como número de fechas se establezca
  * @param n número de fechas a inicializar
  * @pre n debe ser mayor o igual que cero
  */	
	void Inicializa(int n);

/**
  * @brief Redimensiona el vector de fechas históricas
  * @param n nuevo número de elementos del vector
  * @pre n debe ser mayor o igual que cero
  */
	void Resize(int n);

/**
  * @brief Copia otro objeto de la misma clase
  * @param otra_cronologia Objeto de la cronología a copiar
  */
	void Copia(const Cronologia &otra_cronologia);

/**
  * @brief Elimina de memoria dinámica el vector de fechas históricas
  * @pre num_fechas debe ser mayor que 0
  */
	void Destruye();

/**
  * @brief Comprueba si la cronología está ordenada cronológicamente
  * @return Devuelve true si está ordenada y false en caso contrario
  */
	bool Esta_Ordenada();

/**
  * @brief Busca la posición en vec_fechas donde se encuentra un año dado
  * @param anio Año de la posición a buscar
  * @return Devuelve la posición del año en el vector de fechas históricas
  */
	int Posicion_Anio (int anio) const;

/**
  * @brief Busca un año en la cronología y dice si está en ella o no
  * @param anio Año que se desea saber si existe en la cronología
  * @return Devuelve true si existe la fecha y false en caso contrario
  */
	bool Existe_Fecha(int anio) const;

/**
  * @brief Menor año
  * @return Devuelve el primer año de una cronología
  */
	int Menor_Anio() const;

/**
  * @brief Mayor año
  * @return Devuelve el último año de una cronología
  */
	int Mayor_Anio() const;

/**
  * @brief Ordena la cronología en orden cronológico. Si está previamente
  * ordenada no hace nada.
  */
	void Ordenar();

public:

/**
  * @brief Constructor por defecto de la clase.
  * Crea un vector de fechas históricas vacío.
  */
	Cronologia();

/**
  * @brief Constructor de la clase
  * @param n número de fechas históricas con el que construir la cronología
  */
	Cronologia(int n);

/**
  * @brief Constructor de copia de la clase.
  * @param crono Cronología que será copiada
  */
	Cronologia(const Cronologia &crono);

/**
  * @brief Constructor de la clase
  * @param crono Cronología desde la que se copia la fecha histórica
  * @param anio Año que se va a copiar
  * @pre Debe existir el año que se va a copiar en el objeto original
  */
	Cronologia(const Cronologia &crono, int anio);

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
	int Num_Fechas();

/**
  * @brief Añade un evento en un año concreto. Si existe el año, se añade en la fecha histórica 
  * de dicha fecha; en caso de no existir, crea una nueva fecha histórica y añade el evento. En
  * caso de haber sido alterada la cronología, se ordena.
  * @param anio Año en el que ocurre el evento
  * @param acont Acontecimiento que se desea añadir
  * @pre Debe existir el año que se va a copiar en el objeto original
  */
	void Aniadir_Evento(int anio, string acont);

/**
  * @brief Dada un cronología original, establece una subcronología de un año o un rango de años
  * @param crono Cronología desde el que van a ser copiadas las fechas históricas
  * @param anio_ini Año desde el que se va a copiar la cronología
  * @param anio_fin Año hasta el que se va a copiar la cronología
  */
	void Devolver_Cronologia(const Cronologia &crono, int anio_ini, int anio_fin);

/**
  * @brief Busca en la cronología un acontecimiento y en caso de existir devuelve la posición
  * en donde se encuentra en el vector de acontecimientos de la fecha histórica
  * @param hecho Suceso o evento a buscar
  * @param pos_fecha Posición de la fecha en el vector de fechas históricas
  */
	int Buscar_Acontecimientos(string hecho, int pos_fecha) const;

/**
  * @brief Devuelve una cronología asociada a un hecho, suceso, evento, personaje, etc.
  * @param crono Cronología en la que se desea buscar un evento
  * @param hecho Evento que se desea buscar
  */
	void Devolver_Hechos(const Cronologia &crono, string hecho);

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