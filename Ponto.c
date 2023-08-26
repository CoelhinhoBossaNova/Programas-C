#include<stdio.h>
#include<stdlib.h>

/*
Crie uma estrutura chamada 'Ponto' para representar um ponto no plano cartesiano, com os campos 'x' e 'y'. 
Em seguida, escreva uma função chamada deslocaPonto que recebe um ponteiro para um ponto e desloca 
suas coordenadas em uma determinada quantidade (delta_x e delta_y) passada como parâmetro
*/


typedef struct ponto
{
    float x;
    float y;

}Ponto;

void deslocaPonto(Ponto *ponto,float delta_x,float delta_y)
{

    ponto->x=ponto->x+delta_x;
    ponto->y=ponto->y+delta_y;

}

int main()
{
    Ponto *ponto_principal,ponto_secundario;
    float delta_x;
    float delta_y;

    ponto_principal=&ponto_secundario;

    printf("Digite um valor para o ponto X: ");
    scanf("%f",&ponto_principal->x);
    getchar();

    printf("Digite um valor para o ponto Y: ");
    scanf("%f",&ponto_principal->y);
    getchar();

    printf("Digite o deslocamento que X ira receber: ");
    scanf("%f",&delta_x);
    getchar();

    printf("Digite o deslocamento que Y ira receber: ");
    scanf("%f",&delta_y);
    getchar();

    printf("Antes do procedimento: X=%.2f e Y=%.2f\n\n",ponto_principal->x,ponto_principal->y);

    deslocaPonto(ponto_principal,delta_x,delta_y);

    printf("Depois do procedimento: X=%.2f e Y=%.2f\n\n",ponto_principal->x,ponto_principal->y);

    return 0;
}