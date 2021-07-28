#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{
    char sentence[500];
    char newsentence[500];
    char *numbers[11] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
    scanf("%[^\n]%*c",&sentence);
    char *token = strtok(sentence," ");
    int i = 0;
    while (token != NULL)
    {
        if ((int)token[0] < 58 && (int)token[0] > 47)
        {
            printf("%s ",numbers[atoi(token)]);
        }
        else
        {
            printf("%s ",token);
        }
        token = strtok(NULL," ");
        i++;
    }
}
