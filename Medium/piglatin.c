#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[])
{
    char *new_sentence;
    char *token = strtok(argv[1]," ");
    int val = 0;
    while (token != NULL)
    {
        for (int i = 1;i < strlen(token)+1;i++)
        {
            if (i == strlen(token))
            {
                printf("%c",token[0]);
            }
            else
            {
                printf("%c",token[i]);
            }
        }
        printf("a");
        printf("y ");
        token = strtok(NULL," ");
    }
}