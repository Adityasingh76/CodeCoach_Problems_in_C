#include<stdio.h>
#include<string.h>

int in(char word[],char to_find,int index);

int main(void)
{
    char link[500] = "https://www.youtu.be/kbxkq_w51PM";
    int val = 0;
    int j = 1;
    if (in(link,'=',strlen(link)) == 0)
    {
        char *token = strtok(link,"=");
        while (token != NULL)
        {
            if (val == 1)
            {
                printf("%s",token);
            }
            val += 1;
            token = strtok(NULL,"=");
        }
    }
    else
    {
        char *token = strtok(link,"e");
        while (token != NULL)
        {
            if (val == 1)
            {
                while (token[j] != '\0')
                {
                    printf("%c",token[j++]);
                }
            }
            val += 1;
            token = strtok(NULL,"e");
        }
    }
}

int in(char word[],char to_find,int index)
{
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i++] == to_find)
        {
            return 0;
        }
    }
    return 1;
}
