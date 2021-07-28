#include<stdio.h>
#include<string.h>

int main(void)
{
    char signs[500];
    char reversed[500];
    int len = 0;
    int val = 0;
    for (int i = 0;i < 4;i++)
    {
        scanf("%s",&signs);
        len = strlen(signs);
        for (int j = 0;j < strlen(signs);j++)
        {
            reversed[len - j - 1] = signs[j];
        }
        if (strcmp(signs,reversed) == 0)
        {
            val += 1;
        }
    }
    if (val > 0)
    {
        printf("Open!");
    }
    else{
        printf("Trash!");
    }

}
