#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 500

char *sort(char *list, int index);
int clean(char *list, int index);
char *pop(char word[], char to_remove, int index);
int letter_rank(char *word, char letter, int index);
int slice(char *word, int start, int end);
int factorial(int no);
int word_rank_no_repetition(char word[], int len, int *rank);
int word_rank_repetition(char word[], int len, int *rank);
int repetition_checker(char word[], char lst[], int index_lst[], int index);
int to_upper(char word[], int len);

int main()
{
    char a[MAX]; // initialising the variables for storing the input.
    char c[MAX];
    scanf("%s", &c);
    to_upper(c, strlen(c)); // converting the given string to uppercase.
    strcpy(a, c);           // creating a copy of string for future use.
    int rank = 0;
    int index_lst[MAX];
    char repeated_words[MAX];
    char *b = sort(c, strlen(c)); // sorting the string in alphabetical order.
    int index = repetition_checker(b, repeated_words, index_lst, strlen(a)); // checking the given word for repetitions.
    if (index == -1) // if there are no repetitions then calling the wordrank function without repetitions
    {
        word_rank_no_repetition(a, strlen(a), &rank);
    }
    if (index > -1) // otherwise without repetitions.
    {
        word_rank_repetition(a, strlen(a), &rank);
    }
    printf("%i", rank); // displaying the rank
}

int word_rank_repetition(char word[], int len, int *rank)
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
    char initial_word[MAX]; // initializing variables for later use.
    char repeated_words[MAX];
    int index_lst[MAX];
    float val = 1;
    strcpy(initial_word, word);
    char *cleaned = sort(word, len); // sorting the given word in alphabetical order.
    char sorted[MAX];
    strcpy(sorted, cleaned);
    int new_len = clean(cleaned, len);                                      // removing all the repetitions from the given word.
    float letterrank = letter_rank(sorted, initial_word[0], len);           // finding the rank of first letter in the original word in the sorted word.
    int index = repetition_checker(sorted, repeated_words, index_lst, len); // checking for the repetitions in the sorted word.
    /* here we are using the formula
    total number of combinations made by the first letter = rank of given letter in sorted word/product of factorials of all repetitions after the letter in original word including the given letter*factorial of rank of letter from the end in the original word.
    */
    for (int k = 0; k < index + 1; k++)
    {
        val *= factorial(index_lst[k]);
    }
    float pre_answer = letterrank / val;
    float answer = pre_answer * factorial(len - 1);
    *rank += answer;
    int sliced = slice(initial_word, 1, len);             // removing the first letter from the given word
    word_rank_repetition(initial_word, sliced - 1, rank); // recalling the function with sliced word to get the next combinations
    /* here we are using the recursion method to find all the combinations that can be made with the given letters
    we call the function then after getting all the combinations made by first letter we remove it and again call the function
    and we do it until only two letters are left in the word after which the recursion stops.
    */
    return 0;
}

int word_rank_no_repetition(char word[], int len, int *rank)
{
    if (len == 2) // if the given word is of length 2
    {
        char temp[MAX];
        strcpy(temp, word);
        char *temp1 = sort(word, 2);  // sorting the word.
        if (strcmp(temp, temp1) == 0) // if the original word equals the sorted word then the word rank is 1.
        {
            *rank += 1;
        }
        else // otherwise the word rank of original word is 2 as sorted word holds the first rank.
        {
            *rank += 2;
        }
        return 0;
    }
    char initial_word[MAX];
    strcpy(initial_word, word);      // making the copy of original word for later use.
    char *cleaned = sort(word, len); // sorting the word.
    char sorted[MAX];
    strcpy(sorted, cleaned);                                         // again making the copy of sorted word for later use.
    int new_len = clean(cleaned, len);                               // removing all the repetitions from the word.
    int letterrank = letter_rank(cleaned, initial_word[0], new_len); // finding the rank of first letter in the initial word.
    /*
    applying the formula
    no of combinations of word with or without meaning = rank of the letter in all letters of the word * factorial of rank of letter in the original word from the end of the word
    */
    int answer = letterrank * factorial(new_len - 1);
    *rank += answer; // adding the rank = total number of combinations
    int sliced = slice(initial_word, 1, len);                // removing the first letter from the given word and
    word_rank_no_repetition(initial_word, sliced - 1, rank); // recallign the function with sliced word to get the next combinations.
    return 0;
    /* here we are using the recursion method to find all the combinations that can be made with the given letters
    we call the function then after getting all the combinations made by first letter we remove it and again call the function
    and we do it until only two letters are left in the word after which the recursion stops.
    */
}

char *sort(char *list, int index) // using binary sort to sort the given string in alphabetical order.
{
    char temp;
    for (int l = 0; l < index; l++) // first level iteration.
    {
        for (int k = 0; k < index - 1; k++) // second level iteration
        {
            if (list[k] > list[k + 1]) // if the given character comes after the next character then swap the two characters.
            {
                temp = list[k];
                list[k] = list[k + 1];
                list[k + 1] = temp;
            }
        }
    }
    return list;
}

int to_upper(char word[], int len) // to make the whole string in uppercase.
{
    for (int i = 0; i < len; i++)
    {
        if (word[i] < 123 && word[i] > 96) // if the character is in lowercase.
        {
            word[i] = word[i] - 32; // find the corresponding uppercase letter using the ASCII conversion.
        }
    }
    return 0;
}

int repetition_checker(char word[], char lst[], int index_lst[], int index)
{
    int val = 0; // initialising necessary variables
    int j = 0;
    for (int i = 0; i < index; i++) // iterating through the given word.
    {
        if (word[i] == word[i + 1] && word[i] != word[i - 1]) // if for given character the next character is same and previous character is not same.
        {
            j = i;                     // setting up j for next loop
            while (word[j] == word[i]) // iterating through the word until another character is found.
            {
                j += 1;
            }
            index_lst[val] = j - i; // getting the number of times the given character repeated.
            j = 0;                  // resetting j.
            lst[val] = word[i];     // setting the given character in the repeated word lst.
            val += 1;               // incrementing value of val by 1 to get the number of characters that repeated.
        }
    }
    lst[val] = '\0'; // setting up null character to end the list.
    return val - 1;
}

int clean(char *list, int index) // for removing any repetitions of letters from the given string.(only pass the sorted string to this function)
{
    int val = 0;
    char temp_list[index]; // temporary list for storage of cleaned word.
    for (int i = 0; i < index + 1; i++)
    {
        if (list[i] != list[i + 1]) // adding only those letters to the temporary list whose next letter is not same
        {                           // this means for repeated letters the last letter will be added to the temporary list and others will be neglected.
            temp_list[val] = list[i];
            val += 1;
        }
    }
    for (int y = 0; y < val + 1; y++)
    {
        list[y] = temp_list[y]; // resetting the original string with temporary list
    }
    return val; // returning the length of the cleaned word.
}

int letter_rank(char *word, char letter, int index) // to find the rank of a letter in a given word.
{
    int val = 0;
    for (int i = 0; i < index; i++) // iterating through the given word.
    {
        if (word[i] == letter) // if the current character of the word matches with the given character.
        {
            return val; // return the index of that character.
        }
        val += 1;
    }
    return 0;
}

int factorial(int no) // for factorial ofa  given number.
{
    int result = 1;
    for (int i = 1; i < no + 1; i++) // iterating through all natural numbers till given number.
    {
        result = result * i; // multiplying all the numbers till given number.
    }
    return result;
}

char *pop(char word[], char to_remove, int index) // to remove a given character for a given list of char.
{
    char temp_list[index]; // creating a new char list to store the given word temporarily.
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        if (word[i] != to_remove) // adding the characters from the word to temporary list only if the don't match the character to be removed.
        {
            temp_list[j++] = word[i];
        }
    }
    temp_list[j] = '\0'; // completing the temporary list by adding the null character.
    for (int k = 0; k < j; k++)
    {
        word[k] = temp_list[k]; // resetting the original word using the temporary list with given character removed.
    }
    return word;
}

int slice(char *word, int start, int end)
{
    char temp[MAX]; // temporary list for storing the sliced string
    int val = 0;
    for (int i = start; i < end + 1; i++)
    {
        temp[val] = word[i]; // adding only those characters to the temporary list which are in the given bounds
        val += 1;
    }
    for (int j = 0; j < val; j++)
    {
        word[j] = temp[j]; // resetting the original string with temporary list.
    }
    return val; // returning the length of the sliced string.
}
