#include<stdio.h>
#include<math.h>

int main(void)
{
    int no_of_fruits;
    printf("No. of fruits: ");
    scanf("%d",&no_of_fruits);
    int no_of_pies = (no_of_fruits/2)/3;
    printf("%i",no_of_pies);
}