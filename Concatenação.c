#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Crie uma estrutura chamada 'String' que contém um campo 'texto' para armazenar uma string. 
Escreva uma função que recebe dois ponteiros para estruturas 'String' e concatena o 
texto do segundo ponteiro ao texto do primeiro ponteiro. A função deve atualizar o 
campo 'texto' da primeira estrutura com a string resultante.
*/

#define linha 2

typedef struct string
{
    char *texto;

}String;

String**cria_matriz(int tamanho1,int tamanho2)
{
    String **matriz;

    matriz=(String**)malloc((linha)*sizeof(String*));

    for(int i=0;i<linha;i++)
    {

        *(matriz+i)=(String*)malloc(2*(sizeof(String)));
    }

    (*(matriz))->texto=(char*)malloc(tamanho1*sizeof(char));
    (*(matriz+1))->texto=(char*)malloc(tamanho2*sizeof(char));

    return matriz;
}

void preenche_matriz(String **matriz)
{
    printf("Digite a string 1: ");
    scanf(" %[^\n]",&(*(*matriz)->texto));

    printf("Digite a string 2: ");
    scanf(" %[^\n]",&(*(*(matriz+1))->texto));

    (*(matriz))->texto=realloc((*(matriz))->texto,strlen(((*(matriz))->texto))*sizeof(char));
    (*(matriz+1))->texto=realloc((*(matriz+1))->texto,strlen(((*(matriz+1))->texto))*sizeof(char));
}

char* concatena_string(String **matriz)
{
    String auxiliar;

    (auxiliar).texto=(char*)malloc((strlen((*(matriz))->texto)+strlen((*(matriz+1))->texto))*sizeof(char));

    sprintf(auxiliar.texto,"A concatenacao da string 1 e string 2 e %s%s",(*(matriz))->texto,(*(matriz+1))->texto);

    return auxiliar.texto;
    
}

void limpa_memoria(String **matriz)
{
    free((*(matriz))->texto);
    free((*(matriz+1))->texto);
    free(matriz);

}

int main()
{

    String **matrizstr1;
    char *string_concatenada;
    int tamanhostr1;
    int tamanhostr2;

    printf("Digite o tamanho maximo que a primeira string pode ter: ");
    scanf("%d",&tamanhostr1);
    getchar();

    printf("Digite o tamanho maximo que a segunda string pode ter: ");
    scanf("%d",&tamanhostr2);
    getchar();
    
    matrizstr1=cria_matriz(tamanhostr1,tamanhostr2);

    preenche_matriz(matrizstr1);

    string_concatenada=concatena_string(matrizstr1);

    printf("\n%s\n\n",string_concatenada);

    limpa_memoria(matrizstr1);

    printf("-->Pressione 'Enter' para sair do programa: ");
    getchar();

    return 0;
}