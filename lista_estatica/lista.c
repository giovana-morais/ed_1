#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicia(vet *v){
	v->tam = 0;
}

int insereIni(vet *v, elem_t n){
	int i;
	if(cheio(*v)){
		return 0;	
	}
	for(i = v->tam - 1; i >= 0; i--){
		v->item[i+1] = v->item[i];
	}	
	v->item[0] = n;
	v->tam++;

	return 1;
}

int retiraIni(vet *v, elem_t *elemRemovido){
	int i;
	if(vazio(*v)){
		return 0;
	}

	*elemRemovido = v->item[0];

	for(i = 0; i < v->tam - 1; i++){
		v->item[i] = v->item[i+1];
	}
	v->tam--;

	return 1;
}

int insere(vet *v, elem_t n){
	if(cheio(*v))
		return 0;
	v->item[v->tam] = n;
	v->tam++;
	// dá pra fazer isso também:
	// v->item[v->tam++] = n;
	return 1;
}

int retira(vet *v, elem_t *elemRemovido){
	if(vazio(*v))
		return 0;
	*elemRemovido = v->item[v->tam-1];
	v->tam--;
	return 1;
}

int verRepeticao(vet v, elem_t n){
	int qtd_n, i;
	qtd_n = 0;
	for(i = 0; i < v.tam; i++){
		if(v.item[i] == n){
			qtd_n++;
		}
	}

	return qtd_n;
}

int cheio(vet v){
	if(v.tam == MAX)
		return 1;
	return 0;
}

int vazio(vet v){
	if(v.tam == 0)
		return 1;
	return 0;
}

elem_t acessa(vet v, int ind){
	return v.item[ind];	
}

int tamanho(vet v){
	return v.tam;
}
