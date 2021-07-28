#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define trip_time 10
int main(int argc,char *argv[])
{
    int no_of_people = atoi(argv[1]);
    if (no_of_people > 20 && no_of_people % 20 != 0)
    {
        int total_time = (((int)no_of_people / 20) * 20) + 10;
        printf("%i",total_time);
    }
    else if (no_of_people > 20 && no_of_people % 20 == 0)
    {
        int total_time = ((((int)no_of_people / 20) - 1) * 20) + 10;
        printf("%i",total_time);
    }
    else{
        printf("%i",10);
    }
}