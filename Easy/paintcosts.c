#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define canvas_cost 40
#define tax 0.1
int main(int argc,char*argv[])
{
    int total_cost = (atoi(argv[1]) *5) + canvas_cost;
    total_cost = total_cost + total_cost * tax;
    printf("%i",total_cost);

}