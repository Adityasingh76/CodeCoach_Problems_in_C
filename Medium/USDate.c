#include<stdio.h>
#include<string.h>

int main(void)
{
    char usdate[500];
    int val = 0;
    char *MM;
    char *DD;
    char *YY; 
    char *token;
    scanf("%[^\n]%*c",&usdate);
    for (int i = 0;i < strlen(usdate);i++)
    {
        if ((int)usdate[i] == 47)
        {
            val = 2;
        }
    }
    if (val == 2)
    {
        val = 0;
        token = strtok(usdate, "/");
        while (token != NULL)
        {
            if (val == 1)
            {
                printf("%s/%s/", token, MM);
            }
            MM = token;
            if (val > 1)
            {
                printf("%s", token);
            }
            token = strtok(NULL, "/");
            val += 1;
        }
    }
    if (val == 0)
    {
        val = 0;
        token = strtok(usdate," ");
        while (token != NULL)
        {
            if (val == 1)
            {
                printf("%s %s ",token,MM);
            }
            MM = token;
            if (val > 1)
            {
                printf("%s",token);
            }
            token = strtok(NULL," ");
            val += 1;
        }
    }
}
