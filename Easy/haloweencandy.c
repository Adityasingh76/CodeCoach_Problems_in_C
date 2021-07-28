#include<stdio.h>
#include<math.h>

# define dollarbills 2
# define toothbrush 1
#define candy 1
int main(void)
{
    int no_of_houses;
    printf("NO. of houses: ");
    scanf("%i", &no_of_houses);
    int percentage = (int)ceil(100*2.0 / no_of_houses);
    printf("%d",percentage);
    return 0;
    
}