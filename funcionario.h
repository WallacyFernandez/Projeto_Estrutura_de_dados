typedef struct lista Lista;

Lista* lst_cria(void);

Lista* lst_insere(Lista* l);

int lst_vazia(Lista *l);

void lst_imprime(Lista*l);

int lst_busca(long long int elemento, Lista* l);

void lst_libera(Lista* l);

void imprimefuncionario(long long int elemento, Lista *l);

void lst_imprimetxt(Lista *l);

Lista *lst_lertxt(Lista *l);