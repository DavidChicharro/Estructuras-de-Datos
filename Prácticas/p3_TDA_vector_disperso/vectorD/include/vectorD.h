/**
  * @file vectorD.h
  * @brief Fichero cabecera del TDA Vector Disperso
  *
  */

#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <list>     // tipo list STL
#include <utility>  // clase pair

using namespace std;

/**
  * @brief T.D.A. Vector Disperso
  * Una instancia @e vd del tipo de datos abstracto @c VectorD es un objeto
  * que contiene un vector disperso en el que la mayoría de valores se corresponden con un valor nulo.
  * Cada objeto posee una lista de pares indicando la posición en el vector 
  * y el valor que almacena, así como el número de elementos totales.
  *
  * @author David Carrasco Chicharro
  * @date Noviembre 2017
  *
  */

template <typename  T >
class vectorD{
public:
  class stored_iterator;        /** <iterador sobre elementos no nulos */
  class iterator;               /** <iterador sobre todos los elementos del vector */

  typedef unsigned int size_type;
  
/**
  * @brief Constructor por defecto de la clase.
  * @param t hace referencia al valor por defecto del vector
  * Crea un vector disperso sin elementos
  */  		
  vectorD<T>( const  T  & t=  T () );
  
/**
  * @brief Constructor de copia de la clase.
  * @param b vector que será copiado
  */
  vectorD<T>(  const vectorD< T > & b);    	

/**
  * @brief Constructor que crea un vectorD con numcomp componentes, todas ellas iguales a t
  * @param numcomp número de componentes del vector
  * @param t valor por defecto del vector disperso
  * @pre numcomp debe ser mayor que cero.
  */
  vectorD<T>( int numcomp, const  T  & t =  T () );

/**
  * @brief Destructor de la clase
  */	
  ~vectorD();

/**
  * @brief Número de elementos
  * @return Devuelve el tamaño del vectorD
  */
  size_type size() const;

/**
  * @brief Valor por defecto
  * @return Devuelve el valor por defecto vectorD
  */
  T  default_value( ) const;

/**
  * @brief Informa sobre si el vector está vacío
  * @return Devuelve true si el número de elementos es cero y false en caso contrario
  */
  bool empty();

/**
  * @brief Asigna el valor t a una posicion concreta del vector
  * @param p posición del valor en el vector disperso
  * @param t valor por defecto del vector disperso
  * @pre p debe ser mayor o igual que 0 y menor que n_ele
  * @post No se modifica el size del vector
  */
  void set(int p, const  T  & t);

/**
  * @brief Añade un nuevo elemento al final del vector y aumenta en uno el tamaño
  * @param t valor a añadir en el vector disperso
  * @pre t debe ser distinto al valor nulo
  */
  void push_back( const  T  & t);

/**
  * @brief Elimina un elemento del final del vector y disminuye en uno el tamaño
  */
  void pop_back();

/**
  * @brief elimina todos los elementos del vectorD.
  * @post Tamaño es 0
  */
  void clear();

/**
  * @brief Cambia el tamaño del vector a "s" elementos.
  * Si s es menor que el tamaño actual, elimina los restantes.
  * Si es mayor, aumenta la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 
  * @param s es el nuevo número de elementos del vector disperso
  */
  void resize(int s);
 
/**
  * @brief Operador de asignación
  * @param x vectorD que se va a asignar a la clase
  * @return devuelve la clase
  */
  vectorD<T> & operator= (const vectorD<T> & x);

/**
  * @brief Da una referencia constante a la componente c-esima del vectorD.
  * @param c componente del vector a la que se desea acceder
  * @pre c debe ser mayor o igual que cero y menor que el número de componenetes
  * @return Devuelve la componente referenciada
  */
  const  T  & operator[](unsigned c) const;

/**
  * @brief Operador de igualdad
  * @param x objeto de vectorD que se quiere comparar
  * @return Devuelve verdadero si tienen los mismos elementos y false en caso contrario
  */
  bool operator==( const vectorD<T> & x);

/**
  * @brief Operador de desigualdad
  * @param x objeto de vectorD que se quiere comparar
  * @return Devuelve verdadero si no tienen los mismos elementos y false en caso contrario
  */
  bool operator!=( const vectorD<T> & x);


  /////////////////iteradores///////////////////////

/**
  * @brief Iterador al inicio sobre todos los elementos del vector
  * @return Devuelve el iterador
  */
  iterator begin();

/**
  * @brief Iterador al final (siguiente al ultimo) sobre todos los elementos del vector
  * @return Devuelve el iterador
  */
  iterator end();

/**
  * @brief Iterador al inicio sobre elementos no nulos
  * @return Devuelve el iterador
  */
  stored_iterator sbegin() const;

/**
  * @brief Iterador al final (siguiente al ultimo) sobre telementos no nulos
  * @return Devuelve el iterador
  */
  stored_iterator send() const;


private:
/**
  * @page repConjunto Rep del TDA VectorD
  *
  * @section invConjunto Invariante de representación
  * Dado un vectorD V (vd,n_ele,v_nulo) se satisface que: \n
  * 0 <= vd.size() < n_ele; \n
  * vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1;c\n
  * vd[i].first >=0, para todo i = 0, ..., vd.size()-1; \n
  * vd[i].first < vd[j].first si i<j
  * 
  * @section faConjunto Función de abstracción
  * 
  * Un objeto válido @e rep del TDA VectorD representa: (vd,n_ele,v_nulo) con: \n
  * vd=[ (a,v1), (b,v2), ..., (n,vn) ] \n
  * n_ele = M \n
  * v_nulo = t \n
  * tal que M[pos] \n
  * pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1  \n
  * val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
  *
  */

  list< pair<int, T > > vd;     /**< Lista que aloja el vector disperso (solo los distintos al valor nulo) */
  size_type n_ele;              /**< Número de elementos totales */
  T   v_nulo;                   /**< Valor nulo del vector */


/**
  * @brief Comprueba el IR y el tipo de fallo en caso de haberlo según indica el éste.
  * @return Devuelve el tipo de fallo
  */
  int checkRepFails();
  
/**
  * @brief Copia un objeto de vectorD en la clase
  * @param x objeto de la clase vectorD a copiar
  */
  void copy(const vectorD<T> & x);

/**
  * @brief Comprueba la igualdad entre dos vectores dispersos
  * @param x objeto de vectorD que se quiere comparar
  * @return Devuelve true si tienen los mismos elementos y false en caso contrario
  */
  bool equals( const vectorD<T> & x);


/* ITERADORES SOBRE VECTOR DISPERSO */
public:
  class stored_iterator{
    public:
      friend class vectorD<T>;
      
  /**
    * @brief Constructor por defecto de la clase.
    */
      stored_iterator();

  /**
    * @brief Constructor de copia de la clase.
    * @param d iterador que será copiado
    */      
      stored_iterator(const stored_iterator & d);

  /**
    * @brief Operador de acceso a la componente del vector
    * @return Devuelve el par del vector apuntado
    */
      const pair<int, T > & operator *( );

  /**
    * @brief Operador ++ prefijo
    * @return Devuelve la clase
    */
      stored_iterator & operator++( );

/**
    * @brief Operador ++ posfijo
    * @return Devuelve la clase
    */
      stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}

  /**
    * @brief Operador ++ prefijo
    * @return Devuelve la clase
    */
      stored_iterator & operator--( );

  /**
    * @brief Operador ++ posfijo
    * @return Devuelve la clase
    */
      stored_iterator operator--(int ) {stored_iterator tmp(*this); --ite; return tmp;}

  /**
    * @brief Operador de igualdad
    * @param d objeto de iterator que se quiere comparar
    * @return Devuelve true si tienen los mismos elementos y false en caso contrario
    */
      bool operator == (const stored_iterator & d);

  /**
    * @brief Operador de desigualdad
    * @param d objeto de iterator que se quiere comparar
    * @return Devuelve true si no tienen los mismos elementos y false en caso contrario
    */
      bool operator != (const stored_iterator & d);
    
    private:
      typename list<pair<int, T > >::const_iterator ite;  /**< iterador a la lista */
  };

  class iterator{
  public:
    friend class vectorD<T>;

  /**
    * @brief Constructor por defecto de la clase.
    * Inicializa a cero el índice del vector
    */
    iterator();

  /**
    * @brief Constructor de copia de la clase.
    * @param d iterador que será copiado
    */
    iterator(const iterator & d);

  /**
    * @brief Operador de acceso al valor de la componente del vector
    * @return Devuelve el valor de la componente apuntada
    */
    const  T  & operator *(  );

  /**
    * @brief Operador ++ prefijo
    * @return Devuelve la clase
    */
    iterator & operator++( );

  /**
    * @brief Operador ++ posfijo
    * @return Devuelve la clase
    */
    iterator operator++(int ){  
      iterator tmp(*this);
      if( i_vect == (*ite_rep).first)
        ++ite_rep;      
      i_vect++;

      return tmp;
    }

  /**
    * @brief Operador de igualdad
    * @param d objeto de iterator que se quiere comparar
    * @return Devuelve true si tienen los mismos elementos y false en caso contrario
    */
    bool operator == (const iterator & d);

  /**
    * @brief Operador de desigualdad
    * @param d objeto de iterator que se quiere comparar
    * @return Devuelve true si no tienen los mismos elementos y false en caso contrario
    */
    bool operator != (const iterator & d);

  /**
    * @brief Operador de asignación
    * @param d objeto de iterator que se va a asignar a la clase
    * @return Devuelve la clase
    */
    iterator & operator=(const iterator & d);

  private:
  /**
   * @page repConjunto Rep del Iterator
   *
   * @section invConjunto Invariante de representación
   * 
   * (i_vect, ite_rep):
   * 0 <= i_vect <=n_ele
   * i_vect <= (*ite_rep).first
   *
   * @section faConjunto Función de abstracción
   * Iterador sobre el vector abstracto
   * (i_vect, ite_rep, el_vec):
   * i_vect = k
   * ite_rep = p 
   * el_vect = v
   * 
   * iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
   *
   */

    int i_vect; /**< índice sobre el vector abstracto */
    typename list<pair<int, T > >::iterator ite_rep;  /**< iterador a la representación */
    vectorD<T> *el_vect;  /**< puntero al vector para obtener el valor nulo del éste */
    
    /**
    * @brief Copia un objeto de iterator en la clase
    * @param d objeto de la clase iterator a copiar
    */
    void copy_it(const iterator & d);  
  };
};

#include "vectorD.hxx"

#endif
