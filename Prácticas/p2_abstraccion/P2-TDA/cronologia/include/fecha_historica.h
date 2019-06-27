/**
  * @file fecha_historica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */

#ifndef FECH_HIST
#define FECH_HIST

#include <iostream>
#include <string>
using namespace std;

/**
  * @brief T.D.A. Fecha Histórica
  * Una instancia @e f del tipo de datos abstracto @c FechaHistorica es un objeto
  * que contiene un año y una serie de acontecimientos de diversa índole
  *
  * @author David Carrasco Chicharro
  * @date Octubre 2017
  *
  */

class FechaHistorica {
friend class Cronologia;

private:
/**
  * @page repConjunto Rep del TDA Fecha Histórica
  *
  * @section invConjunto Invariante de representación
  * El invatiente es \e num_aconts > 0
  * 
  * @section faConjunto Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Fecha Histórica representa el valor
  *
  * Fecha: \n
  * Hechos:
  *
  */

	int fecha; /**< fecha */
	string *ptr_acont; /**<puntero al vector de acontecimientos */
	int num_aconts; /**< número de acontecimientos */

/**
  * @brief Reserva un número determinado de acontecimientos
  * @param num número de acontecimientos a reservar
  */
	void Reserva(int num);

/**
  * @brief Asigna la fecha y el número de acontecimientos y manda reservar tantas casillas
  * del vector acontecimientos como número de de éstos se haya establecido
  * @param fecha Año en el que suceden los acontecimientos
  * @param num_aconts número de acontecimientos a inicializar
  * @pre num_aconts debe ser mayor o igual que cero
  */
	void Inicializa(int fecha, int num_aconts);

/**
  * @brief Redimensiona el vector de acontecimientos
  * @param n nuevo número de elementos del vector
  * @pre n debe ser mayor o igual que cero
  */
	void Resize(int n);

/**
  * @brief Copia otro objeto de la misma clase
  * @param otra_fecha Objeto de la cronología a copiar
  */
	void Copia(const FechaHistorica &otra_fecha);

/**
  * @brief Elimina de memoria dinámica el vector de acontecimientos
  * @pre num_aconts debe ser mayor que 0
  */
	void Destruye();

/**
  * @brief Compara si una fecha es mayor que otra, siendo la mayor aquélla más reciente
  * @param otra_fecha Fecha histórica a comparar
  */
	bool Es_Mayor(const FechaHistorica &otra_fecha);

/**
  * @brief Compara si una fecha es menor que otra, siendo la menor aquélla más lejana en el tiempo
  * @param otra_fecha Fecha histórica a comparar
  */
	bool Es_Menor(const FechaHistorica &otra_fecha);

public:

/**
  * @brief Constructor por defecto de la clase.
  */
	FechaHistorica();

/**
  * @brief Constructor de copia de la clase.
  * @param otra_fecha Fecha Histórica que será copiada
  */
	FechaHistorica(const FechaHistorica &otra_fecha);

/**
  * @brief Constructor de la clase con una fecha y un número de acontecimientos concretos
  * @param fecha Año de la cronología a crear
  * @param num_aconts Número de acontecimientos de la fecha histórica
  */
	FechaHistorica(int fecha, int num_aconts);

/**
  * @brief Destructor de la clase
  */
	~FechaHistorica();

/**
  * @brief Añade un acontecimiento 
  * @param suceso Suceso a añadir
  * @param pos_suceso Posición del suceso en el vector de acontecimientos
  * @pre pos_suceso debe ser mayor o igual que 0
  */
	void Aniadir_Acontecimiento(string suceso, int pos_suceso);

/**
  * @brief Año
  * @return Devuelve el año de la fecha histórica
  */
	int Get_Anio();

/**
  * @brief Número de acontecimientos
  * @return Devuelve el número de acontecimientos de una fecha histórica
  */
	int Get_Num_Aconts();

/**
  * @brief Acontecimiento
  * @param indice Índice del acontecimiento en el vector
  * @pre indice debe ser mayor o igual que 0
  * @return Devuelve un acontecimiento
  */
	string Get_Puntero_Acont(int indice);

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
};

#endif