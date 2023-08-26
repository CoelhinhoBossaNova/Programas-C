#include<stdio.h>

/*
Crie uma estrutura chamada Retangulo com os campos largura e altura. 
Escreva uma função chamada calculaArea que recebe um ponteiro para um retângulo e 
retorna a área do retângulo.
*/

typedef struct retangulo
{
    float largura;
    float altura;

}Retangulo;


float calculaArea(Retangulo *retangulo)
{
    float area;

    area=(retangulo->altura)*(retangulo->largura);

    return area;

}

int main()
{
    Retangulo retangulo;
    float area;

    printf("Digite a largura do retangulo: ");
    scanf("%f",&retangulo.largura);
    getchar();

    printf("Digite a altura do retangulo: ");
    scanf("%f",&retangulo.altura);
    getchar();

    area=calculaArea(&retangulo);

    printf("A area do retangulo e %.2f\n\n",area);

    return 0;
}