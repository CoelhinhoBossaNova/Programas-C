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

typedef struct alunos
{

    int matricula;
    float media;

}Alunos;

typedef struct disciplinas
{
    char codigo[32];
    char nome[32];
    int carga_horaria;
    Alunos *matriculados;

}Disciplinas;



int* cria_struct(Disciplinas *disciplinas , int tamanho)
{
    int tamanho_alunos;
    int *qt_alunos;

    qt_alunos=(int*)malloc(tamanho*sizeof(int));

    for(int i=0;i<tamanho;i++)
    {
        printf("Qual o nome da disciplina %d: ",i+1);
        scanf(" %[^\n]",&((disciplinas+i)->nome));

        printf("Qual o codigo de %s: ",(disciplinas+i)->nome);
        scanf(" %[^\n]",&((disciplinas+i)->codigo));

        printf("Qual a carga horaria de %s: ",(disciplinas+i)->nome);
        scanf("%d",&((disciplinas+i)->carga_horaria));
        getchar();

        printf("Quantos alunos estao matriculados em %s: ",(disciplinas+i)->nome);
        scanf("%d",&tamanho_alunos);
        getchar();

        (disciplinas+i)->matriculados=(Alunos*)malloc(tamanho_alunos*sizeof(Alunos));

        *(qt_alunos+i)=tamanho_alunos;

        for(int j=0;j<tamanho_alunos;j++)
        {
            printf("Qual a matricula do aluno %d: ",j+1);
            scanf("%d", &((disciplinas + i)->matriculados + j)->matricula);
            getchar();

            printf("Qual a media do aluno %d: ",j+1);
            scanf("%f",&((disciplinas+i)->matriculados+j)->media);
            getchar();

        }

    }

    return qt_alunos;

}

void busca_matricula(Disciplinas *disciplinas , int *qt_alunos, int tamanho)
{
    int busca;
    char escolha;

    do
    {
        printf("Digite a matricula do aluno: ");
        scanf("%d",&busca);
        getchar();

        for(int i=0;i<tamanho;i++)
        {
            for(int j=0;j<*(qt_alunos+i);j++)
            {
                if(busca==((disciplinas+i)->matriculados+j)->matricula)
                {   

                    printf("\n=========Informacoes Alunos============\n");
                    printf("Matricula do aluno: %d\n",((disciplinas+i)->matriculados+j)->matricula);
                    printf("Media do aluno em %s: %.2f\n\n",(disciplinas->nome),((disciplinas+i)->matriculados+j)->media);

                }
                
            }


        }

        printf("Deseja continuar buscando aluno[S/N]: ");
        escolha=getchar();


    }while(escolha=='S');


}

void limpa_memoria(Disciplinas *disciplinas , int *qt_alunos, int tamanho)
{
    for(int i=0;i<tamanho;i++)
    {

        free((disciplinas+i)->matriculados);

    }


    free(qt_alunos);
    free(disciplinas);


}

int main()
{
    Disciplinas *disciplinas_principal;
    Disciplinas *disciplinas_secundaria;
    int tamanho;
    int *quantidade_alunos;
    int escolha;

    printf("Quantas disciplinas vc deseja registrar: ");
    scanf("%d",&tamanho);
    getchar();

    disciplinas_secundaria=(Disciplinas*)malloc(tamanho*sizeof(Disciplinas));

    disciplinas_principal=disciplinas_secundaria;
    
    quantidade_alunos=cria_struct(disciplinas_principal,tamanho);

    system("cls");

    printf("Deseja procurar um aluno[S/N]: ");
    escolha=getchar();

    if(escolha=='S')
    {
        busca_matricula(disciplinas_principal,quantidade_alunos,tamanho);
    }

    printf("-->Pressione 'Enter' para finalizar o programa: ");
    getchar();
    getchar();

    system("cls");

    printf("\nFim!!!\n");

    return 0;
}