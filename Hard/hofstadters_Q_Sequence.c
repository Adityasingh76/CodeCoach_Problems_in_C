#include<stdio.h>

int q(int num);

int main(void)
{
    int number = 0;
    scanf("%i",&number);
    printf("%i",q(number));
}

int q(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    return q(num - q(num - 1)) + q(num - q(num-2));
}
