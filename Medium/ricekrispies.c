#include<stdio.h>

int main(void)
{
    int a[6];

    scanf("%i %i %i %i %i %i",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
    for (int i = 0;i < 6;i++)
    {
        if (a[i]%3==0)
        {
            printf("pop! ");
        }
        else if (a[i]%3!=0 && a[i]%2==0)
        {
            printf("Crackle! ");
        }
        else if (a[i]%3!=0 && a[i]%2!=0)
        {
            printf("snap! ");
        }
    }

}