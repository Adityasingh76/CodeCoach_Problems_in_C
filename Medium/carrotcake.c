#include<stdio.h>

void main(void)
{
    int no_of_carrots,no_of_boxes;
    scanf("%i %i",&no_of_carrots,&no_of_boxes);
    if (no_of_carrots % no_of_boxes == 0)
    {
        printf("I need to buy 7 carrots more.");
        return;
    }
    if (no_of_carrots % no_of_boxes < 7)
    {
        printf("I need to buy %i carrots more.",7 - (no_of_carrots % no_of_boxes));
        return;
    }
    else
    {
        printf("Cake time");
    }
}
