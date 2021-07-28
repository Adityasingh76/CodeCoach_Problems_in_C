#include<stdio.h>

int main(void)
{
    int length;
    scanf("%i",&length);
    int numbers;
    int result = 0;
    for (int i = 0;i < length;i++)
    {
        scanf("%i",&numbers);
        if (numbers % 2 == 0)
        {
            result += numbers;
        }
        else{
            ;
        }
    }
    printf("%i",result);
}
