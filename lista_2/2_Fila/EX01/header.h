/*
* Implementacao de Fila Circular
*/
#define MAX_CARROS 10
typedef struct fila{
  int placa[MAX_CARROS];
  int comeco;
  int fim;
  int tam;
} fila;
void inicFila(fila *f);
int filaCheia(fila *f);
void enfileiraCarro(int placa, fila *f);
int desenfileiraCarro(fila *f);
