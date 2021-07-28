#include<stdio.h>

#define cost 21000000
#define price 3000000

int main(void)
{
    int no_of_hovercraft;
    printf("No. of Hovercrafts sold: ");
    scanf("%i",&no_of_hovercraft);
    int val = no_of_hovercraft * price;
    if ((val == cost) == 1)
    {
        printf("broke even");
    }
    if (val > cost)
    {
        printf("profit");
    }
    else if (val < cost){
        printf("loss");
    }
    
}
