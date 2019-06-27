///
///@file vector_dinamico.h
///@brief fichero de cabecera del TDA Vector_Dinamico
///
///Se crea un vector con capacidad de crecer y decrecer
///
#ifndef vectorDinamico_h
#define vectorDinamico_h
///
///@brief TDA Vector_Dinamico
///
///Una instancia @e v del tipo de dato abstracto
///@c Vector_Dinamico sobre el tipo @c float es un
///array 1-D de un determinado tamaño @e n que puede
///crecer y decrecer a petición del usuario.
///Podemos representarlo como:
///    {v[0], v[1],...,v[n-1]}
///donde v[i] es el valor asociado a la posición i del vector
///
///La eficiencia en espacio es de O(n)
///
///Un ejemplo de uso puede verse en
///@include ejemplo_vector_dinamico.cpp
///
class Vector_Dinamico{
private:
  ///
  ///@page repVector_Dinamico Rep del TDA Vector_Dinamico
  ///@section invVector_Dinamico Invariante de Representación
  ///
  ///Un objeto @e v del TDA Vector_Dinamico debe cumplir:
  ///
  ///-@c v.nelementos>=0
  ///
  ///-@c v.datos apunta a una zona de memoria con capacidad para
  ///albergar @c nelementos valores de tipo @c float
  ///
  ///@section faVector_Dinamico Función de Abstracción
  ///
  ///Un objeto válido @e rep del TDA Vector_Dinamico
  ///representa al vector de tamaño @e n
  ///
  ///  {v.datos[0], v.datos[1],..., v.datos[nelementos-1]}
  ///
  float * datos;   ///<Apunta a los elementos del vector
  int nelementos;  ///<Indica el número de elementos en @c datos
public:
  //Constructores
  ///
  ///@brief Constructor por defecto
  ///@param n indica el número de componentes inicial reservadas para el vector
  ///@note Este constructor también corresponde al
  ///constructor con parámetro
  Vector_Dinamico(int n=0);
  ///
  ///@brief Constructor de copia
  ///@param original es el vector del que se hace copia. No se modifica
  Vector_Dinamico(const Vector_Dinamico & original);
  //Destructor
  ///@brief Destructor
  ~Vector_Dinamico();
  //Otros métodos
  ///
  ///@brief Número de componentes del vector
  ///@return Devuelve el número de componentes que se puede almacenar
  ///en ese instante en el vector
  ///@see resize()
  int size() const;
  ///
  ///@brief Redimensión del vector
  ///@param n es el nuevo tamaño del vector. v>=0
  ///@post Los valores almacenados antes de la redimensión no se pierden
  ///(excepto los que se salgan del nuevo rango de índices)
  void resize( int n);
  ///
  ///@brief Acceso a un elemento del vector
  ///@param i es la posición del vector donde está el elemento. 0<=i<size()
  ///@return Devuelve la referencia al elemento. Por tanto, puede usarse
  ///para almacenar un valor en esa posición (lvalue)
  float & operator[](const int i);
  ///
  ///@brief Acceso a un elemento de un vector constante
  ///@param i es la posición del vector donde está el elemento. 0<=i<size()
  ///@return Devuelve la referencia al elemento. Se supone que el vector
  ///no se puede modificar y por tanto es acceso de sólo lectura
  const float & operator[](const int i) const;
  ///
  ///@brief Operador de asignación
  ///Sobrecargamos el operador para la clase Vector_Dinamico
  Vector_Dinamico & operator=(const Vector_Dinamico & original);
};
#endif /* vectorDinamico_h */
