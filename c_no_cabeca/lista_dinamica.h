#ifndef LISTAD_H
#define LISTAD_H

typedef int elem_t;

typedef struct no{
	   elem_t info;
	     struct no *prox;
} No_lista;

typedef No_lista Lista;

/* Inicializa uma lista */
void inicLista(Lista *p_l);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l);

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e);

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e);

/* Insere um elemento na lista de maneira ordenada.
 *    Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e);

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l);

/* Ordena a lista */
void ordena(Lista *p_l);

/* Remove o elemento que esta no inicio da lista.
 *    Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e);

/* Remove o elemento que esta no final da lista.
 *    Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e);

/* Remove todas as ocorrências de valor e.
 *    Retorna 0 caso este numero não tenha sido encontrado */
int removeTodoValor(Lista *p_l, elem_t e);

/* Remove a única ocorrência do valor e;
 * 	Retorna 0 caso este número não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e);

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l);

/* Acha o maior valor presente na lista */
void acha_max(Lista *p_l, int *maximo);
#endif
