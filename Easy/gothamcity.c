#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int val = atoi(argv[1]);
    if (val <= 5)
    {
        printf("I got it!");
    }
    if (val > 5 && val <= 10)
    {
        printf("Help me batman!");
    }
    if (val > 10)
    {
        printf("Best of Luck!");
    }
}