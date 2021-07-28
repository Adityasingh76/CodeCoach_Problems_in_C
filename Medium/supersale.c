#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void selectionSort(int arr[],int n);

int main(void)
{
    char prices[500];
    int price[500];
    int total_savings = 0;
    scanf("%[^\n]%*c", &prices);
    char *token = strtok(prices,",");
    int i = 0;
    while (token != NULL)
    {
        price[i] = atoi(token);
        token = strtok(NULL,",");
        i++;
    }
    selectionSort(price,i);
    for (int y = 0;y < i-1;y++)
    {
        total_savings += price[y] * 1.07 * 0.3;
    }
    printf("%i",total_savings);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}


