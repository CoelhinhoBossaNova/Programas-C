#include <stdio.h>

//? Char/Char 

int main() 
{
    FILE *file_in = fopen(__FILE__, "r"); 
    FILE *file_out = fopen("codigo_fonte.txt", "w"); 

    if (file_in == NULL || file_out == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file_in)) != EOF) 
    {
        fputc(c, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("Codigo fonte copiado para arquivo 'codigo_fonte.txt'.\n");

    return 0;
}


//? String/String 

/*int main() 
{
    FILE *file_in = fopen(__FILE__, "r");
    FILE *file_out = fopen("codigo_fonte.txt", "w");

    if (file_in == NULL || file_out == NULL) 
    {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char buffer[256]; // Buffer para armazenar cada linha
    
    while (fgets(buffer, sizeof(buffer), file_in) != NULL) 
    {
        fputs(buffer, file_out); // Copia a linha para o arquivo de saída
    }

    fclose(file_in);
    fclose(file_out);

    printf("Código fonte copiado para arquivo 'codigo_fonte.txt'.\n");

    return 0;
}*/
