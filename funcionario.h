typedef struct lista Lista;

// função que cria uma lista vazia (NULL)
Lista* lst_cria(void);

// função que insere um elemento no início da lista
Lista* lst_insere(Lista* l);



//função que verifica se a lista está vazia
int lst_vazia(Lista *l);



//função que imprime os elementos da lista
void lst_imprime(Lista*l);



//função que busca um elemento na lista
Lista * lst_busca(long long int elemento, Lista* l);

//função que retira um elemento da lista


//função que libera a memória alocada para a lista
void lst_libera(Lista* l);

void imprimefuncionario(long long int elemento, Lista *l);

// função que insere de forma ordenada um elemento na lista

void lst_imprimetxt(Lista *l);

Lista *lst_lertxt(Lista *l);