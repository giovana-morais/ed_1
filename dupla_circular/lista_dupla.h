/*
 * Implementacao de lista dupla circular.
 */

#ifndef LISTAD_H
#define LISTAD_H

typedef int elem_t;

typedef struct no{
  elem_t info;
  struct no *prox;
  struct no *ant;
} No_lista;

typedef No_lista* Lista;

/* Inicializa uma lista */
void inicLista(Lista *p_l);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l);

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e);

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e);

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e);

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l);

/* Ordena a lista */
void ordena(Lista *p_l);

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e);

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e);

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e);

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l);

/* Retorna o endereço do nó do meio da lista */
No_lista* meio(Lista *p_l);

/* Intercala 2 listas */
No_lista* intercalaListas(Lista *l1, Lista *l2);

/* Intercala 2 listas ordenadas*/
No_lista* intercalaListasOrdenadas(Lista *l1, Lista *l2);
#endif
