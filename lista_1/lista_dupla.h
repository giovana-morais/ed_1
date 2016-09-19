#ifndef LISTAD_H
#define LISTAD_H

typedef int elem_t;

typedef struct no{
	elem_t info;
	struct no *prox;
	struct no *ant;
} No_lista;

typedef No_lista *Lista;

/* Inicializa uma lista */
void inicLista(Lista *lista);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *lista);

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *lista, elem_t e);

/* Insere um elemento no final da lista */
void insereFim(Lista *lista, elem_t e);

/* Insere um elemento na lista de maneira ordenada.
 *    Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *lista, elem_t e);

/* Verifica se a lista esta ordenada */
int ordenada(Lista *lista);

/* Ordena a lista */
void ordena(Lista *lista);

/* Remove o elemento que esta no inicio da lista.
 *    Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *lista, elem_t *p_e);

/* Remove o elemento que esta no final da lista.
 *    Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *lista, elem_t *p_e);

/* Remove todas as ocorrências de valor e.
 *    Retorna 0 caso este numero não tenha sido encontrado */
int removeTodoValor(Lista *lista, elem_t e);

/* Remove a única ocorrência do valor e;
 * 	Retorna 0 caso este número não tenha sido encontrado */
int removeValor(Lista *lista, elem_t e);

/* Inverte os elementos de uma lista */
void inverte(Lista *lista);

/* Remove todos os numeros da lista */
void libera(Lista *lista);

/* Exibe o conteudo da lista */
void exibe(Lista *lista);

/* Acha o maior valor presente na lista */
void acha_max(Lista *lista, int *maximo);

/* Gera lista de números aleatórios */
void geraListaAleatoria(int N, Lista *lista);

/* Calcula a média de todos os elementos da lista */
float calculaMedia(Lista *lista);

/* Retorna uma terceira lista com a intersecção dos elementos entre as duas primeiras */
No_lista* interseccao(Lista *lista_1, Lista *lista_2);

#endif
