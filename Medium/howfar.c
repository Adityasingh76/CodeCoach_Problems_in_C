#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int val = 1;
    int val1 = 0;
    for (int i = 0; i < strlen(argv[1]);i++)
    {
        if (val1 == 1)
        {
            val += 1;
        }
        if ((int)argv[1][i] == 72 || (int)argv[1][i] == 80)
        {
            val -= 1;
            val1 += 1;
        }
        if (val1 == 2)
        {
            printf("%i",val);
            return 0;
        }
    }
}
