#include<stdio.h>
#include<math.h>

#define tape_area 12*60*2
int main(void)
{
    int height,width;
    printf("Height: ");
    scanf("%i",&height);
    printf("Width: ");
    scanf("%i",&width);
    printf("%d\n",(int)ceil((height*width)/5.0));
}