/* 
 * crie uma fç que receba dois ponteiros para listas distintas e ordenadas e devolva um ponteiro para uma terceira lista gerada pela intersecção dos elementos dessas duas outras listas. não pode alocar nós pra isso. 
 *
 */
#include <stdio.h>
#include "lista_sno.h"

int main(){
	int i;
	Lista lista_1, lista_2;

	inicLista(&lista_1);
	inicLista(&lista_2);
	for(i = 0; i < 5; i++){
		insereFim(&lista_1, (i + 3));
	}
	printf("lista 1\n");	
	exibe(&lista_1);
	for(i = 0; i < 5; i++){
		insereFim(&lista_2, 3*i);
	}
	printf("lista 2\n");	
	exibe(&lista_2);
	interseccao(&lista_1, &lista_2);
}
