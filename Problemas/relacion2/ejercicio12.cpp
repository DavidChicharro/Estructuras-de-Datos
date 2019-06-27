/*	12. Implementa una cola con prioridad de un tipo struct con 
	(apellidos, nombre, prioridad) de forma que los datos salgan
	de acuerdo a ese tercer campo prioridad						*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Persona{
	string apellidos;
	string nombre;
	int prioridad;

	bool operator<(const Persona &p) const {
        return prioridad < p.prioridad;
    }
};

ostream& operator<< (ostream& os, const Persona &p){
	os << p.apellidos << " " << p.nombre << " " << p.prioridad << endl;
	return os;
}

int main(){
	priority_queue<Persona, vector<Persona>, less<Persona> > cola;

	Persona p1 = {"Martinez Moreno","Antonio",6};
	Persona p2 = {"Fernandez Soto","Carmen", 3};
	Persona p3 = {"Arredondo Garcia","Sonia",1};
	Persona p4 = {"Chamorro Colono","David", 5};
	Persona p5 = {"Alvarez Montes","Manuel",2};

	cola.push(p1);
	cola.push(p2);
	cola.push(p3);
	cola.push(p4);
	cola.push(p5);	

	while(!cola.empty()){
		cout << cola.top() << endl;
		cola.pop();
	}
	cout << endl;
	
	return 0;
}