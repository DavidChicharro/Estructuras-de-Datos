/*	Ejercicio 20	*/

#include <iostream>
#include <map>

using namespace std;

int main(){
	float coord1, coord2;
	map< pair<float, float>, int> mapa;
	map< pair<float, float>, int>::iterator it;

	cout << "Introduce pares de coordenadas: ";
	cin >> coord1 >> coord2;
	while (!(coord1 == 0.0 && coord2 == 0.0)){
		pair<float,float> par = make_pair(coord1, coord2);

		
		it = mapa.find(par);
		if(it != mapa.end()){
			it->second++;
		}
		else{			
			mapa.insert(make_pair(par, 1));
		}

		cout << "Introduce pares de coordenadas: ";
		cin >> coord1 >> coord2;
	}


	for(it = mapa.begin() ; it != mapa.end() ; ++it){
		cout << "Par de coordenadas: " << (it->first).first << ", " << (it->first).second <<
					"  Numero de apariciones: " << it->second << endl;
	}

	return 0;
}