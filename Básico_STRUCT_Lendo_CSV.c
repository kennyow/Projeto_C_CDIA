#include <stdio.h>
#include <locale.h>


typedef struct
{
    char date;
    float open, high, low, close, volume;

}Market;


int main(void)
{

    setlocale(LC_ALL, "Portuguese");
    printf("Análise de Dados do Mercado Financeiro\n\n"); //Título
    FILE *file;

    file = fopen("ia.csv", "r");

    if (file = NULL)
    {
        printf("Erro abrindo o arquivo.\n");
        return 1;
    }

    Market markets[100];

    int read = 0;
    int records = 0;

    do
    {
        read = fscanf(file,
                      "%c,%f, %f, %f, %f, %f",
                      &markets[records].date,
                      &markets[records].open,
                      &markets[records].high,
                      &markets[records].low,
                      &markets[records].close,
                      &markets[records].volume);

        if (read == 6) records++;

        if (read != 6 && !feof(file))
        {
            printf("Formato inválido.\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Erro lendo o arquivo.\n");
            return 1;
        }

    } while (!feof(file));

    fclose(file);

    printf("\n%d Registros Lidos. \n\n", records);

    for (int i = 0; i < records; i++)
        printf("c,%f, %f, %f, %f, %f\n",
            markets[i].date,
            markets[i].open,
            markets[i].high,
            markets[i].low,
            markets[i].close,
            markets[i].volume);
    printf("\n");



return 0;
}
