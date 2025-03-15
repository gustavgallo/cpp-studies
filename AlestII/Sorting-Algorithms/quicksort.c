#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
long long int count = 0;
void quicksort(int data[], int tam);
void _qsort(int data[], int p, int r);
int partition(int data[], int p, int r);
void swap(int data[], int p1, int p2);

void quicksort(int data[], int tam)
{
    _qsort(data, 0, tam-1);
}

void _qsort(int data[], int p, int r) {
    if(p < r) {
        int q = partition(data,p, r);
        _qsort(data, p, q-1);
        _qsort(data, q+1, r);
    }
}

int partition(int data[], int p, int r) {
    int q = p;
    for(int j=p; j<r; j++) {
        if(data[j] <= data[r]) {
            swap(data,j,q);
            q++;
            
        }
    }
    swap(data,r,q);
    return q;
}

void swap(int data[], int p1, int p2) {
    int tmp = data[p1];
    data[p1] = data[p2];
    data[p2] = tmp;
    count ++;
}

int main()
{
    FILE *arquivo = fopen("quicksort.txt", "w");
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
        quicksort(data, MAX + tam);
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
        quicksort(data, MAX + tam);
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
        quicksort(data, MAX + tam);
        fprintf(arquivo,"Tamanho: %d - Trocas: %lld\n", MAX + tam, count);
        free(data);
    }
    printf("\n\n");
    count = 0;
    
    return 0;
}
