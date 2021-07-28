#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char nos[500];
    float total_val = 0;
    scanf("%[^\n]%*c",&nos);
    char *token = strtok(nos,",");
    while (token != NULL)
    {
        if (atoi(token) > 19)
        {
            total_val += atoi(token);
        }
        else{
            total_val += atoi(token) * 1.07;
        }
        token = strtok(NULL,",");
    }
    printf("%f",total_val);
}
