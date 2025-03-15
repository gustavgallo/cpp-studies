#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

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
}

int main()
{
    int data[MAX];

    for(int i=0; i<MAX; i++)
        data[i] = rand()%(MAX*10);

    long start = clock();
    quicksort(data, MAX);
    long end = clock();

    //for(int i=0; i<MAX; i++)
    //    printf("%5d", data[i]);
    //printf("\n");
    printf("Tempo para %d elementos: %ld ns\n", MAX, (end-start));
}
