#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *arquivo = fopen("nomes.txt", "r+");  // Abrir o arquivo para leitura e escrita

    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int deslocamento = 0;
    char linha[100]; 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) 
    {
        deslocamento += strlen(linha);

        printf("%d",deslocamento);
        getchar();
        if (strstr(linha, "marcelo") != NULL) 
        {
            deslocamento+=1;
            break;
        }
    }


    fseek(arquivo, deslocamento, SEEK_SET);

    fputc('L', arquivo);

    fclose(arquivo);

    printf("Caractere adicionado com sucesso!\n");

    return 0;
}