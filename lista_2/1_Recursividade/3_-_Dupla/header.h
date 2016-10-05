typedef struct ll{
  int n;
  struct ll *prox;
  struct ll *ant;
} ll;

typedef ll* Lista;

// Funções não-recursivas
void inicLista(Lista *plista);
int listaVazia(Lista *plista);
void exibe(Lista *plista);
// Todas recursivas:
void imprimirNormal(ll *lista);
void imprimirReverso(ll *lista);
void insereOrdenado(Lista *plista, int num);
int tamanhodaLista(ll *lista);
//Bonus opcional:
void liberaRecursivo(Lista *plista);
