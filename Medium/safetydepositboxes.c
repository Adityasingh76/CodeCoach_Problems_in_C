#include<stdio.h>
#include<string.h>

int main(void)
{
    char items[500];
    char needed_item[500];
    int val=5;
    scanf("%[^\n]%*c",&items);
    scanf("%[^\n]%*c",needed_item);
    char *token = strtok(items,",");
    while (token != NULL)
    {
        if (strcmp(token,needed_item) == 0)
        {
            printf("%i",val);
        }
        token = strtok(NULL,",");
        val += 5;
    }
}