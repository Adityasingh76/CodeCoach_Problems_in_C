#include<stdio.h>
#include<string.h>

int royal_flush(char cards[],int val1,int val);
int straight_flush(char cards[],int val1,int val);
int four_of_kind(char cards[]);
int two_pairs(char cards[]);
int one_pair(char cards[]);
int three_of_kind(char cards[]);
int full_house(char cards[]);
int kind(char cards[]);
int pair(char cards[]);
char *sort(char *list, int index);
int flush(char suits[]);
int straight(char cards[]);

int main(void)
{
    char cards1[500];
    printf("Enter the cards: ");
    scanf("%[^\n]%*C",&cards1);
    char suits[500];
    char cards[500];
    int val = 0;
    int val1 = 1;
    char *token = strtok(cards1, " ");
    while (token != NULL)
    {
        if (val > 0)
        {
            if (suits[val - 1] == token[1])
            {
                val1 += 1;
            }
        }
        if (token[1] == '0')
        {
            suits[val] = token[2];
            cards[val] = token[1];
        }
        if (token[1] != '0')
        {
            suits[val] = token[1];
            cards[val] = token[0];
        }
        val += 1;
        token = strtok(NULL, " ");
    }
    printf("%i\n",royal_flush(cards,val1,val));
    if (royal_flush(cards,val1,val) == 0)
    {
        printf("Royal FLush");
        return 0;
    }
    if (straight_flush(cards,val1,val) == 0)
    {
        printf("Straight_Flush");
        return 0;
    }
    if (four_of_kind(cards) == 0)
    {
        printf("Four of a Kind");
        return 0;
    }
    if (full_house(cards) == 0)
    {
        printf("Full House");
        return 0;
    }
    if (flush(cards) == 0)
    {
        printf("Flush");
        return 0;
    }
    if (straight(cards) == 0)
    {
        printf("Straight");
        return 0;
    }
    if (three_of_kind(cards) == 0)
    {
        printf("Three of a Kind");
        return 0;
    }
    if (two_pairs(cards) == 0)
    {
        printf("Two Pairs");
        return 0;
    }
    if (one_pair(cards) == 0)
    {
        printf("One Pair");
        return 0;
    }
    printf("High Card");
    return 0;

}

int pair(char cards[])
{
    char *a = sort(cards,5);
    int val2 = 0;
    for (int i = 0; i < 4; i++)
    {   
        if (i > 0)
        {
            if (cards[i] == cards[i+1] && cards[i] != cards[i-1])
            {
                val2 += 1;
            }
        }
        if (i == 0)
        {
            if (cards[i] == cards[i+1])
            {
                val2 += 1;
            }
        }
    }
    return val2;
}

int one_pair(char cards[])
{
    if (pair(cards) == 1)
    {
        return 0;
    }
    return 1;
}

int two_pairs(char cards[])
{
    if (pair(cards) == 2)
    {
        return 0;
    }
    return 1;
}

int flush(char suits[])
{
    int val2 = 1;
    for (int i = 0;i < 4;i++)
    {
        if (suits[i] == suits[i+1])
        {
            val2 += 1;
        }
    }
    if (val2 == 5)
    {
        return 0;
    }
    return 1;
}

int straight(char cards[])
{
    int val2 = 1;
    for (int i = 0; i < 4; i++)
    {
        if (cards[i] != '9' && cards[i] != '0' && cards[i] != 'J' && cards[i] != 'K' && cards[i] != 'A' && cards[i] != 'Q')
        {
            if (cards[i] = cards[i + 1] - 1)
            {
                val2 += 1;
            }
        }
        if (cards[i] == '9')
        {
            if (cards[i + 1] == '0')
            {
                val2 += 1;
            }
        }
        if (cards[i] == '0')
        {
            if (cards[i + 1] == 'J')
            {
                val2 += 1;
            }
        }
        if (cards[i] == 'J')
        {
            if (cards[i + 1] == 'Q')
            {
                val2 += 1;
            }
        }
        if (cards[i] == 'Q')
        {
            if (cards[i + 1] == 'K')
            {
                val2 += 1;
            }
        }
        if (cards[i] == 'K')
        {
            if (cards[i + 1] == 'A')
            {
                val2 += 1;
            }
        }
    }
    if (val2 == 5)
    {
        return 0;
    }
    return 1;
}

char *pop(char word[],char empty_lst[], char to_remove, int index)
{
    char temp_list[index];
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        if (word[i] != to_remove)
        {
            temp_list[j] = word[i];
            j += 1;
        }
    }
    temp_list[j] = '\0';
    for (int k = 0; k < j; k++)
    {
        empty_lst[k] = temp_list[k];
    }
    return empty_lst;
}

int royal_flush(char cards[],int val1,int val)
{
    int val2 = 0;
    int val3 = 5;
    char empty_lst[500];
    char *a = sort(cards,5);
    if (val1 == val)
    {
        for (int i = 0;i < 5;i++)
        {
            if (cards[i] == '0' && cards[i+1] == 'A')
            {
                printf("1");
                val2 += 1;
            }
            if (cards[i] == 'A' && cards[i + 1] == 'J' && cards[i-1] == '0')
            {
                printf("2");
                val2 += 1;
            }
            if (cards[i] == 'J' && cards[i + 1] == 'K' && cards[i - 1] == 'A')
            {
                printf("3");
                val2 += 1;
            }
            if (cards[i] == 'K' && cards[i + 1] == 'Q' && cards[i - 1] == 'J')
            {
                printf("4");
                val2 += 1;
            }
        }
    }
    if (val2 == 4)
    {
        return 0;
    }
    return 1;
}

int straight_flush(char cards[],int val1,int val)
{
    int val3 = 0;
    if (val1 == val)
    {
        int val2 = straight(cards);
        return val2;
    }
}

int kind(char cards[])
{
    int val2 = 1;
    char *a = sort(cards,5);
    int val3 = 0;
    int empty_lst[500];
    int val = 0;
    for (int i = 0; i < 4;i++)
    {
        if (cards[i] != cards[i+1])
        {
            empty_lst[val] = val2;
            val2 = 1;
            val += 1;
        }
        if (cards[i] == cards[i+1])
        {
            val2 += 1;
        }
    }
    empty_lst[val] = val2;
    val += 1;
    val3 = empty_lst[0];
    for (int i = 0; i < val-1; i++)
    {
        if (empty_lst[i + 1] > val3)
        {
            val3 = empty_lst[i + 1];
        }
    }
    return val3;
}

int four_of_kind(char cards[])
{
    if (kind(cards) == 4)
    {
        return 0;
    }
    return 1;
}
int three_of_kind(char cards[])
{
    if (kind(cards) == 3)
    {
        return 0;
    }
    return 1;
}

int full_house(char cards[])
{
    int lst[5];
    int val = kind(cards);
    int val1 = pair(cards);
    int val2 = lst[0];
    
    if (val == 3)
    {
        if (val1 == 1)
        {
            return 0;
        }
    }
    return 1;
}

char *sort(char *list, int index)
{
    char temp;
    for (int l = 0; l < index; l++)
    {
        for (int k = 0; k < index - 1; k++)
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
