#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
int count = 0;

void sort(int values[], int total);
void mergesort2(int values[], int low, int high, int helper[]);
void merge(int values[], int low, int middle, int high, int helper[]);

void sort(int values[], int total) {
    int *helper = (int *)malloc(total * sizeof(int));
    if (helper == NULL) {
        printf("Erro ao alocar memória para helper.\n");
        return;
    }
    mergesort2(values, 0, total - 1, helper);
    free(helper);
}

void mergesort2(int values[], int low, int high, int helper[]) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergesort2(values, low, middle, helper);
        mergesort2(values, middle + 1, high, helper);
        merge(values, low, middle, high, helper);
    }
}

void merge(int values[], int low, int middle, int high, int helper[]) {
    for (int i = low; i <= high; i++) {
        helper[i] = values[i];
    }
    int i = low, j = middle + 1, k = low;
    while (i <= middle && j <= high) {
        if (helper[i] <= helper[j]) {
            values[k++] = helper[i++];
        } else {
            values[k++] = helper[j++];
        
        }
        count++;
    }
    while (i <= middle) {
        values[k++] = helper[i++];
        count ++;
    }
}

int main() {
    srand(time(NULL));
    
    printf("Randomizado:\n");
    for (int tam = 0; tam < 10000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = rand() % (MAX * 10);
        }
        sort(data, MAX + tam);
        printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
        free(data);
    }
    printf("\n\n");
    count = 0;
    
    printf("Ordenado:\n");
    for (int tam = 0; tam < 10000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = i;
        }
        sort(data, MAX + tam);
        printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
        free(data);
    }
    printf("\n\n");
    count = 0;
    
    printf("Inverso:\n");
    for (int tam = 0; tam < 10000; tam += 1000) {
        int *data = (int *)malloc((MAX + tam) * sizeof(int));
        if (data == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        for (int i = 0; i < MAX + tam; i++) {
            data[i] = MAX + tam - i;
        }
        sort(data, MAX + tam);
        printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
        free(data);
    }
    printf("\n\n");
    count = 0;
    
    return 0;
}