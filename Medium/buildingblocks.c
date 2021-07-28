#include<stdio.h>

void main(void)
{
    int red,green,blue,yellow;
    scanf("%i %i %i %i",&red,&green,&blue,&yellow);
    printf("%i",(yellow+red+green+blue)%15);
}
