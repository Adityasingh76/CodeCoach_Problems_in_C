#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAX 500

char *sort(char *list, int index);
int clean(char *list, int index);
char *pop(char word[], char to_remove, int index);
int letter_rank(char *word, char letter, int index);
int slice(char *word,int start,int end);
int factorial(int no);
int word_rank_no_repetition(char word[],int len,int *rank);
int word_rank_repetition(char word[],int len,int *rank);
int repetition_checker(char word[],char lst[],int index_lst[],int index);
int to_upper(char word[],int len);

int main(void)
{
    char a[MAX];
    char c[MAX];
    printf("Enter the word: ");
    scanf("%s",&c);
    to_upper(c,strlen(c));
    strcpy(a,c);
    int rank = 0;
    int index_lst[MAX];
    char repeated_words[MAX];
    char *b = sort(c,strlen(c));
    int index = repetition_checker(b,repeated_words,index_lst,strlen(a));
    if (index == -1)
    {
        word_rank_no_repetition(a,strlen(a),&rank);
    }
    if (index > -1)
    {
        word_rank_repetition(a,strlen(a),&rank);
    }
    printf("Rank: %i",rank);
}

int word_rank_repetition(char word[],int len,int *rank)
{
    if (len == 2)
    {
        char temp[MAX];
        strcpy(temp, word);
        char *temp1 = sort(word, 2);
        if (strcmp(temp, temp1) == 0)
        {
            *rank += 1;
        }
        else
        {
            *rank += 2;
        }
        return 0;
    }
    char initial_word[MAX];
    char repeated_words[MAX];
    int index_lst[MAX];
    float val = 1;
    strcpy(initial_word,word);
    char *cleaned = sort(word,len);
    char sorted[MAX];
    strcpy(sorted,cleaned);
    int new_len = clean(cleaned, len);
    float letterrank = letter_rank(sorted, initial_word[0], len);
    int index = repetition_checker(sorted,repeated_words,index_lst,len);
    for (int k = 0;k < index+1;k++)
    {
        val *= factorial(index_lst[k]);
    }
    float pre_answer = letterrank/val;
    float answer = pre_answer * factorial(len-1);
    *rank += answer;
    int sliced = slice(initial_word, 1, len);
    word_rank_repetition(initial_word, sliced - 1, rank);
    return 0;
}

int word_rank_no_repetition(char word[],int len,int *rank)
{
    if (len == 2)
    {
        char temp[MAX];
        strcpy(temp,word);
        char *temp1 = sort(word,2);
        if (strcmp(temp,temp1) == 0)
        {
            *rank += 1;
        }
        else
        {
            *rank += 2;
        }
        return 0;
    }
    char initial_word[MAX];
    strcpy(initial_word,word);
    char *cleaned = sort(word,len);
    char sorted[MAX];
    strcpy(sorted,cleaned);
    int new_len = clean(cleaned,len);
    int letterrank = letter_rank(cleaned,initial_word[0],new_len);
    int answer = letterrank * factorial(new_len - 1);
    *rank += answer;
    int sliced = slice(initial_word,1,len);
    word_rank_no_repetition(initial_word,sliced-1,rank);
    return 0;
}

char *sort(char *list, int index)
{
    char temp;
    for (int l = 0; l < index; l++)
    {
        for (int k = 0; k < index-1; k++)
        {
            if (list[k] > list[k + 1])
            {
                temp = list[k];
                list[k] = list[k + 1];
                list[k + 1] = temp;
            }
        }
    }
    return list;
}

int to_upper(char word[],int len)
{
    for (int i = 0;i < len;i++)
    {
        if (word[i] < 123 && word[i] > 96)
        {
            word[i] = word[i]-32;
        }
    }
    return 0;
}

int repetition_checker(char word[],char lst[],int index_lst[],int index)
{
    int val = 0;
    int j = 0;
    for (int i = 0;i < index; i++)
    {
        if (word[i] == word[i+1] && word[i] != word[i-1])
        {
            j = i;
            while (word[j] == word[i])
            {
                j += 1;
            }
            index_lst[val] = j-i;
            j = 0;
            lst[val] = word[i];
            val += 1;
        }
    }
    lst[val] = '\0';
    return val-1;
}   

int clean(char *list, int index)
{
    int val = 0;
    char temp_list[index];
    for (int i = 0; i < index+1; i++)
    {
        if (list[i] != list[i + 1])
        {
            temp_list[val] = list[i];
            val += 1;
        }
    }
    for (int y = 0; y < val+1; y++)
    {
        list[y] = temp_list[y];
    }
    return val;
}

int letter_rank(char *word, char letter,int index)
{
    int val = 0;
    for (int i = 0;i < index;i++)
    {
        if (word[i] == letter)
        {
            return val;
        }
        val += 1;
    }
    return 0;
}

int factorial(int no)
{
    int result = 1;
    for (int i = 1;i < no+1;i++)
    {
        result = result * i;
    }
    return result;
}

char *pop(char word[], char to_remove, int index)
{
    char temp_list[index];
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        if (word[i] != to_remove)
        {
            temp_list[j++] = word[i];
        }
    }
    temp_list[j] = '\0';
    for (int k = 0; k < j; k++)
    {
        word[k] = temp_list[k];
    }
    return word;
}

int slice(char *word,int start,int end)
{
    char temp[MAX];
    int val = 0;
    for (int i = start;i < end+1;i++)
    {
        temp[val] = word[i];
        val += 1;
    }
    for (int j = 0;j < val;j++)
    {
        word[j] = temp[j];
    }
    return val;
}
