typedef struct lista *Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int lista_cheia(Lista lst);

int insere_ord(Lista lst, int elem);

int remove_ord (Lista lst, int elem);

int imprimir(Lista lst);

void menu();

int removePares(Lista lst);

int Maior(Lista lst, int *elem);

int Iguais(Lista l1, Lista l2);

Lista intercala(Lista lst1, Lista lst2);

