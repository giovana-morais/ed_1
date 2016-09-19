/* a fç recebe duas listas que representam polinômios e devolve a soma entre eles 
 * 	os nós tão em ordem crescente de expoente 
 */


#include "lista_sno.h"
#include <stdio.h>

int main(){

	Lista lista_1, lista_2, resultado;

	inicLista(&lista_1);
	inicLista(&lista_2);
	inicLista(&resultado);

	// polinômio 1: 3 + 2x + x^2
	insereFim(&lista_1, 3);
	insereFim(&lista_1, 2);
	insereFim(&lista_1, 1);

	
	// 1 + 5x + 7x^2 + 4x^3
	insereFim(&lista_2, 1);
	insereFim(&lista_2, 5);
	insereFim(&lista_2, 7);
	insereFim(&lista_2, 4);
	
	resultado = soma(&lista_1, &lista_2);
	exibe(&resultado);

	return 0;
}
