#include<stdio.h>

int main(void)
{
    int a = 0;
    int c = 0;
    int b;
    int val = 0;
    scanf("%i",&a);
    for (int i = 0;i < a;i++)
    {
        scanf("%i",&b);
        if (b > c)
        {   
            val += 1;
        }
        c += b;
    }
    if (val == a || val == a -1)
    {
        printf("True");
        return 0;
    }
    else
    {
        printf("False");
    }
}

