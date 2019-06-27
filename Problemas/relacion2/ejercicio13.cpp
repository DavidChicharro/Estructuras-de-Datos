/*	13. Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de
	caracteres que tengan mas vocales y que en caso de igualdad salgan por orden alfabético			*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int contar_vocales(string cad){
	int num_vocales = 0;

	for (unsigned i=0 ; i<cad.size() ; i++)
		switch (cad[i]){
			case 'a': num_vocales++; break;
			case 'e': num_vocales++; break;
			case 'i': num_vocales++; break;
			case 'o': num_vocales++; break;
			case 'u': num_vocales++; break;
			default: break;
		}

	return num_vocales;
}

class comp{
private:
	// compara dos cadenas con el mismo numero de vocales
	bool orden_alfabetico(string a, string b){
		int cad_mas_corta = a.size()<b.size() ? a.size():b.size();
		
		for (int i=0 ; i<cad_mas_corta ; i++){
			if (a[i] != b[i])
				return a[i] > b[i];					// compara letra a letra para comprobar el orden alfabético
		}

		/* si dos cadenas con mismo numero de vocales 
		   son iguales hasta el fin de la más corta, 
		   tendrá mayor prioridad la más escueta	*/
		return a.size()>b.size();
	}

public:
	bool operator()(string a, string b){
		if (contar_vocales(a) != contar_vocales(b))
			return contar_vocales(a) < contar_vocales(b); 	// tendrá mayor prioridad aquella con más vocales
		else
			return orden_alfabetico(a, b);
	}
};

int main(){
	priority_queue <string, vector<string>, comp> pq;
	string v[] = {"Esta cadena tiene x caracteres", "Esta cadena tiene y caracteres",
	 "Esta cadena iria la primera de todas por tener mas vocales", "Esta es la mas corta"};

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