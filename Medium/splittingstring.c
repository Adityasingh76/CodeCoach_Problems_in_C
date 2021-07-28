#include<stdio.h>
#include<string.h>

int main(void)
{
    char word[500];
    int split_index = 0;
    scanf("%i\n",&split_index);
    scanf("%s",&word);
    int val = strlen(word);
    int val2 = 0;
    int val3 = 0;
    int i1 = 0;
    for (int i = 0; i < val;i++)
    {
        if (i % split_index == val2 && i != 0 && val3 == 0)
        {
            printf("-");
            val3 = 1;
            i1 -= 1;
            val2 += 1;
            val += 1;
        }
        else
        {
            printf("%c",word[i1]);
            val3 = 0;
        }
        i1++;
    }
}
