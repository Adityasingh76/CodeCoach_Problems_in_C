#include<stdio.h>
#include<string.h>

int char_cmp(char first_char,char *symbol_lst1);

int main(void)
{
    char symbol_lst[7] = {'!', '@', '#', '$', '%', '&', '*'};
    char no_lst[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char password[500] = "Hello@$World19";
    int symbol_no = 0;
    int no_index = 0;
    if (strlen(password) >= 7)
    {
        for (int i = 0;i < strlen(password);i++)
        {
            if (char_cmp(password[i],symbol_lst) == 0)
            {
                symbol_no += 1;
            }
            else if (char_cmp(password[i],no_lst) == 0)
            {
                no_index += 1;
            }
        }
    }
    if (symbol_no >= 2 && no_index >= 2)
    {
        printf("Strong!");
    }
    else
    {
        printf("Weak!");
    }
}

int char_cmp(char first_char,char *symbol_lst1)
{
    for (int i = 0;i < strlen(symbol_lst1);i++)
    {
        if (symbol_lst1[i] == first_char)
        {
            return 0;
        }
    }
    return 1;
}
