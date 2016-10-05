typedef struct ll{
  int n;
  struct ll *prox;
  struct ll *ant;
} ll;

void inicLista(ll **plista);
// Todas recursivas:
void imprimirNormal(ll *lista);
void imprimirReverso(ll *lista);
void insereOrdenado(ll **plista, int num);
int tamanhodaLista(ll *lista);
//Bonus opcional:
void liberaRecursivo(ll **plista);
