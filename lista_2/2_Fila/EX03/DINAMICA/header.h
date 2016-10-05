typedef struct fila_dinamica
{
  int n;
  struct fila_dinamica* prox;
} fila;

void inicFila(fila **pf);
int filaVazia(fila *f);
void enqueue(fila **pf,int n);
int dequeue(fila **pf);
void liberaFila(fila **pf);


/* Uso opcional, caso queira, podendo adaptar as assinaturas
das funcoes para trabalhar com esse struct.
typedef struct enqueue{
  fila *comeco;
  fila *fim;
} enqueue */
