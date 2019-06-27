/*	14. Implementa una cola con prioridad que contenga strings y de la que salgan primero las 
	cadenas de caracteres mas largas y que en caso de igualdad salgan por orden alfabético.	*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


class comp{
private:
	// compara dos cadenas con el mismo tamaño
	bool orden_alfabetico(string a, string b){	
		for (unsigned i=0 ; i<a.size() ; i++)
			if (a[i] != b[i])
				return a[i] > b[i];			// compara letra a letra para comprobar el orden alfabético
	}

public:
	bool operator()(string a, string b){
		if (a.size() != b.size())
			return a.size() < b.size(); 	// tendrá mayor prioridad aquella con más caracteres
		else
			return orden_alfabetico(a,b);
	}
};

int main(){
	priority_queue <string, vector<string>, comp> pq;
	string v[] = {"Esta cadena tiene x caracteres", "Esta cadena tiene y caracteres",
	 "Esta cadena iria la primera de todas por ser la mas larga", "Esta es la mas corta"};

	for (int i=0 ; i<4 ; i++){
		//string cad;
		//getline(cin, cad);
		pq.push(v[i]);
	}

	while(!pq.empty()){
		cout << pq.top() << endl; pq.pop();
	}
	cout << endl;

	return 0;
}