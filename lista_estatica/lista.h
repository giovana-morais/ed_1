#define MAX 100

typedef int elem_t;

typedef struct {
	  elem_t item[MAX];
	    int tam;
} vet;

// Inicializa o vetor
void inicia (vet *v);

// Insere um elemento no inicio do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insereIni (vet *v, elem_t n);

// Remove um elemento do inicio do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retiraIni (vet *v, elem_t *elemRemovido);

// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n);

// Remove um elemento do final do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retira (vet *v, elem_t *elemRemovido);

// Verifica o numero de vezes que o elemento n se repete no vetor
int verRepeticao (vet v, elem_t n);

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v);

// Retorna 1 caso o vetor esteja vazio ou 0 caso contrario
int vazio (vet v);
//
// Retorna o elemento na posicao ind
elem_t acessa (vet v, int ind);

// Retorna o numero de elementos do vetor
int tamanho(vet v);

