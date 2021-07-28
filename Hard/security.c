#include<stdio.h>
#include<string.h>

char *remove1(char removable,char string[]);

int main(void)
{
    char input[500];
    scanf("%s",&input);
    remove1('x',input);    
}

char* remove1(char removable, char string[])
{
    char new_string[3];
    int val = 0;
    for (int i = 0;i < strlen(string);i++)
    {
        if (string[i] != removable)
        {
            new_string[val] = string[i];
            val += 1;
        }
    }
    for (int i = 0; i < strlen(new_string); i++)
    {
        if (new_string[i] == '$')
        {
            if (new_string[i + 1] == 'T' || new_string[i - 1] == 'T')
            {
                printf("ALARM!");
                return 0;
            }
        }
    }
    printf("quite");

}
