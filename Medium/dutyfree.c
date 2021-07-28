#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char prices[500];
    scanf("%[^\n]%*c",&prices);
    char *token = strtok(prices,",");
    while (token != NULL)
    {
        if (atoi(token)*1.1 > 20)
        {
            printf("Back to Shop");
            return 1;
        }
        token = strtok(NULL,",");
    }
    printf("To the terminal");
}
