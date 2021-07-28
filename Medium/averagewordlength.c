#include<stdio.h>
#include<string.h>

void main(void)
{
    char sentence[500];
    int val = 0;
    int val1 = 0;
    scanf("%[^\n]%*c",&sentence);
    char *token = strtok(sentence," ");
    while (token != NULL)
    {
        for (int i = 0;i < strlen(token);i++)
        {
            val += 1;
        }
        val1 += 1;
        token = strtok(NULL," ");
    }
    printf("%i",val/val1);
}
