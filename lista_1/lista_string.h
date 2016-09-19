/* protótipos das funções com strings */
typedef struct no{
	char info;
	struct no *prox;
} No_lista;

typedef No_lista *Str;

/* inicia lista */
void inicStr(Str *lista);

/* confere se tá vazio ou não */
int listaVazia(Str *lista);

/* insere no inicio */
void insereInicio(Str *lista, char e);

/* insere elemento no fim */
void insereFim(Str *lista, char e);

/* exibe toda a string */
void exibe(Str *lista);

/* retorna o tamanho da lista
 *  	retorna 0 se estiver vazia */
int tamanho(Str *lista);

/* compara as duas strings e retorna
 * 	< 0 se str1 for menor que str2
 * 	> 0 se str2 for maior que str2
 * 	= 0 se forem idênticas */
int compara(Str *lista_1, Str *lista_2);

/* copia a string pra uma outra string (?) 
 * 	retorna 0 se a lista tiver vazia */
void copia(Str *destino, Str *lista);

/* concatena duas strings */
void concatena(Str *lista_1, Str *lista_2);
