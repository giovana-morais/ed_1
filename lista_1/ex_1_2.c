#include <stdio.h>
#include <time.h>
#include "lista_cno.h"

/*
* 	- gerar N números aleatórios 
*	- armazenar em uma lista
*	- imprimir normal
*	- imprimir reverso
*	- imprimir ordenado
*	- imprimir média duas casas decimais
*/ 

int main(){
	int N;
	Lista lista;
	inicLista(&lista);
	scanf("%d", &N);


	geraListaAleatoria(N, &lista);
	exibe(&lista);
	printf("\n");

	inverte(&lista);
	exibe(&lista);
	printf("\n");

	ordena(&lista);
	exibe(&lista);
	printf("\n");
	
	printf("%.2f", calculaMedia(&lista));
	printf("\n");	

}
