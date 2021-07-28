#include<stdio.h>

#define price 5
#define tax 0.07
#define discount 0.1

int main(void)
{
    int no_of_kaliedoscopes;
    printf("No of kaliedoscopes bought: ");
    scanf("%i",&no_of_kaliedoscopes);
    if (no_of_kaliedoscopes > 1)
    {
        float total_cost = (no_of_kaliedoscopes * price - no_of_kaliedoscopes * price * discount);
        float totalcost = total_cost + total_cost * tax;
        printf("%f",totalcost);
    }
    else
    {
        float total_cost = no_of_kaliedoscopes * price + no_of_kaliedoscopes * price * tax;
        printf("%f",total_cost);
    }
}