typedef struct no{
	int num;
	struct no *prox;
} No_pilha;

typedef No_pilha Pilha;

void inic_pilha(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void empilha(Pilha *pilha, int num);

void imprime_original(Pilha *pilha);

int desempilha(Pilha *pilha);

void muda_ordem(Pilha *pilha, Pilha *aux);

void exibe(Pilha *pilha);

void separa(Pilha *pilha, Pilha *p1, Pilha *p2);

void junta(Pilha *pilha, Pilha *p1, Pilha *p2);
