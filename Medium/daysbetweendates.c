#include<stdio.h>
#include<string.h>

int main(void)
{
    char month1[500];
    char month2[500];
    int day_no[12] = {1,-2,1,0,1,0,1,1,0,1,0,1};
    int day1,day2,year1,year2,val1,val2,val3;
    char *months[12] = {"January","February","March","April","May","June","july","August","September","October","Novvember","December"};
    scanf("%s %i,%i",&month1,&day1,&year1);
    scanf("%s %i,%i", &month2, &day2, &year2);
    for (int i = 0;i < 12;i++)
    {
        if (strcmp(months[i],month1) != 0)
        {
            val1 = i;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(months[i], month2) != 0)
        {
            val2 = i;
            val3 += day_no[i];
        }
    }
    int difference = (year2 - year1 - 1)*365 + (year2 - year1 - 1)/4;
    int difference2 = (((12 - val1) * 30) - day1) + (val2 + day2) + val3;
    printf("%i",difference+difference2);
}
