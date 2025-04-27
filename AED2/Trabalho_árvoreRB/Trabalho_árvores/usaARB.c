#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreRB.h"

// Definição da estrutura person
typedef struct {
    char name[50];
    char birthdate[11];
    char cpf[12];
} person;

// Função de comparação personalizada para pessoas
int comparePeople(void* a, void* b) {
    person* x = (person*)a;
    person* y = (person*)b;
    return strcmp(x->cpf, y->cpf);
}

// Função de impressão personalizada para pessoas
void printPerson(void* data) {
    person* p = (person*)data;
    printf("Nome: %s\n", p->name);
    printf("Data de nascimento: %s\n", p->birthdate);
    printf("CPF: %s\n\n", p->cpf);
}

int main() {
    // Cria uma nova árvore rubro-negra
    t_red* tree = createARB();

    // Insere algumas pessoas na árvore
    person p1 = {"Joao Silva", "01/01/1990", "12345678901"};
    insertNode(tree, &p1, comparePeople);
    person p2 = {"Maria Santos", "02/02/1980", "23456789012"};
    insertNode(tree, &p2, comparePeople);
    person p3 = {"Pedro Oliveira", "03/03/1970", "34567890123"};
    insertNode(tree, &p3, comparePeople);

    // Imprime as pessoas armazenadas na árvore
    printf("Pessoas na arvore:\n");
    printTree(tree, printPerson);


    printf("DEPOIS DA REMOCAO\n\n");
    removeNode(tree, &p2, comparePeople);

    printf("Pessoas na arvore:\n\n");
    printTree(tree, printPerson);

    // Libera a memória alocada para a árvore
    free(tree);

    return 0;
}