#include<stdio.h>
#include<string.h>

int main(void)
{
    char sentence[500];
    int val = 0;
    scanf("%[^\n]%*c",&sentence);
    char *token = strtok(sentence," ");
    while (token != NULL)
    {
        if ((int)token[0] != val && val != 0)
        {
            printf("False");
            return 1;
        }
        val = (char)token[strlen(token)-1];
        token = strtok(NULL," ");
    }
}
