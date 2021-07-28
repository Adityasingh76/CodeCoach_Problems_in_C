#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

char **sort(char *list[], int index);
int finder(char *find_in,char *to_find);
char *word_generator(char *word,char combinations[][500],int *val2);

int main(void)
{
    printf("This program is case sensitive.\n");
    char *splitted_words[500];
    char first_word_combinations[500][500];
    char words[500];
    scanf("%[^\n]%*c",&words);
    int val = 0;
    int val2 = 0;
    int val4 = 0;
    char *temp;
    char *token = strtok(words," ");
    while (token != NULL)
    {
        splitted_words[val] = token;
        val += 1;
        token = strtok(NULL," ");
    }
    sort(splitted_words,val-1); 
    word_generator(splitted_words[0],first_word_combinations,&val2);
    for (int j = 0;j <= val2;j++)
    {
        val4 = 0;
        for (int k = 0;k < val;k++)
        {
            if (finder(splitted_words[k],first_word_combinations[val2-j]) == 0)
            {
                val4 += 1;
            }
        }
        if (val4 == val)
        {
            printf("%s",first_word_combinations[val2-j]);
            return 0;
        }
    }
}

char *word_generator(char *word,char combinations[][500],int *val2)
{
    int index = 0;
    int val = 0;
    int val3 = 0;
    int index1  = 0;
    int len = strlen(word);
    for (int i = 0;i < pow(len,2);i++)
    {
        for (int j = 0;j < len - index;j++)
        {
            val = 0;
            for (int k = j;k < j+index+1;k++)
            {
                combinations[index1][val] = word[k];
                val += 1;
            }
            if (val == len)
            {
                *val2 = val3;
                return &combinations[0][0];
            }
            val3 += 1;
            index1 += 1;
        }
        index += 1;
    }
}

int finder(char *find_in,char *to_find)
{
    int val = 0;
    int index = 0;
    int val2 = 0;
    char combinations[500][500];
    word_generator(find_in,combinations,&val2);
    for (int j = 0;j <= val2;j++)
    {
        if (strcmp(to_find,combinations[j]) == 0)
        {
            return 0;
        }
        
    }
    return 1;
}


char **sort(char *list[], int index)
{
    char *temp;
    for (int l = 0; l < index; l++)
    {
        for (int k = 0; k < index; k++)
        {
            if (strlen(list[k]) > strlen(list[k+1]))
            {
                temp = list[k];
                list[k] = list[k+1];
                list[k+1] = temp;
            }
        }
    }
    return list;
}
