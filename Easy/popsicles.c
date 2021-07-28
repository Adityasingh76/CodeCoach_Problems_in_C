#include<stdio.h>

int main(void)
{
    int no_of_siblings,no_of_popsicles;
    printf("No. of Siblings: ");
    scanf("%i",&no_of_siblings);
    printf("NO. of Popsicles: ");
    scanf("%i",&no_of_popsicles);
    if (no_of_popsicles%no_of_siblings == 0)
    {
        printf("Give away");
    }
    else
    {
        printf("Eat it yourself.");
    }
}