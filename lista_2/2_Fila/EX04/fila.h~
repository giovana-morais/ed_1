/*
 * Implementacao de Fila Circular
 */

#ifndef FILA_H
#define FILA_H

#define MAX 10
typedef int elem_t;

typedef struct no{
  elem_t info[MAX];
  int head, tail, tam;
} Fila;

/* Inicializa uma Fila */
void inicFila(Fila *p_l);

/* Verifica se a Fila está vazia ou nao */
int filaVazia(Fila *p_l);

/* Verifica se a Fila está cheia ou nao */
int filaCheia(Fila *p_l);

/* Insere um elemento na Fila */
void insereFila(Fila *p_l, elem_t e);

/* Remove um elemento da Fila */
elem_t removeFila(Fila *p_l);

/* Remove todos os numeros da Fila */
void libera(Fila *p_l);

/* Insere um elemento no inicio da Fila em O(1) */
void furaFila(Fila *p_l, elem_t e);

#endif
