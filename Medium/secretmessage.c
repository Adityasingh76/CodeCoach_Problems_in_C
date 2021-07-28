#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(void)
{
    char message[500];
    scanf("%[^\n]%*c",&message);
    char token;
    for (int i = 0;i < strlen(message);i++)
    {
        token = message[i];
        if (islower(token) == 0)
        {
            printf("%c", 91 + 64 - (int)token);
        }
        else
        {
            printf("%c", 123 + 96 - (int)token);
        }
        
    }
}
