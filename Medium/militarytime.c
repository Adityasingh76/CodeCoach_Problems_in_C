#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char time[500] = "09:59 PM";
    int no_lst[200];
    int val = 0;
    int val1 = 0;
    int val2 = 0;
    char *token1;
    char *token = strtok(time," ");
    while (token != NULL)
    {
        if (val == 0)
        {
            no_lst[0] = ((token[0]-48)*10) + (token[1]-48);
            no_lst[1] = ((token[3]-48) * 10) + (token[4]-48);
        }
        if (val == 1)
        {
            if (strcmp(token,"PM") == 0)
            {
                val2 = 1;
            }
        }
        val += 1;
        token = strtok(NULL," ");
    }
    for (int i = 0; i < 2;i++)
    {
        if (val2 == 1)
        {
            if (i == 0)
            {
                if (no_lst[0] > 12 || no_lst[1] > 60)
                {
                    printf("Invalid Input");
                    return 1;
                }
                if (no_lst[i] < 12)
                {
                    printf("%i:",no_lst[0]+12);
                }
                if (no_lst[0] == 12)
                {
                    printf("00:");
                }
            }
            if (i == 1)
            {
                printf("%i",no_lst[1]);
            }
        }
        if (val2 == 0)
        {
            printf("%i:%i",no_lst[0],no_lst[1]);
            val2 += 2;
        } 
    }
}
