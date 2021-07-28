#include<stdio.h>
#include<string.h>

char *decode(char *message);

int main(void)
{
    char message[500];
    scanf("%[^\n]%*c", &message);
    decode(message);
}

char *decode(char *message)
{
    printf("%s\n",message);
    char message1[500];
    for (int i = 0;i<=strlen(message);i++)
    {
        if ((int)message[i] < 91 && message[i] > 64)
        {
            printf("%c",message[i]);
        }
        if ((int)message[i] < 123 && message[i] > 96)
        {
            printf("%c", message[i]);
        }
        if ((int)message[i] == 32)
        {
            printf("%c", message[i]);
        }
        else
        {
            ;
        }
    }
    
}
