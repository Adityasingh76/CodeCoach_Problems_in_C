#include<stdio.h>
#include<math.h>

#define distance_apart 50

int main(void)
{
    int a,b,c;
    scanf("%i %i %i",&a,&b,&c);
    if ((b/a)*c > 50)
    {
        printf("Yum");
    }
    else{
        printf("meep meep");
    }
}