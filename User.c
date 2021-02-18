#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencialOrdenada.h"

int main(){
    int opcao, elem, remover, qtd=0, maio;
    Lista l1, l2, l3;
    l1=cria_lista();
    l2=cria_lista();
    l3=cria_lista();

    menu();
    scanf("%d", &opcao);

    while(opcao!=9){
        switch(opcao){
            case(1):
                printf("Digite o numero para inserir a lista\n");
                scanf("%d", &elem);
                insere_ord(l1, elem);
                break;
            case(2):
                printf("Digite o numero para remover\n");
                scanf("%d", &remover);
                remove_ord(l1, remover);
                break;
            case(3):
                imprimir(l1);
                break;
            case(4):
                removePares(l1);
                break;

            case(5):
                Maior(l1, &maio);
                printf("%d\n", maio);
                break;

            case(6):
                printf("Digite a quantidade de elementos que quer inserir na L2\n");
                scanf("%d", &qtd);
                printf("Digite os elementos da L2\n");
                while(qtd--){
                    scanf("%d", &elem);
                    insere_ord(l2, elem);
                }
                if(Iguais(l1, l2)==0) printf("nao foi possivel verificar\n");
                break;
            case(7):
                printf("Digite a quantidade de elementos que quer inserir na L2\n");
                scanf("%d", &qtd);
                printf("Digite os elementos da L2\n");
                while(qtd--){
                    scanf("%d", &elem);
                    insere_ord(l2, elem);
                }
                l3=intercala(l1, l2);
                imprimir(l3);
                break;
        };
        menu();
        scanf("%d", &opcao);

    }

    return 0;
}
