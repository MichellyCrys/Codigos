#include <stdio.h>
#include <stdlib.h>

typedef struct t_temperatura{
    int seq;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int radiacao_solar;
    double temperatura;
    double umidade_relativa;

}t_temperatura;

/*FUNÇAO PRINCIPAL QUE CHAMA =*/
int main(int argc, char const *argv[]){
   
   const int tipo = (int) argv[1][0]-48;

   const char* nome_arquivo = argv[2];
    
    t_temperatura al;
    int cont=0;

    FILE *fd;
    fd= fopen("temperatura-amostra.txt", "r");

    if(fd==NULL)
    {
        printf("ERR");
        exit(1);
    }

    while(fscanf(fd,"%hhd%*[\t]%hhd%*[/]%hhd%*[/]%hhd%*[ ]%hhd%*[:]%hhd%hhd%hhf%hhf%*c",
    &al.seq, &al.dia, &al.mes, &al.ano, &al.hora, &al.minuto,&al.radiacao_solar, &al.temperatura, 
    &al.umidade_relativa)==9){
        
        cont++;
        printf("%hhd ",al.seq);
        if(al.dia<10)
        {
            printf("0%hhd/",al.dia);
        }
        else{
            printf("%hhd/",al.dia);
        }
        if(al.mes<10)
        {
            printf("0%hhd/",al.mes);  
        }
        else{
            printf("%hhd/",al.mes);
        }
        printf("%hhd",al.ano);

        printf(" 0%hhd:0",al.hora);
        printf("%hhd ",al.minuto);
        printf("%hhd ",al.radiacao_solar);
        printf("%.2f ",al.temperatura);
        printf("%.2f\n",al.umidade_relativa);

    }
    fclose(fd);
}
