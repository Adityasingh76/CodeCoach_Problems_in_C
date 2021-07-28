#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(void)
{
    int dividend;
    char nos[500];
    scanf("%[^\n]%*c", &nos);
    scanf("%i",&dividend);
    char *token = strtok(nos, " ");
    while (token != NULL)
    {
        if (dividend % atoi(token) == 0)
        {
            ;
        }
        else
        {
            printf("Not divisible by all!");
            return;
        }
        token = strtok(NULL," ");
    }
    printf("Divisivle by all!");
}
