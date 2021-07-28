#include<stdio.h>
#include<math.h>

#define MAX 8
int main(void)
{
    int binary[MAX] = {0,0,0,0,0,0,0,0};
    int number;
    int val = 1;
    int  i =0;
    int no_of_ones = 0;
    scanf("%i",&number);
    if (number < 257)
    {
        while (val != 0)
        {
            if (number == 0)
            {
                val = 0;
            }
            if (pow(2,i) > number)
            {
                binary[i-1] = 1; 
                number = number - pow(2,i-1);
                i = -1;
            }
            i += 1;
        }
        for (int v =0;v<8;v++)
        {
            if (binary[v] == 1)
            {
                no_of_ones += 1;
            }
            else
            {
                ;
            }
        }
        printf("%i",no_of_ones);
    }
    else
    {
        printf("You can only count as high as 256 in 8 bits!");
    }
}