#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
int count = 0;

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
    // random
    printf("Randomizado:\n");
    for (int tam = 0; tam < 10000; tam += 1000)
    {
        int data[MAX + tam];
        for (int i = 0; i < MAX + tam; i++)
        {
           
            data[i] = rand() % (MAX * 10);
        }
        sort(data, MAX + tam);
        
        printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
    }
    printf("\n\n");
    count = 0;

     // ordenado
     printf("Ordenado:\n");
     for (int tam = 0; tam < 10000; tam += 1000)
     {
         int data[MAX + tam];
         for (int i = 0; i < MAX + tam; i++)
         {
            
             data[i] = i;
         }
         sort(data, MAX + tam);
         
         printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
     }

    printf("\n\n");
    count = 0;

    // inverso
    printf("Inverso:\n");
    for (int tam = 0; tam < 10000; tam += 1000)
    {
        int data[MAX + tam];
        for (int i = 0; i < MAX + tam; i++)
        {
           
            data[i] = MAX + tam - i;
        }
        sort(data, MAX + tam);
        
        printf("Tamanho: %d - Trocas: %d\n", MAX + tam, count);
    }

   printf("\n\n");
   count = 0;

 

    
}
