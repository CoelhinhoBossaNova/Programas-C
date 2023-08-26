#include <stdio.h>
#include <stdlib.h>

//                                              Maneira Normal

// Função para criar e preencher a matriz
int** criarMatriz(int linhas, int colunas) {
    // Alocação de memória para o array de ponteiros para inteiros (linhas)
    int** matriz;

    matriz = (int**)malloc(linhas * sizeof(int*));

    // Alocação de memória para cada linha (array de inteiros)
    for (int i = 0; i < linhas; i++) {
        matriz[i]= (int*)malloc(colunas * sizeof(int));
    }

    // Preenchimento da matriz com valores
    int count = 1;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j]= count++;
        }
    }

    return matriz;  // Retorna a matriz criada
}

// Função para imprimir a matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int linhas = 3;
    int colunas = 4;

    // Chamada da função criarMatriz para criar a matriz dinâmica
    int** matriz = criarMatriz(linhas, colunas);

    // Chamada da função imprimirMatriz para exibir a matriz
    imprimirMatriz(matriz, linhas, colunas);

    // Liberar a memória alocada para a matriz
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

//                                                      Aritimetica de ponteiro

/*
// Função para criar e preencher a matriz
int** criarMatriz(int linhas, int colunas) {
    // Alocação de memória para o array de ponteiros para inteiros (linhas)
    int** matriz;

    matriz = (int**)malloc(linhas * sizeof(int*));

    // Alocação de memória para cada linha (array de inteiros)
    for (int i = 0; i < linhas; i++) {
        *(matriz+i) = (int*)malloc(colunas * sizeof(int));
    }

    // Preenchimento da matriz com valores
    int count = 1;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            *(*(matriz+i)+j)= count++;
        }
    }

    return matriz;  // Retorna a matriz criada
}

// Função para imprimir a matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", *(*(matriz+i)+j));
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int linhas = 3;
    int colunas = 4;

    // Chamada da função criarMatriz para criar a matriz dinâmica
    int** matriz = criarMatriz(linhas, colunas);

    // Chamada da função imprimirMatriz para exibir a matriz
    imprimirMatriz(matriz, linhas, colunas);

    // Liberar a memória alocada para a matriz
    for (int i = 0; i < linhas; i++) {
        free(*(matriz+i));
    }
    free(matriz);

    return 0;
}
*/