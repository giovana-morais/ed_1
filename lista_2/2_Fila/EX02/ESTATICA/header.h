
#define MAX 1000

typedef struct no{
  int info[MAX];
  int head, tail, tam;
} Fila;

void inicFila(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

void insereFila(Fila *f, int e);

int removeFila(Fila *f);

void imprime(Fila *f);

void fibonacci(Fila *f, int e);
