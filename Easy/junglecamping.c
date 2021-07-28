#include<stdio.h>
#include<string.h>

int main(void)
{
    char *animals[4] = {"Lion","Tiger","Snake","Bird"};
    char *noises[4] = {"Grr","Rawr","Sss","Chirp"};
    char input[500];
    printf("Noises: ");
    scanf("%[^\n]%*c",&input);
    char *token = strtok(input," ");
    while (token != NULL)
    {
        for (int i = 0;i < 4 ;i++ )
        {
            if (strcmp(token,noises[i]) == 0)
            {
                printf("%s ",animals[i]);
            }
        }
        token = strtok(NULL," ");
    }
}