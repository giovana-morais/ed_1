typedef struct no{
	int num;
	struct no *prox;
} No_pilha;

typedef No_pilha Pilha;

void inic_pilha(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void empilha(Pilha *pilha, int num);

void gera_sequencia(Pilha *pilha, int N);

void desempilha(Pilha *pilha);

void imprime_original(Pilha *pilha);

void imprime_reversa(Pilha *pilha);

void separa(Pilha *pilha, Pilha *par, Pilha *impar);
