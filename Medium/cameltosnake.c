#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    for (int i = 0;i < strlen(argv[1]);i++)
    {
        if ((int)argv[1][i] < 91)
        {
            printf("_%c",(int)argv[1][i] + 32);
        }
        else{
            printf("%c",argv[1][i]);
        }
    }
}
