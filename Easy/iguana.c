#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int total_points = 0;
    char *items[] = {"Letuce","Mango","Cheeseburger","Carrot"};
    int points[] = {5,9,0,4};
    char *token = strtok(argv[1]," ");
    while (token != NULL)
    {
        for (int i = 0;i < 4;i++)
        {
            if (strcmp(token,items[i]) == 0)
            {
                total_points += points[i];
            }
        }
        token = strtok(NULL," ");
    }
    if (total_points > 10)
    {
        printf("Come on down!");
    }
    else{
        printf("Time to wait");
    }

}