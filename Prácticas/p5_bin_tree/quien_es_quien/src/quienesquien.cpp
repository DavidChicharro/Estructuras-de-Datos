#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <ctype.h>
#include <algorithm>

void QuienEsQuien::copia(const QuienEsQuien &quienEsQuien){
	this->personajes = quienEsQuien.personajes;
	this->atributos = quienEsQuien.atributos;
	this->tablero = quienEsQuien.tablero;
	this->arbol = quienEsQuien.arbol;
	this->jugada_actual = quienEsQuien.jugada_actual;
}

QuienEsQuien::QuienEsQuien(){
	std::vector<string> personajes;
	std::vector<string> atributos;
	std::vector<std::vector<bool> > tablero;
	bintree<Pregunta> arbol;
	bintree<Pregunta>::node jugada_actual;
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	this->limpiar();
	this->copia(quienEsQuien);
}
QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	this->limpiar();
	this->copia(quienEsQuien);
	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	this->personajes.clear();
	this->atributos.clear();
	this->tablero.clear();
	this->arbol.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada línea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un número a un vector de bool que corresponde 
  *        con su representación en binario con un numero de digitos
  *        fijo.
  *
  * @param n Número a convertir en binario.
  * @param digitos Número de dígitos de la representación binaria.
  *
  * @return Vector de booleanos con la representación en binario de @e n 
  *      con el número de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

typename bintree<Pregunta>::node QuienEsQuien::crear_arbol_recursivo(bintree<Pregunta> &arb, typename bintree<Pregunta>::node nodo, 
	set<int> col_visit, set<int> filas_no_visit, int tipo_hijo, int n_pers, bool primera_pregunta)
{
	int num_personajes,
			num_ceros_mayor = 0, num_unos_mayor = 0;
	double 	entropia, entropia_cero, entropia_uno,
					entropia_0, entropia_1, ganancia,
					mayor_ganancia = 0;
	int indice_mayor_ganancia = -1;
	set<int> filas_no_visit_0 = filas_no_visit,		// Conjunto de filas por las que no se va a iterar
					 filas_no_visit_1 = filas_no_visit;

	if(!primera_pregunta)
		num_personajes = n_pers;
	else
		num_personajes = personajes.size();

	Pregunta pregunta(num_personajes);
	entropia = log(pregunta.obtener_num_personajes())/log(2);
	
	for(int i=0 ; i<atributos.size() ; i++){
		double num_ceros = 0, num_unos = 0;
		bool visitar_col = col_visit.find(i) != col_visit.end();
		for(int j=0 ; j<personajes.size() && !visitar_col ; j++)
			if(filas_no_visit.find(j) == filas_no_visit.end()){
				if(tablero[j][i] == false)
					num_ceros++;
				else
					num_unos++;
			}

		if(!visitar_col){
			assert(num_personajes == (num_ceros + num_unos));
			entropia_cero = -(num_ceros/num_personajes)*(log(num_ceros/num_personajes)/log(2));
			entropia_uno  = -(num_unos/num_personajes)*(log(num_unos/num_personajes)/log(2));
			ganancia = (num_ceros/num_personajes)*entropia_cero + (num_unos/num_personajes)*entropia_uno;

			if(ganancia > mayor_ganancia){
				mayor_ganancia = ganancia;
				entropia_0 = entropia_cero;
				entropia_1 = entropia_uno;
				indice_mayor_ganancia = i;
				num_ceros_mayor = num_ceros;
				num_unos_mayor = num_unos;
			}
		}
	}
	col_visit.insert(indice_mayor_ganancia);				// Conjunto de columnas por las que no se vuelve a iterar

	for(int i=0 ; i<personajes.size() ; i++)
		if(filas_no_visit.find(i) == filas_no_visit.end()){
			if(tablero[i][indice_mayor_ganancia] == false)
				filas_no_visit_1.insert(i);
			else
				filas_no_visit_0.insert(i);
		}

	pregunta.set_atributo(atributos[indice_mayor_ganancia]);
	if(!primera_pregunta){
		if(tipo_hijo == 1){
			arb.insert_left(nodo, pregunta);
			nodo = nodo.left();
		}
		else{
			arb.insert_right(nodo, pregunta);
			nodo = nodo.right();
		}		
	}
	else
		nodo = pregunta;


	if(entropia_1 != (entropia/num_personajes))
		crear_arbol_recursivo(arb, nodo, col_visit, filas_no_visit_1, 1, num_unos_mayor, false);
	else{		// es un personaje
		string nombre_pers;
		for(int i=0 ; i<personajes.size() ; i++)
			if(filas_no_visit_1.find(i) == filas_no_visit_1.end())
				nombre_pers = personajes[i];

		Pregunta pregunta(nombre_pers, 1);
		arb.insert_left(nodo, pregunta);
	}
	if(entropia_0 != (entropia/num_personajes))
		crear_arbol_recursivo(arb, nodo, col_visit, filas_no_visit_0, 0, num_ceros_mayor, false);
	else{
		string nombre_pers;
		for(int i=0 ; i<personajes.size() ; i++)
			if(filas_no_visit_0.find(i) == filas_no_visit_0.end())
				nombre_pers = personajes[i];

		Pregunta pregunta(nombre_pers, 1);
		arb.insert_right(nodo, pregunta);
	}

	while(!nodo.parent().null())
		nodo = nodo.parent();

	return nodo;
}


bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	bintree<Pregunta> arb;
	bintree<Pregunta>::node nodo = arb.root();

	set<int> col_visit;
	set<int> filas_no_visit;

	typename bintree<Pregunta>::node n = crear_arbol_recursivo(arb, arb.root(), col_visit, filas_no_visit , -1, 0, true);

	bintree<Pregunta> A;
	A.assign_subtree(arb, n);
	
	return A;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

bool respuesta_valida(char respuesta){
	respuesta = tolower(respuesta);

	return (respuesta == 's' || respuesta == 'n');
}

void QuienEsQuien::iniciar_juego(){
	char respuesta;
	bool repetir_juego;
	do{
		jugada_actual = arbol.root();

		cout << "\n¿Añadir nuevo personaje?" << endl;
		do{
			cout << "(s/n): ";
			cin >> respuesta;
		}while(!respuesta_valida(respuesta));

		if(respuesta == 's'){
			nuevo_personaje();
		}


		cout << "\n¿Eliminar personaje?" << endl;
		do{
			cout << "(s/n): ";
			cin >> respuesta;
		}while(!respuesta_valida(respuesta));

		if(respuesta == 's'){
			borrar_personaje();
		}


		while((*jugada_actual).es_pregunta()){
			set<string> personajes_levantados;			
			personajes_levantados = informacion_jugada(jugada_actual);
			set<string>::const_iterator it;

			cout << "--- Personajes levantados: ---" << endl;
			for(it = personajes_levantados.begin() ; it != personajes_levantados.end() ; ++it)
				cout << *it << endl;

			cout << "\nEl personaje oculto tiene las siguientes características: " << endl;
			stack<pair<string,string> > st = preguntas_formuladas(jugada_actual);
			while(!st.empty()){
				cout << st.top().first << "\t- " << st.top().second << endl;
				st.pop();
			}
			cout << "pero aún no sé cuál es." << endl;


			cout << "\n¿Es " << (*jugada_actual).obtener_pregunta() << " ?" << endl;
			do{
				cout << "(s/n): ";
				cin >> respuesta;
			}while(!respuesta_valida(respuesta));

			if(respuesta == 's')
				jugada_actual = jugada_actual.left();
			else
				jugada_actual = jugada_actual.right();
		}
		cout << "​¡Ya lo sé! Tu personaje es " << (*jugada_actual).obtener_personaje() << endl << endl;


		cout << "¿Repetir juego? ";
		do{
			cout << "(s/n): ";
			cin >> respuesta;
		}while(!respuesta_valida(respuesta));

		if(respuesta == 's')
			repetir_juego = true;
		else
			repetir_juego = false;
	}while(repetir_juego);
}

/**
  * @brief Recibe un nodo y éste pasa a ser el siguiente (en preorden)
*/
void siguiente_nodo(typename bintree<Pregunta>::node &v){
	if (!v.left().null())
    v = v.left();
  else if (!v.right().null())
      v = v.right();
  else {
    while ((!v.parent().null()) &&
	   (v.parent().right() == v 
	    || v.parent().right().null()))
         v = v.parent();
    if (v.parent().null())
      v = typename bintree<Pregunta>::node();
    else
      v = v.parent().right();
  }
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;
	bintree<Pregunta> A;
	A.assign_subtree(arbol, jugada_actual);

	for (typename bintree<Pregunta>::const_preorder_iterator it= A.begin_preorder(); it!=A.end_preorder(); ++it)
		if((*it).es_personaje())
			personajes_levantados.insert((*it).obtener_personaje());

	return personajes_levantados;
}

stack<pair<string, string> > QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada_actual){
	stack<pair<string, string> > st;
	string respuesta;

	while(!jugada_actual.parent().null()){
		if(jugada_actual.parent().left() == jugada_actual)
			respuesta = "sí";
		else
			respuesta = "no";

		jugada_actual = jugada_actual.parent();

		st.push(make_pair((*jugada_actual).obtener_pregunta(), respuesta));
	}

	return st;
}

void QuienEsQuien::nuevo_personaje(){
	string nombre;
	int valor;
	vector<bool> caracteristicas;

	cout << "Introduce el nombre del nuevo personaje: ";
	cin >> nombre;
	cout << "Indica sus características (sí=1 / no=0): " << endl;
	cin >> valor;
	for(int i=0 ; i<atributos.size()-1 ; i++){
		if(valor == 0)
			caracteristicas.push_back(false);
		else if(valor == 1)
			caracteristicas.push_back(true);

		cin >> valor;
	}
	aniade_personaje(nombre, caracteristicas);
}

void QuienEsQuien::aniade_personaje (string nombre, vector <bool> caracteristicas){
	string nombre_personaje, nueva_pregunta;
	typename bintree<Pregunta>::node n = arbol.root();

	while((*n).es_pregunta()){
		int pos_pregunta;
		bool continuar = true;
		string nombre_pregunta = (*n).obtener_pregunta();

		for(int i=0 ; i<atributos.size() && continuar ; i++)
			if(nombre_pregunta == atributos.at(i)){
				pos_pregunta = i;
				continuar = false;
			}
		
		if(caracteristicas.at(pos_pregunta) == true)
			n = n.left();
		else
			n = n.right();
	}

	assert((*n).es_personaje());
	nombre_personaje = (*n).obtener_personaje();

	cout << "Introduce una nueva pregunta cuya respuesta sea afirmativa para " <<
				nombre_personaje << " y negativa para " << nombre << ": ";
	cin.ignore();
	getline(cin, nueva_pregunta);
	Pregunta 	pregunta(nueva_pregunta, 2),
						personaje_izq(nombre_personaje, 1),
						personaje_dcho(nombre, 1);
	bintree<Pregunta> aux(pregunta);
	aux.insert_left(aux.root(), personaje_izq);
	aux.insert_right(aux.root(), personaje_dcho);

	bintree<Pregunta> nulo;
	bintree<Pregunta>::node padre = n.parent();
	if(n == padre.left()){
		arbol.prune_left(padre.left(), nulo);
		arbol.insert_left(padre, aux);
	}
	else{
		arbol.prune_right(padre.right(), nulo);
		arbol.insert_right(padre, aux);
	}
}

void QuienEsQuien::borrar_personaje(){
	string nombre;
	int indice;
	bool existe_personaje = false;

	cout << "Introduce el nombre del personaje que deseas eliminar: ";
	cin.ignore();
	getline(cin, nombre);

	for(int i=0 ; i<personajes.size() && !existe_personaje ; i++)
		if(nombre == personajes.at(i)){
			indice = i;
			existe_personaje = true;
		}

	if(existe_personaje){
		vector<bool> caracteristicas;

		for(int i=0 ; i<atributos.size() ; i++)				
			caracteristicas.push_back(tablero[indice][i]);

		elimina_personaje(caracteristicas);
	}
	else
		cerr << "No existe el personaje que deseas eliminar." << endl;
}

void QuienEsQuien::elimina_personaje (vector <bool> caracteristicas){
	typename bintree<Pregunta>::node n = arbol.root();

	while((*n).es_pregunta()){
		string nombre_pregunta = (*n).obtener_pregunta();
		int pos_pregunta;
		bool continuar = true;
		for(int j=0 ; j<atributos.size() && continuar ; j++)
			if(nombre_pregunta == atributos.at(j)){
				pos_pregunta = j;
				continuar = false;
			}
		
		if(caracteristicas.at(pos_pregunta) == true)
			n = n.left();
		else
			n = n.right();
	}
	
	bintree<Pregunta> sub_rama;
	if(n.parent().left() == n)
		arbol.prune_right(n.parent(), sub_rama);
	else
		arbol.prune_left(n.parent(), sub_rama);

	bintree<Pregunta>::node abuelo = n.parent().parent();
	if(n.parent() == abuelo.left())
		arbol.insert_left(abuelo, sub_rama);
	else
		arbol.insert_right(abuelo, sub_rama);
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a, 
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	// No es necesario este método, pues el árbol se crea directamente sin redundancias
}

/**
 * @brief Devuelve la profundidad de un nodo en el árbol donde se encuentra
**/
int profundidad_nodo(const typename bintree<Pregunta>::node &v) {
	int profundidad = 0;

	if(!v.parent().null()){
		typename bintree<Pregunta>::node aux = v.parent();

		while(!aux.null()){
			profundidad ++;
			aux = aux.parent();
		}
	}

	return profundidad;
}

float QuienEsQuien::profundidad_promedio_hojas(){
	int num_preguntas = 0;
	float prof_nodo = 0, prof_promedia;

	typename bintree<Pregunta>::node n = arbol.root();
	while(!n.null()){
		if((*n).es_pregunta()){
			prof_nodo += profundidad_nodo(n);
			num_preguntas++;
		}
		siguiente_nodo(n);
	}

	prof_promedia = (prof_nodo*1.0)/num_preguntas;

	return prof_promedia;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/
int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atr_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
