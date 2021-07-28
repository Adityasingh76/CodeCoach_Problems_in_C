#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    if (atoi(argv[1]) == atoi(argv[2]) + atoi(argv[3]))
    {
        printf("candy time");
    }
    else{
        printf("Continue");
    }
}