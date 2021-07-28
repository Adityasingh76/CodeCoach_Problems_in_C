#include<stdio.h>
#include<string.h>

char *generate(int a,int b,int c);

int main(void)
{
    int red,green,blue;
    scanf("%i %i %i",&red,&green,&blue);
    generate(red,green,blue);
}

char *generate(int a,int b,int c)
{
    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char hex_red[500];
    char hex_green[500];
    char hex_blue[500];
    int d = a/15;
    int e = b/15;
    int f = c/15;
    int g = a%15;
    int h = b%15;
    int i = c%15;
    if (d <= 16 && e <= 16 && f <= 16)
    {
        hex_red[0] = hex[d-1];
        hex_green[0] = hex[e-1];
        hex_blue[0] = hex[f-1];
    }
    hex_red[1] = hex[g];
    hex_green[1] = hex[h];
    hex_blue[1] = hex[i];
    printf("%s5%s5%s\n",hex_red,hex_green,hex_blue);
}
