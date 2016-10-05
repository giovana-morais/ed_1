/* implementar essas fç
 * 	 - concatenar
 * 	 - dividir uma lista em duas e retornar o ponteiro da segunda parte
 * 	 	essa fç recebe como parâmetro um número. tem que dividir a lista a partir desse número
 * 	 - transformar uma lista normal em circular
 * 	 - criar uma lista encadeada a partir de um vetor e seu tamanho
 * 	 - não entendi o item 5.5
 * 	 - mesclar duas listas, mantendo sua originalidade. tbm criar um vetor com os elementos.
 */

#include "lista_sno.h"
#include <stdio.h>
int main(){
	
	Lista lista_1, lista_2, teste;
	int i, v[5];

	inicLista(&lista_1);
	inicLista(&lista_2);

	for(i =  0; i < 5; i++){
		insereInicio(&lista_1, i);
		insereFim(&lista_2, 3*i);
	}

	concatena(&lista_1, &lista_2);
	exibe(&lista_1);
/*
	teste = divide(&lista_1, 3);
	exibe(&teste);

	teste = divide(&lista_1, 6);
	exibe(&teste);
*/
//	transformaCircular(&lista_1);
//	exibe(&lista_1);
	
	for(i = 0; i < 5; i++)
		v[i] = (i*20) % 7;
	printf("vetor: ");
	for(i = 0; i < 5; i++)
		printf("%d ", v[i]);
	printf("\n");

	teste = criaLista(v, 5);
	exibe(&teste);
		
}
