#include <stdio.h>
#include "lista_sno.h"

/*
 *
 * 	imprimir na ordem
 * 	imprimir invertido
 * 	imprimir ordenado
 * 	imprimir média
 *
 */

int main(){
	int N;
	Lista lista;

	inicLista(&lista);
	scanf("%d", &N);

	printf("lista:\n");	
	geraListaAleatoria(N, &lista);
	exibe(&lista);
	
	printf("lista inversa:\n");
	inverte(&lista);
	exibe(&lista);
	
	printf("lista ordenada:\n");
	ordena(&lista);
	exibe(&lista);

	printf("media:\n");
	printf("%.2f\n", calculaMedia(&lista));
	
return 0;
}
