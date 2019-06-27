/*	4. El recorrido en preorden de un determinado arbol binario es: GEAIBMCLDFKJH
y en inorden: IABEGLDCFMKHJ

Resolver:
a) Dibuja el arbol binario.
b) Da el recorrido en postorden.
c) Diseña una función para dar el recorrido en postorden dados los recorridos en preorden e inorden
(sin construir el árbol) y escribe un programa para comprobar el resultado del apartado anterior	*/

// pre: R-i-d
//  in: i-R-d
//post: i-d-R
/*	a)
               G
              / \ 
             /   \	
            /     \	
           /       \
          E         M
         /         / \
        /         /   \
       A         C     K
	    / \       / \     \
	   /   \     /   \     \
	  I	    B   L     F     J
     \                   /
      D                 H
*/

/*	b) Recorrido en postorden: IBAEDLFCHJKMG	*/

#include <iostream>
#include <cstring>
using namespace std;

void arb_postorden(char *preorden, char *inorden, char *postorden, int tam_preorden) {
  int tam_izq;

  if(tam_preorden != 0){
    postorden[tam_preorden-1] = preorden[0];
    tam_izq = strchr(inorden,preorden[0]) - inorden;
    arb_postorden (preorden+1, inorden, postorden, tam_izq);
    arb_postorden (preorden+1+tam_izq, inorden+1+tam_izq, postorden+tam_izq, tam_preorden-1-tam_izq);
  }
}

bool verificar_postorden(char *postorden_1, char *postorden_2){
	return strcmp(postorden_1,postorden_2) == 0;
}


int main(){
	char preorden[] = {'G','E','A','I','B','M','C','L','D','F','K','J','H'};
	char inorden[] = {'I','A','B','E','G','L','D','C','F','M','K','H','J'};
	char postorden[] = {'I','B','A','E','D','L','F','C','H','J','K','M','G'};	// Solución apartado b)
	char v[sizeof(preorden)];
	int tam_preorden = sizeof(preorden);

	arb_postorden(preorden, inorden, v, tam_preorden);

	cout << "postorden: " << endl;
	for(int i=0 ; i<sizeof(v) ; i++)
		cout << v[i] << " ";
	cout << endl;


	if(verificar_postorden(v, postorden))
		cout << "\nEl resultado es correcto" << endl;
	else
		cout << "\nEl resultado no es correcto" << endl;

	return 0;
}