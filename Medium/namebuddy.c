#include<stdio.h>
#include<string.h>


void main(void)
{
    char names[500];
    char own_name[500];
    scanf("%[^\n]%*c",&names);
    scanf("%s",&own_name);
    char *token = strtok(names," ");
    while(token != NULL)
    {
        if (token[0] == own_name[0])
        {
            printf("comapare notes!");
            return;
        }
        token = strtok(NULL," ");
    }
    printf("No such luck!");
}
