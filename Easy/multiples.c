#include<stdio.h>

int main(void)
{
    int val = 0;
    int number;
    scanf("%i",&number);
    for (int i = 0;i<number;i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            val += i;
        }
    }
    printf("%i",val);
}