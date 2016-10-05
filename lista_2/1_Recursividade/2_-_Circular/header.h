typedef struct ll{
  int n;
  struct ll *prox;
} ll;

void inicLista(ll **plista);
// Todas recursivas:
void imprimirNormal(ll *lista, ll *comeco);
void imprimirReverso(ll *lista, ll *comeco);
void insereOrdenado(ll **plista, ll *comeco, int num);
int tamanhodaLista(ll *lista, ll *comeco);
//Bonus opcional:
void liberaRecursivo(ll **plista, ll *comeco);
