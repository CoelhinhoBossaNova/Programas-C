#include<stdio.h>
#include<stdlib.h>

/*
Crie uma estrutura chamada Aluno que contém os campos: nome, nota1, nota2, nota3 e média. 
Escreva uma função que recebe um array de estruturas Aluno e o número total de alunos. 
O programa deve imprimir as informações dos em ordem decrescente baseado na media dos alunos
e informar a maior media.
*/

typedef struct alunos
{
    char nome[44];
    float nota1;
    float nota2;
    float nota3;
    float media;

}Alunos;

void cria_vetor(Alunos *alunos, int tamanho)
{

    for(int i=0;i<tamanho;i++)
    {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]",&(alunos+i)->nome);

        printf("Digite a primeira nota do aluno %s: ",(alunos+i)->nome);
        scanf("%f",&(alunos+i)->nota1);
        getchar();

        printf("Digite a segunda nota do aluno %s: ",(alunos+i)->nome);
        scanf("%f",&(alunos+i)->nota2);
        getchar();

        printf("Digite a terceira nota do aluno %s: ",(alunos+i)->nome);
        scanf("%f",&(alunos+i)->nota3);
        getchar();
  
    }

} 

float* calcula_media(Alunos *alunos, int tamanho)
{

    float *media_aluno;
    
    media_aluno=(float*)malloc(tamanho*sizeof(tamanho));

    for(int i=0;i<tamanho;i++)
    {

        (alunos+i)->media=((alunos+i)->nota1+(alunos+i)->nota2+(alunos+i)->nota3)/3.0;
        *(media_aluno+i)=((alunos+i)->nota1+(alunos+i)->nota2+(alunos+i)->nota3)/3.0;
    }

    return media_aluno;

}

void organiza_media(float *media_alunos, int tamanho)
{

    float temp=0;

    for(int i=0;i<tamanho-1;i++)
    {
        for(int j=0;j<tamanho-1-i;j++)
        {
            if(*(media_alunos+j)>=*(media_alunos+j+1))
            {
                temp=*(media_alunos+j);
                *(media_alunos+j)=*(media_alunos+j+1);
                *(media_alunos+j+1)=temp;

            }

        }
    }

}

float mostra_nota(Alunos *alunos, float* media_alunos, int tamanho)
{

    int tamanho2=tamanho;

    for(int i=0,j=0;j<tamanho;i++)
    {
        if(*(media_alunos+(tamanho2-1))==(alunos+i)->media)
        {
            printf("\n\nNome do aluno: %s\n",(alunos+i)->nome);
            printf("Primeira nota do aluno: %.2f\n",(alunos+i)->nota1);
            printf("Segunda nota do aluno: %.2f\n",(alunos+i)->nota2);
            printf("Terceira nota do aluno: %.2f\n",(alunos+i)->nota3);
            printf("Media do aluno: %.2f\n\n",*(media_alunos+(tamanho2-1)));
            printf("+----------------------------------------------+");

            ++j;
            i=-1;
            --tamanho2;
        }

    }

    return *(media_alunos+(tamanho-1));

}


int main()
{

    Alunos *alunos1,*alunos2;
    int tamanho=0;
    float *media_alunos;
    float maior_media=0;

    printf("Quantos alunos voce deseja registrar: ");
    scanf("%d",&tamanho);

    alunos2=(Alunos*)malloc(tamanho*sizeof(Alunos));

    alunos1=alunos2;

    cria_vetor(alunos1,tamanho);

    media_alunos=calcula_media(alunos1,tamanho);

    organiza_media(media_alunos,tamanho);

    system("cls");

    maior_media=mostra_nota(alunos1,media_alunos,tamanho);

    printf("\n\nA maior media da classe de %d alunos foi de %.2f\n\n",tamanho,maior_media);

    free(media_alunos);
    free(alunos1);

    printf("-->Pressione 'Enter' para sair do programa: ");
    getchar();

    return 0;
}