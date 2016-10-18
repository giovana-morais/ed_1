/*
 * Implementacao de Fila Circular
 */

#include"fila.h"
#include <stdio.h>

/* Inicializa uma Fila */
void inicFila(Fila *p_l){
	p_l->head = 0;
	p_l->tail = -1;
	p_l->tam  = 0;
}

/* Verifica se a Fila está vazia ou nao */
int filaVazia(Fila *p_l){
	if(p_l->tam == 0)
	{
		return 1;
	}
	return 0;
}

/* Verifica se a Fila está cheia ou nao */
int filaCheia(Fila *p_l){
	if(p_l->tam == MAX)
	{
		return 1;
	}
	return 0;
}

/* Insere um elemento na Fila */
void insereFila(Fila *p_l, elem_t e){
	p_l->tail = (p_l->tail + 1) % MAX;
	p_l->info[p_l->tail] = e;	
	p_l->tam++;
}

/* Remove um elemento da Fila */
elem_t removeFila(Fila *p_l){
	elem_t ret;

	ret = p_l->info[p_l->head];
	p_l->head = (p_l->head + 1) % MAX;
	p_l->tam--;
	return ret;
}

/* Remove todos os numeros da Fila */
void libera(Fila *p_l){
	inicFila(p_l);
}

/* Insere um elemento no inicio da Fila em O(1) */
void furaFila(Fila *p_l, elem_t e){
	if(!filaCheia(p_l))
	{
		p_l->head = (p_l->head - 1) % MAX;
		p_l->info[p_l->head] = e;
		p_l->tam++;
	}
}
