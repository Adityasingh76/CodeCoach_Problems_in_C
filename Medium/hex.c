#include<stdio.h>
#include<string.h>

char *generate(int a,int b,int c);

int main(void)
{
	int a,b,c;
	scanf("%i %i %i",&a,&b,&c);
	generate(a,b,c);
}

char *generate(int a,int b,int c)
{
	char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	char d[5];
	char e[5];
	char f[5];
	int g = a/15;
	int h = b/15;
	int i = c/15;
	int j = a%15;
	int k = b%15;
	int l = c%15;
	if (g <= 16)
	{
		d[0] = hex[g];
	}
	if (h <= 16)
	{
		e[0] = hex[h];
	}
	if (i <= 16)
	{
		f[0] = hex[i];
	}
	d[1] = hex[j];
	e[1] = hex[k];
	f[1] = hex[l];
	printf("%s %s %s\n",d,e,f);
		
}
