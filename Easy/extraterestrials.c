#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int len = strlen(argv[1]);
    char reversed_word[len];
    for (int i = 0;i < len;i++)
    {
        printf("%c",argv[1][len-i-1]);
    }
}