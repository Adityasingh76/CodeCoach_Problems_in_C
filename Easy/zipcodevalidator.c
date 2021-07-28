#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    if (strlen(argv[1]) == 5)
    {
        for (int i = 0;i < strlen(argv[1]);i++)
        {
            int asci = argv[1][i];
            if (asci > 47 && asci < 58)
            {
                ;
            }
            else
            {
                printf("False");
                return 1;
            }
        }
        printf("True");
    }
    else
    {
        printf("False");
        return 1;
    }
}