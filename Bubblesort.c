#include<stdio.h>

/*
Ordene um vetor de tamanho 10 em ordem crescente;
*/

int main() {

    #define x 20

    int V[x]={10,9,8,7,6,5,4,3,2,1,2,3,4,23,4,3,23,23,2,32};
    int i, j, temp;


    for (i = 0; i < x-1 ; i++)
    {
        for (j = 0; j < x - 1 - i; j++)
        {
            if (V[j] >= V[j+1])
            {
                temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
            }
        }
    }


    printf("\nVetor V ordenado em ordem crescente:\n");
    for (i = 0; i < x; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");

    return 0;
}
