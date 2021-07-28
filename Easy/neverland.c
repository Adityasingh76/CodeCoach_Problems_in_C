#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char ages[4];
    int ages1[5];
    scanf("%[^\n]%*c",&ages);
    char *token = strtok(ages," ");
    int i =0;
    while (token != NULL)
    {
        ages1[i] = (int)atoi(token);
        token = strtok(NULL," ");
        i += 1; 
    }
    printf("My twin is %d years old and he is %i years older than me.",(ages1[0]+ages1[1]),ages1[1]);

}