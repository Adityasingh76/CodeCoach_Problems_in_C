#include<stdio.h>
#include<string.h>

int main(void)
{
    int name_index = 0;
    int val2 = 0;
    char name[500];
    char name1[500];
    char initials[500];
    char *token;
    scanf("%i",&name_index);
    for (int i = 0;i < name_index;i++)
    {
        scanf("%s %s",&name,&name1);
        initials[i+val2] = name[0];
        initials[i+val2+1] = name1[0];
        initials[i+val2+2] = ' ';
        val2+=2;
    }
    for (int j = 0;j < strlen(initials);j++)
    {
        printf("%c",initials[j]);
    }
}
