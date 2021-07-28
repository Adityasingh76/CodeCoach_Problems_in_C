#include<stdio.h>
#include<string.h>

#define MAX 500

int detect(char word[]);

int main(void)
{
    char word[MAX];
    scanf("%s",&word);
    detect(word);
}

int detect(char word[])
{
    for (int i = 0; i < strlen(word);i++)
    {
        int val = word[i];
        for (int c = 0; c < strlen(word); c++)
        {
            int val1 = word[c];
            if (val == val1 && i != c)
            {
                printf("DejaVu");
                return 1;
            }
        }
        
    }
    printf("Unique!");
}