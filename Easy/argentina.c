#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int price_in_dollar,price_in_pesos;
    printf("Price in dollars: ");
    scanf("%i",&price_in_dollar);
    printf("Price in Pesos: ");
    scanf("%i",&price_in_pesos);
    if (price_in_pesos/50 < price_in_dollar)
    {
        printf("pesos");
    }
    if (price_in_pesos/50 == price_in_dollar)
    {
        printf("both prices are equal.");
    }
    if (price_in_pesos/50 > price_in_dollar)
    {
        printf("dollars");
    }
    return 0;

}