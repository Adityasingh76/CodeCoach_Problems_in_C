#include<stdio.h>
#include<stdlib.h>

int count(int no);
int* split(int no,int lst[],int index,int len);

int a=10000,b,c=8400,d,e,f[8401],g,i,k,index1,len;
int pi[25000];
int main()
{ 
    for(;b-c;){f[b++]=a/5;}
    for(;d=0,g=c*2;c-=14,k=e+d/a,e=d%a,len=count(k),split(k,pi,index1,len),i++,index1+=len) 
    for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b);
    int k = 0;
    printf("Index: ");
    scanf("%i",&k);
    if (k >= 0 && k < 1001)
    {
        printf("%i",pi[k]);
    }
}

int count(int no)
{
    int count = 0;
    while (no!=0)
    {
        no = no/10;
        count++;
    }
    return count;
}

int* split(int no,int lst[],int index,int len)
{
    char a[500];
    itoa(no,a,10);
    for (int k = 0;k < len;k++)
    {
        lst[index+k] = ((int)a[k])-48;
    }
    return lst;
}
