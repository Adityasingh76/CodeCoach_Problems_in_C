#include<stdio.h>
#include<string.h>

int main(void)
{
    char map[500] = "XXPXP,XXXXX,XXXXX,XXXXX,XXXXX";
    int index1 = 0;
    int index2 = 0;
    int rows = 0;
    int val = 0;
    char *token = strtok(map,",");
    while (token != NULL)
    {
        val = 0;
        for (int i = 0;i < strlen(token);i++)
        {
            if (token[i] == 'P')
            {
                if (index1 == 0)
                {
                    index1 = i+1;
                }
                else{
                    index2 = i+1;
                }
            }
            else{
                val += 1;
            }
        }
        if (val >= 5 && index2 < 1)
        {
            printf("%i %s\n", val, token);
            rows += 1;
        }
        token = strtok(NULL,",");
    }
    if (rows != 0)
    {
        rows += 1;
    }
    printf("%i",(index2 - index1)+rows);
}
