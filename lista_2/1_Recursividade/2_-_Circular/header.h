typedef struct ll{
  int n;
  struct ll *prox;
} ll;

typedef ll* Lista;
void inicLista(Lista *plista);
int listaVazia(Lista *plista);
// Todas recursivas:
void imprimirNormal(ll *lista, ll *comeco);
void imprimirReverso(ll *lista, ll *comeco);
void insereOrdenado(Lista *plista, ll *comeco, int num);
int tamanhodaLista(ll *lista, ll *comeco);
//Bonus opcional:
void liberaRecursivo(Lista *plista, ll *comeco);
