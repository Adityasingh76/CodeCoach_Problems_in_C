#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int solve(char expression[],int index,int bracket)
{
    char new_expression[500];
    char signs[500];
    int val = 0;
    int val2 = 0;
    char *token;
    int first_no = 0;
    if (bracket == 1)
    {
        for (int i = 1;i < strlen(expression)-1;i++)
        {
            new_expression[i-1] = expression[i];
            if (expression[i] == '+')
            {
                signs[val] = '+';
                val += 1;
            }
            if (expression[i] == '-')
            {
                signs[val] = '-';
                val += 1;
            }
            if (expression[i] == '*')
            {
                signs[val] = '*';
                val += 1;
            }
            if (expression[i] == '/')
            {
                signs[val] = '/';
                val += 1;
            }
        }
    }
    if (bracket == 0)
    {
        for (int i = 0; i < strlen(expression); i++)
        {
            new_expression[i] = expression[i];
            if (expression[i] == '+')
            {
                signs[val] = '+';
                val += 1;
            }
            if (expression[i] == '-')
            {
                signs[val] = '-';
                val += 1;
            }
            if (expression[i] == '*')
            {
                signs[val] = '*';
                val += 1;
            }
            if (expression[i] == '/')
            {
                signs[val] = '/';
                val += 1;
            }
        }
    }
    if(signs[index] == '+')
    {
        token = strtok(new_expression, "+");
    }
    if (signs[index] == '-')
    {
        token = strtok(new_expression, "-");
    }
    if (signs[index] == '*')
    {
        token = strtok(new_expression, "*");
    }
    if (signs[index] == '/')
    {
        token = strtok(new_expression,"/");
    }
    if (val == 0)
    {
        return atoi(expression);
    }
    if (val > 1)
    {
        while (token != NULL)
        {
            if (val2 == 0)
            {
                first_no = atoi(token);
            }
            else
            {
                if (signs[index] == '+')
                {
                    first_no += solve(token,index,0);
                }
                if  (signs[index] == '-')
                {
                    first_no -= solve(token, index,0);
                }
                if (signs[index] == '*')
                {
                    first_no *= solve(token, index,0);
                }
                if (signs[index] == '/')
                {
                    first_no = first_no / solve(token, index,0);
                }
            }
            if (signs[index] == '+')
            {
                token = strtok(NULL, "+");
            }
            if (signs[index] == '-')
            {
                token = strtok(NULL, "-");
            }
            if (signs[index] == '*')
            {
                token = strtok(NULL, "*");
            }
            if (signs[index] == '/')
            {
                token = strtok(NULL, "/");
            }
            val2 += 1;
        }
    }
    if (val == 1)
    {
        while (token != NULL)
        {
            if (val2 == 0)
            {
                first_no = atoi(token);
            }
            else
            {
                if (signs[index] == '+')
                {
                    first_no += atoi(token);
                }
                if (signs[index] == '-')
                {
                    first_no -= atoi(token);
                }
                if (signs[index] == '*')
                {
                    first_no *= atoi(token);
                }
                if (signs[index] == '/')
                {
                    first_no /= atoi(token);
                }
            }
            if (signs[index] == '+')
            {
                token = strtok(NULL, "+");
            }
            if (signs[index] == '-')
            {
                token = strtok(NULL, "-");
            }
            if (signs[index] == '*')
            {
                token = strtok(NULL, "*");
            }
            if (signs[index] == '/')
            {
                token = strtok(NULL, "/");
            }
            val2 += 1;
        }
    }
    return first_no;
}

int main(void)
{
    char expression[500];
    int answer = 15;
    int val = 0;
    int result = 0;
    char *token = strtok(expression," ");
    while (token != NULL)
    {
        result = solve(token,0,1);
        if (result == answer)
        {
            printf("Index: %i",val);
            return 0;
        }
        val += 1;
        token = strtok(NULL," ");
    }
    printf("None");
}
