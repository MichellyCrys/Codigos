//Michelly Crystiane de Souza Gomes -  22152260
#include "stdio.h"
#include "stdlib.h"
#include "listase.h"

//Temperatura
typedef struct temperatura{
    int seq;
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
    int radiacao_solar;
    double temp;
    double umidade_relativa;
}t_temperatura;

)

void imprimir_temperatura(void *lst){
    t_temperatura *temp = lst;

    printf("%d ", temp->seq);

    if (temp->dia < 10)
    {
        printf("0");
    }
    printf("%d/", temp->dia);

    if (temp->mes < 10)
    {
        printf("0");
    }
    printf("%d/", temp->mes);

    printf("%d ", temp->ano);

    if (temp->hora < 10)
    {
        printf("0");
    }
    printf("%d:", temp->hora);

    if (temp->min< 10)
    {
        printf("0");
    }
    printf("%d ", temp->min);
    printf("%d ", temp->radiacao_solar);
    printf("%2f ", temp->temperatura);
    printf("%2f", temp->umidade_relativa);
}