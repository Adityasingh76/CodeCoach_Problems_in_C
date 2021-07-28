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
    for (int i = 1;i<=strlen(message);i++)
    {
        if ((int)message[i-1] < 91 && message[i-1] > 64)
        {
            printf("%i",1);
            message1[strlen(message) - i] = message[i - 1];
        }
        if ((int)message[i - 1] < 123 && message[i - 1] > 96)
        {
            printf("%i", 2);
            message1[strlen(message) - i] = message[i - 1];
        }
        if ((int)message[i - 1] == 32)
        {
            printf("%i", 3);
            message1[strlen(message) - i] = message[i - 1];
        }
        else
        {
            ;
        }
    }
    printf("%s",message1);
    
}
