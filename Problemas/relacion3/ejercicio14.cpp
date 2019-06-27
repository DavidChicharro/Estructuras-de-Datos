/*	Ejercicio 14	*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
class vdisperso{
private:
	list< pair<int, T> > coefs;
	int n;

public:
	vdisperso(const vector<T> &v){
		n=v.size();
		for(int i=0 ; i<v.size() ; i++)
			if(v[i]!=0)
				coefs.push_back(make_pair(i,v[i]));		
	}

	void asignar_coeficiente(int i, const T &x){
		coefs.push_back(make_pair(i, x));
		if(i>n)
			n=i+1;
	}

	vector<T> convertir() const{
		vector<T> salida;
		list< pair<int, T> > aux = coefs;

		for(int i=0 ; i<n ; i++){
			if(aux.front().first == i){
				salida.push_back(aux.front().second);
				aux.pop_front();
			}
			else
				salida.push_back(0);
		}

		return salida;
	}

	void imprime(){
		typename list< pair<int, T> >::iterator it_l;
		for(it_l=coefs.begin() ; it_l != coefs.end() ; ++it_l)
			cout << "Posicion: " << it_l->first << "  Valor: " << it_l->second << endl;
	}
};

int main(){
	int myints[] = {1,0,0,0,2,0,0,0,1,0,0,0,0,0,5,0,0,0,0,0,8,0,0,0,0,0,0,3,0,0,0};
	vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

	vdisperso<int> vd(v);
	vd.imprime();

	vector<int> v_conv = vd.convertir();
	cout << "\nVector convertdo: " << endl;
	for(int i=0 ; i<v_conv.size() ; i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}
