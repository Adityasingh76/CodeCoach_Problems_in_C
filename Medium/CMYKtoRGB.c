#include<stdio.h>
#include<math.h>

int main(void)
{
    float cyan,magnetta,yellow,black;
    scanf("%f,%f,%f,%f",&cyan,&magnetta,&yellow,&black);
    float R = ceil(255 * (1 - cyan) * (1 - black));
    float G = ceil(255 * (1 - magnetta)* (1 - black));
    float B = ceil(255 * (1 -yellow) * (1 - black));
    printf("%i,%i,%i",R,G,B);
}
