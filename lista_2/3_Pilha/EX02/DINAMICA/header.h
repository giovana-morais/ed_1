typedef int elem_t;

typedef struct no{
	int num;
	struct no *prox;
} No_pilha;

typedef No_pilha Pilha;

void inicPilha(Pilha *pilha);

void inic_pilha(Pilha *pilha);

void enqueue(Pilha *pilha, elem_t e);

elem_t dequeue(Pilha *pilha);

int PilhaVazia(Pilha *pilha);

int pop(Pilha *pilha);

void push(Pilha *pilha, elem_t e);

void libera(Pilha *pilha);
