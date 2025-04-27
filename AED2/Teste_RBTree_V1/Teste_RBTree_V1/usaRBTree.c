#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

int comparaInt(void* d1, void* d2) {
    int a = *(int*)d1;
    int b = *(int*)d2;
    return a - b;
}

void imprimeInt(void* info) {
    printf("%d ", *(int*)info);
}

int main() {
    t_red *tree = criaRED(comparaInt, imprimeInt);

    int data[] = {40, 50, 30, 35};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        inserirRED(tree, &data[i]);
    }

    printf("Arvore apos insercoes: ");
    imprimirRED(tree);
    printf("\n\n");

    int remove = 50;
    printf("\nElemento a ser removido: %d\n", remove);
    removerRED(tree, &remove);

    printf("Arvore apos remocao: ");
    imprimirRED(tree);
    printf("\n\n");

    estatisticaRED(tree);

    return 0;
}
