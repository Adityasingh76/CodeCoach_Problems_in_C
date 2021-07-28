#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int yards = atoi(argv[1]);
    if (yards < 1)
    {
        printf("shh");
    }
    if (yards > 10)
    {
        printf("High Five");
    }
    else
    {
        for (int i=0;i<yards;i++)
        {
            printf("Ra! ");
        }
    }

}