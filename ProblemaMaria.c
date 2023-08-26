#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Seja um conjunto de disciplinas. A quantidade de disciplinas  deve ser informada pelo usuário. 
De cada disciplina deseja-se saber: código, nome, carga horária, e o conjunto de alunos matriculados nela. 
Sendo que cada disciplina pode ter uma quantidade de alunos diferente. 
De cada aluno em uma disciplina deseja-se saber: matricula, média na disciplina. 
Fazer uma função para gerar o conjunto de disciplinas, com o conjunto de alunos relacionados a cada disciplina. 
Em seguida, fazer uma função para pesquisar um aluno e as médias das disciplinas que ele já cursou.
*/

typedef struct Aluno
{
    int matricula;
    float media_disciplina;

}aluno;

typedef struct Disciplinas
{
    char codigo[32];
    char nome[32];
    int carga_horaria;
    aluno *aluno;

}disciplinas;

int libera_memoria(disciplinas *Disciplinas,int quantidade_disciplinas,int *quantidade_alunos)
{
    free(quantidade_alunos);
    for(int i=0;i<quantidade_disciplinas;i++)
    {
        free(Disciplinas[i].aluno);
    }

    free(Disciplinas);

    return 0;

}




void busca_aluno(disciplinas *Disciplinas,int quantidade_disciplinas,int *quantidade_alunos)
{
    char escolha;
    int matricula;

    printf("Qual a matricula do aluno: ");
    scanf("%d",&matricula);
    getchar();

    for(int i=0;i<quantidade_disciplinas;i++)
    {
        for(int j=0;j<quantidade_alunos[i];j++)
        {
            if(Disciplinas[i].aluno[j].matricula==matricula)
            {
                printf("Matricula do aluno: %d\n",Disciplinas[i].aluno[j].matricula);
                printf("Media do aluno em %s: %.2f\n\n",Disciplinas[i].nome,Disciplinas[i].aluno[j].media_disciplina);
            }
            else continue;
        }
    }

    printf("Deseja procurar mais um aluno[S/N]: ");
    escolha=getchar();

    if(escolha=='S')
    {
        printf("\n-->Pressione 'Enter' para buscar o proximo aluno");
        getchar();
        busca_aluno(Disciplinas,quantidade_disciplinas,quantidade_alunos);
    }
    else
    {
        printf("Fim do programa! Pressione 'Enter' para sair: ");
        getchar();
        libera_memoria(Disciplinas,quantidade_disciplinas,quantidade_alunos);
        system("cls");
        printf("Fim!!!");
        exit(0);
    }
}

int main()
{

    disciplinas *Disciplinas=NULL;
    unsigned int tamanho;
    unsigned int tamanho_alunos;
    int *quantidade_alunos=NULL;
    char busca;

    printf("Qual a quantidade de disciplinas: ");
    scanf("%u",&tamanho);
    getchar();

    Disciplinas=(disciplinas*)malloc(tamanho *sizeof(disciplinas));
    quantidade_alunos=(int*)malloc(tamanho *sizeof(disciplinas));

    for(int i=0,j=1;i<tamanho;i++,j++)
    {

        printf("Nome da disciplina %d: ",j);
        fgets(Disciplinas[i].nome,sizeof(Disciplinas[i].nome),stdin);
        Disciplinas[i].nome[strcspn( Disciplinas[i].nome,"\n")]='\0';

        printf("Qual o codigo de %s: ",Disciplinas[i].nome);
        fgets(Disciplinas[i].codigo,sizeof(Disciplinas[i].codigo),stdin);
        Disciplinas[i].codigo[strcspn( Disciplinas[i].codigo,"\n")]='\0';

        printf("Qual a carga horaria de %s: ",Disciplinas[i].nome);
        scanf("%d",&Disciplinas[i].carga_horaria);
        getchar();

        printf("Quantos alunos estao matriculados em %s: ",Disciplinas[i].nome);
        scanf("%u",&tamanho_alunos);
        getchar();

        Disciplinas[i].aluno=(aluno*)malloc(tamanho_alunos*sizeof(aluno));
        quantidade_alunos[i]=tamanho_alunos;

        for(int x=0,y=1;x<tamanho_alunos;x++,y++)
        {
            printf("Digite a matricula do aluno %d: ",y);
            scanf("%d",&Disciplinas[i].aluno[x].matricula);
            getchar();

            printf("Digite a media do aluno %d: ",y);
            scanf("%f",&Disciplinas[i].aluno[x].media_disciplina);
            getchar();

        }

    }

    printf("-->Pressione 'Enter' para ver cada aluno e sua disciplina correspondente: ");
    getchar();

    for(int i=0;i<tamanho;i++)
    {
        printf("\n=========Informacoes Disciplina============\n");
        printf("\nNome da disciplina: %s\n",Disciplinas[i].nome);
        printf("Codigo da disciplina: %s\n",Disciplinas[i].codigo);
        printf("Carga horaria da disciplina: %d\n",Disciplinas[i].carga_horaria);
        printf("\n=========Informacoes Alunos============\n");

        for(int j=0;j<quantidade_alunos[i];j++)
        {
            printf("Matricula do aluno %d: %d\n",j+1,Disciplinas[i].aluno[j].matricula);
            printf("Media do aluno em %s: %.2f\n\n",Disciplinas[i].nome,Disciplinas[i].aluno[j].media_disciplina);
        }

        printf("-->Pressione 'Enter' para ver a proxima disciplina e seus alunos: ");
        getchar();

    }

    printf("\nSem mais disciplinas para mostra!!!\n\n");
    printf("Deseja buscar um aluno [S/N]: ");
    busca=getchar();

    if(busca=='S')
    {
        system("cls");
        busca_aluno(Disciplinas,tamanho,quantidade_alunos);
    }
    else
    {   
        printf("Fim do programa! Pressione 'Enter' para sair: ");
        getchar();
        system("cls");
        printf("Fim!!!");
        exit(0);
    }

    return 0;
}

