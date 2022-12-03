#include <stdio.h>
#include <locale.h>

//Fun��o SOMA
float Array_sum(float array[] , int n)
{
    float sum;
     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Fun��o M�DIA
float Array_media(float array[] , int n)
{
    float media;
    float sum;

     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
       media = sum/n;
    }
    return media;
}


//Rearranjo da array
void Array_sort(int *arr , int n)
{
    // Declarando vari�veis locais
    int i=0 , j=0 , temp=0;


    // Comando FOR para reposicionar os elementos da array:
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp        = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }

}

// Fun��o MEDIANA:
float Find_median(float array[] , int n)
{
    float median=0;

    // se o n�mero de elementos da array for �mpar
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // se o n�mero de elementos for par
    else
        median = array[n/2];

    return median;
}

//Fun��o VARI�NCIA
float Array_variance(float array[] , int n, float media, float sum)
{

    float x[n];
    float variance;


    for (int i = 0; i < n; i++)
    {
        sum = sum + pow((array[i] - media), 2);
    }
    variance = sum / (float)n;

    return variance;
}

//Fun��o DESVIO PADR�O
float Array_deviation(float variance)
{
    float std_deviation;


    std_deviation = sqrt(variance);
    return std_deviation;
}


int main()
{

    setlocale(LC_ALL, "Portuguese");

    //Iniciando a Array
    float arr[] = {15.08, 2.00, 4000, 42, 7.50};
    float sum = 0;
    float media = 0;
    float median = 0;
    int n = 0;
    int  i;
    float arr2[n];
    float average, variance, std_deviation, sum3 = 0, sum1 = 0;
    float x[n];


    //Calculando o tamanho da array
    n = sizeof(arr)/sizeof(arr[0]);


    //Copiando todos os elementos da array em outra
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

     //Soma da array:
    sum = Array_sum(arr, n);
    //M�dia da array:
    media = Array_media(arr, n);

    // Rearranjo da array:
    Array_sort(arr , n);

    //Mediana da array:
    median = Find_median(arr , n);

    //Vari�ncia da array:
    variance = Array_variance(arr , n, media, sum);

    //Desvio padr�o da array:
    std_deviation = Array_deviation(variance);



    //PRINTS

    printf("A lista principal cont�m os valores nesta ordem: ");

    for (int i = 0; i < n; i++) {
        printf("%.3f | ", arr2[i]);
    }
    printf("\n");
    printf("O total de itens da lista � %d\n", n);
    printf("O �ltimo elemento � %f\n", sizeof(arr2)/sizeof(arr2[0]) - 1);
    printf("A soma de seus elementos �: %.3f\n", sum);
    printf("A m�dia dos elementos �: %.3f\n", media);
    printf("A lista secund�ria cont�m os valores rearranjados nesta ordem: ");

    for (int i = 0; i < n; i++) {
        printf("%.3f | ", arr[i]);
    }
    printf("\nA mediana dos elementos �: %.3f\n", median);
    printf("A vari�ncia dos elementos �: %.3f\n", variance);
    printf("O desvio padr�o dos elementos �: %.3f\n", std_deviation);

    return 0;


}
