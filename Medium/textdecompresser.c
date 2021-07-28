#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    char val[500];
    int k = 0;
    int token = 0;
    for (int i = 0;i < strlen(argv[1]);i++)
    {
        token = (char)argv[1][i];
        if (token < 58 && token > 47)
        {
            for (int j = 0;j < token - 48; j++)
            {
                printf("%s",val);
            }
            k = 0;
        }
        else
        {
            val[k] = argv[1][i];
            k += 1;
        }
    }
}
