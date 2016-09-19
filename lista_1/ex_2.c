/* 
 * entrada: 
 * 	o primeiro inteiro é a qtd de número das listas e o resto é a lista
 * saída:
 * 	uma lista com todos os números da outra lista, mas ordenado
 *
 * 2.1 - fazer isso sem alterar ambas as listas
 * 2.2 - fazer isso mesclando as duas listas, mas sem usar malloc
 *
 */

#include <stdio.h>
#include "lista_cno.h"

int main(){
	Lista lista_1, lista_2, nova_lista;

	inicLista(&lista_1);	
	inicLista(&lista_2);	
	inicLista(&nova_lista);
	
	leLista(&lista_1);
	leLista(&lista_2);
/*
	printf("lista 1: ");
	exibe(&lista_1);
	printf("\n");
	printf("lista 2: ");
	exibe(&lista_2);
	printf("\n");
*/
	criarListaMesclada(&lista_1, &lista_2, &nova_lista);
	printf("nova lista (com malloc): ");
	exibe(&nova_lista);
	printf("\n");
	printf("nova lista (sem malloc): ");
	
	
	mesclaListas(&lista_1, &lista_2);
	exibe(&lista_1);
	printf("\n");
return 0;
}
