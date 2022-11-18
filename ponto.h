typedef struct list Listo;

Listo* lst_cria2(void);

Listo* lst_insere2(Listo* l);

int lst_vazia2(Listo *l);

void lst_imprime2(Listo*l);

void lst_libera2(Listo* l);

void imprimepontodefuncionario(long long int elemento, Listo *l);

void lst_buscadata(Listo *l);

Listo * lst_retira(Listo*l, long long int elemento);

Listo *lst_editaponto(Listo *l);

Listo *lst_lertxt2(Listo *l);