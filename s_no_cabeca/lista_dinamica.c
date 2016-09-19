#include<stdlib.h>
#include<stdio.h>
#include"lista_dinamica.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l)
{
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l)
{
	if(*p_l == NULL) return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;
		
	novo_no->prox = *p_l;
	*p_l = novo_no;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo, *aux;
	
	if(listaVazia(p_l))
		insereInicio(p_l, e);
	else {
		novo = malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = NULL;
		
		aux = *p_l;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}

}



/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */ 

void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo, *aux;

//	if(!ordenada(p_l))
	//	ordena(p_l);


	aux = *p_l;

	if(listaVazia(p_l) || e < aux->info)
		insereInicio(p_l, e);
	else {
		novo = (No_lista *) malloc(sizeof(No_lista));
		novo->info = e;
		while(aux->prox != NULL){
			if(e < aux->prox->info){
				novo->prox = aux->prox;
				aux->prox = novo;
				return;
			}
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->prox = NULL;
	}
}

/* Verifica se a lista esta ordenada */ 
int ordenada(Lista *p_l){

	No_lista *aux;

	aux = *p_l;

	if(listaVazia(p_l))
		return 1;
	
	while(aux->prox != NULL){
		if(aux->info > aux->prox->info)
			return 0;
		aux = aux->prox;
	}	

	return 1;
}

/* Ordena a lista 
void ordena(Lista *p_l){
	No_lista *desord, *aux, *novo;
	
	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;
		aux = p_l;
		
		while (aux->prox != NULL && aux->prox->info < novo->info){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}
*/
/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */ 
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if(listaVazia(p_l))
		return 0;
	// aux recebe a primeira struct da lista
	aux = *p_l;
	// p_l passa a apontar pra aux->prox;
	*p_l = aux->prox;
	*p_e = aux->info;
	// libera a memória 
	free(aux);
	
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia*/ 
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;

	if (listaVazia(p_l))
		return 0;
	aux = *p_l;
	//while(aux->prox)...... //terminar	
//	while (p_l->prox->prox != NULL)
	while ((*(*p_l).prox).prox != NULL)
		p_l = p_l->prox;
		
	aux = p_l->prox;
	
	
//	aux = p_l->prox;
//	while(aux->prox != NULL){
//		p_l = aux;
//		aux = aux->prox;
//	}
//	
	
	p_l->prox = aux->prox;
	*p_e = aux->info;
	free(aux);

	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado 
int removeValor(Lista *p_l, elem_t e){
	No_lista *aux;
	int removeu = 0;
	
	if (listaVazia(p_l))
		return 0;

	aux = p_l->prox;
	while(aux != NULL){
		if (aux->info == e){
			p_l->prox = aux->prox;
			free(aux);
			removeu = 1;	
			aux = p_l->prox;
		}	
		else {
			p_l = p_l->prox;
			aux = p_l->prox;
		}
	}	
	
	return removeu; 
}
*/
/* Inverte os elementos de uma lista 
void inverte(Lista *p_l){
	No_lista *desord, *novo;
	
	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;
		
		novo->prox = p_l->prox;
		p_l->prox = novo;
	}
	
}
*/
/* Remove todos os numeros da lista 
void libera(Lista *p_l){
	No_lista *aux;
	
	while (p_l->prox != NULL){
		aux = p_l->prox;
		p_l->prox = aux->prox;
		free (aux);
	}
}
*/
/* Exibe o conteudo da lista */ 
void exibe(Lista *p_l){
	No_lista *aux;

	aux = *p_l;

	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");

	/* usando o p_l pra andar na lista
	while(*p_l!= NULL){
		printf("%d ", (*p_l)->prox->info);
		p_l = &(*p_l)->prox;
	}
	*/
}

 
