#include<stdio.h>
#include<stdlib.h>

/*
Segunda prova maria resolução primeira questão
*/

typedef struct Tarefa
{

    int pessoa;

}tarefa;

void cria_vetor(tarefa **pesquisa , int *qt)
{

    printf("Quantas pessoas fizeram a pesquisa: ");
    scanf("%d",qt);
    getchar();

    *pesquisa=(tarefa*)malloc((*qt)*sizeof(tarefa*));

    if(pesquisa==NULL)
    {
        printf("Nao foi possivel alocar memoria!!!");
        exit(1);

    }

}

void preenche_vetor(tarefa *pesquisa , int qt)
{

    for(int i=0;i<qt;i++)
    {

        printf("Qual a resposta da pessoa %d: ",i+1);
        scanf("%d",&(pesquisa+i)->pessoa);
        getchar();
    }

}

void mediaP(tarefa *pesquisa, int qt , float *media)
{

    for(int i=0;i<qt;i++)
    {
        *media+=(pesquisa+i)->pessoa;
    }

    *media/=(float)qt;

}

tarefa *ordena(tarefa *pesquisa, int qt)
{

    tarefa *auxiliar=(tarefa*)malloc(qt*sizeof(tarefa));

    if(auxiliar==NULL)
    {

        printf("Nao foi possivel alocar memoria!!!");
        exit(1);

    }
    
    for(int i=0;i<qt;i++)
    {
        (auxiliar+i)->pessoa=(pesquisa+i)->pessoa;

    }

    for(int i=0;i<qt-1;i++)
    {

        for(int j=0;j<qt-1-i;j++)
        {
            if((auxiliar+j)->pessoa>=(auxiliar+1+j)->pessoa)
            {
                int temp=(auxiliar+j)->pessoa;
                (auxiliar+j)->pessoa=(auxiliar+j+1)->pessoa;
                (auxiliar+j+1)->pessoa=temp;

            }
        }
    }

    return auxiliar;

}

void medianaP(tarefa *pesquisa, int qt, float *mediana)
{

    if(qt%2==1)
    {
        *mediana=(pesquisa+(qt/2))->pessoa;

    }
    else
    {
        *mediana=(pesquisa+(qt/2))->pessoa;
        *mediana+=(pesquisa+((qt/2)-1))->pessoa;

    }

}

void frequenciaP(tarefa *pesquisa , int qt , int *moda , int *frequencia)
{

    int auxiliar=0;

    for(int i=0;i<9;i++)
    {
        *(frequencia+i)=0;
        *(moda+i)=0;
    }

    for(int i=0;i<qt;i++)
    {
        switch((pesquisa+i)->pessoa)
        {
            case(1):
                *(frequencia+0)+=1;
                break;
            case(2):
                *(frequencia+1)+=1;
                break;
            case(3):
                *(frequencia+2)+=1;
                break;
            case(4):
                *(frequencia+3)+=1;
                break;
            case(5):
                *(frequencia+4)+=1;
                break;
            case(6):
                *(frequencia+5)+=1;
                break;
            case(7):
                *(frequencia+6)+=1;
                break;
            case(8):
                *(frequencia+7)+=1;
                break;
            case(9):
                *(frequencia+8)+=1;
                break;
            default:
                break;
        }
    }

    for(int i=0;i<9;i++)
    {

        if(*(frequencia+i)>=auxiliar)
        {     
            auxiliar=*(frequencia+i);
        }

    }

    for(int i=0,j=0;i<9;i++)
    {
        if(*(frequencia+i)==auxiliar)
        {

            *(moda+j)=(i+1);
            j++;
        }

    }

}

void mostra(tarefa *pesquisa , tarefa *pesquisa_ordenada , int qt , float media , float mediana , int *moda , int *frequencia)
{
 
    printf("Pesquisa em ordem normal: ");
    
    for(int i=0;i<qt;i++)
    {

        printf("%d ",pesquisa[i].pessoa);

    }

    printf("\nPesquisa em ordem crescente: ");
    
    for(int i=0;i<qt;i++)
    {

        printf("%d ",(pesquisa_ordenada+i)->pessoa);

    }

    printf("\nMedia: %.2f",media);
    printf("\nMediana: %.2f",mediana);
    printf("\nModa: ");

    for(int i=0;i<9; i++)
    {

        if(*(moda+i)!=0)
        {

            printf("%d,",*(moda+i));
            continue;

        }

    }

    printf("\nFrequencia:\n");
    
    for(int i=0;i<9;i++)
    {

        printf("%d = %d vezes\n",i+1,*(frequencia+i));

    }

}

int main()
{

    tarefa *pesquisa=NULL;
    tarefa *pesquisa_ordenada=NULL;
    int quantidade=0;
    float media=0;
    float mediana=0;
    int moda[9];
    int frequencia[9];
    
    cria_vetor(&pesquisa,&quantidade);
    preenche_vetor(pesquisa,quantidade);
    mediaP(pesquisa,quantidade,&media);
    pesquisa_ordenada=ordena(pesquisa,quantidade);
    medianaP(pesquisa_ordenada,quantidade,&mediana);
    frequenciaP(pesquisa,quantidade,moda,frequencia);
    mostra(pesquisa,pesquisa_ordenada,quantidade,media,mediana,moda,frequencia);

    free(pesquisa);
    free(pesquisa_ordenada);

    printf("-->Pressione 'Enter' para finalizar o programa: ");
    getchar();

    return 0;
}
//% Tomara que eu não reveja essa mensagem!!!