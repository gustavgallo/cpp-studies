#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
long long int count = 0;

void sort(int values[], int total);

void sort(int values[], int total)
{
    for (int i = 0; i < total; i++)
    {
        char trocou = 0;
        for (int j = 0; j < total - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
                trocou = 1;
                count++;
            }
        }
        if (!trocou)
            break;
    }
}

int main()
{
    FILE *arquivo = fopen("bubblesort.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    srand(time(NULL));
    
    fprintf(arquivo,"Randomizado:\n");
    for (int tam = 0; tam < 21000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = rand() % (MAX * 10);
        }
        sort(data, MAX + tam);
        fprintf(arquivo,"Tamanho: %d - Trocas: %lld\n", MAX + tam, count);
        free(data);
    }
    fprintf(arquivo,"\n\n");
    count = 0;
    
    fprintf(arquivo,"Ordenado:\n");
    for (int tam = 0; tam < 21000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = i;
        }
        sort(data, MAX + tam);
        fprintf(arquivo,"Tamanho: %d - Trocas: %lld\n", MAX + tam, count);
        free(data);
    }
    fprintf(arquivo,"\n\n");
    count = 0;
    
    fprintf(arquivo,"Inverso:\n");
    for (int tam = 0; tam < 21000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = MAX + tam - i;
        }
        sort(data, MAX + tam);
        fprintf(arquivo,"Tamanho: %d - Trocas: %lld\n", MAX + tam, count);
        free(data);
    }
    printf("\n\n");
    count = 0;
    
    return 0;
}