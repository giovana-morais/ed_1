#define ALGUM_NUMERO_GRANDE 50
typedef struct fila_estatica
{
  int vetor[ALGUM_NUMERO_GRANDE];
  unsigned tam, inicio,fim;
} fila;

void inicFila(fila *pf);
int filaVazia(fila f);
void enqueue(fila *pf,int n);
int dequeue(fila *pf);
// Nao eh necessario limpar o vetor para liberaFila
void liberaFila(fila *pf);
