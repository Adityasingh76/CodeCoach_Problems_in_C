#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 500

int main(void)
{
    int asci_values[10] = {65,69,73,79,85,97,101,105,111,117};
    char sentence[MAX];
    int total_vowels = 0;
    scanf("%[^\n]%*c",&sentence);
    char *token = strtok(sentence," ");
    while (token != NULL)
    {
        for (int i = 0; i < strlen(token);i++)
        {
            int ech = token[i];
            for (int c = 0;c < 10;c++)
            {
                if (asci_values[c] == ech)
                {
                    total_vowels += 1;
                }
            }
        }
        token = strtok(NULL," ");
    }
    printf("%i",total_vowels);
}