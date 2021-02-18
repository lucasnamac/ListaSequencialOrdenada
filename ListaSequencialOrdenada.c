#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencialOrdenada.h"
#define max 20

struct lista{
    int no[20];
    int Fim;
};


Lista cria_lista(){
    Lista lst;
    lst=(Lista) malloc (sizeof(struct lista));
    if(lst!=NULL) lst->Fim=0;
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->Fim ==0) return 1;
    else

    return 0;

}

int lista_cheia(Lista lst){
    if(lst->Fim==max) return 1;
    else
    return 0;

}

int insere_ord(Lista lst, int elem) {
    if (lst == NULL || lista_cheia(lst) == 1)return 0; // Falha

    if (lista_vazia(lst) == 1 || elem >= lst->no[lst->Fim-1]) {
        lst->no[lst->Fim] = elem; // Insere no final
    }

    else {
        int i, aux= 0;
        while (elem >= lst->no[aux]) // Percorrimento
            aux++;
        for (i = lst->Fim; i > aux; i--)// Deslocamento
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem; // Inclui o elemento na lista
    }
    lst->Fim++; // Avan�a o Fim
    return 1;
}


int remove_ord (Lista lst, int elem) {
    if (lst == NULL || lista_vazia(lst) == 1 || elem < lst->no[0] || elem > lst->no[lst->Fim-1]) return 0;  // Falha
    int i, Aux = 0;

    while(Aux < lst->Fim && lst->no[Aux] < elem) Aux++;

    if (Aux == lst->Fim || lst->no[Aux] > elem) return 0; // Falha

    for (i = Aux+1; i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i];

    lst->Fim--;
    return 1;
}


int imprimir(Lista lst){
    int i;

    if(lst== NULL || lista_vazia(lst)==1) return 0;

    for(i=0; i<lst->Fim; i++){
        printf("%d ", lst->no[i]);
    }
    printf("\n");
    return 1;
}

void menu(){
    printf("1- Inserir\n");
    printf("2- Remover\n");
    printf("3- Imprimir\n");
    printf("4- Remover a pares\n");
    printf("5- Maior\n");
    printf("6- Iguais\n");
    printf("7- Intercalar\n");

}

int removePares(Lista lst){
    int i;

    if(lst==NULL || lista_vazia(lst)==1)return 0;

    for(i=0; i<lst->Fim; i++){
        if(lst->no[i]%2==0){
            lst->no[i]=lst->no[i+1];
            lst->Fim--;
        }
    }
    return 1;
}

int Maior(Lista lst, int *elem){
    if(lst==NULL || lista_vazia(lst)==1) return 0;

    else
        *elem=lst->no[lst->Fim-1];
        return 0;

}

int Iguais(Lista l1, Lista l2){
    int i;

    if(l1==NULL && l2==NULL) return 0;

    if(lista_vazia(l1)==1 || lista_vazia(l2)==1) return 0;

    else{
        for(i=0; i<l1->Fim; i++){
            if(l1->no[i]==l2->no[i]){
                printf("Sao iguais\n");
                return 1;
            }else{
                printf("Nao sao iguais\n");
                return 1;
            }
        }
    }
    return 1;
}

Lista intercala(Lista lst1, Lista lst2){
    int i=0, j=0;
    Lista lst3;
    lst3=(Lista) malloc (2 * sizeof(struct lista));
    if(lst3 != NULL) lst3->Fim= 0;

    while(i<lst1->Fim || j<lst2->Fim){
        if(j==lst2->Fim  || ((i<lst1->Fim)&&lst1->no[i]<=lst2->no[j])){
            lst3->no[lst3->Fim++]=lst1->no[i++];
        }
        else{
            lst3->no[lst3->Fim++]=lst2->no[j++];
        }

    }
    return lst3;

}


