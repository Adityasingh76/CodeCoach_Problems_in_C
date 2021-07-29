#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* reverse(char word[],char empty_lst[],int len);

int main(void)
{
    char number[500] = "4091131560563988";
    int val = 0;
    if (strlen(number) != 16)
    {
        printf("Invalid Input!");
        return 1;
    }
    char reversed[500];
    int no[500];
    reverse(number,reversed,strlen(number));
    for ( int i = 0;i < strlen(number);i++)
    {
        if ((i+1) % 2 == 0 && i != 0)
        {
            no[i] = (reversed[i]-48)*2;
        }
        else{
            no[i] = reversed[i] - 48;
        }
        if (no[i] > 9)
        {
            no[i] = no[i] - 9;
        }
        val += no[i];

    }
    if (val % 10 == 0)
    {
        printf("Valid");
        return 0;
    }
    printf("Invalid");
    return 1;
}

char *reverse(char word[], char empty_lst[], int len)
{
    for (int i = 0;i < len;i++)
    {
        empty_lst[len-i-1] = word[i];
    }
    return empty_lst;
}
