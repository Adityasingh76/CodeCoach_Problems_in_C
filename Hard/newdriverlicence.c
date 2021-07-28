#include<stdio.h>
#include<string.h>
#include<math.h>

char** sort(char *list[],int index);

int main(void)
{
    char own_name[500];
    char other_names[500];
    char *names[500];
    int no_of_agents = 0;
    int i = 0;
    scanf("%s",&own_name);
    scanf("%[^\n]%*c",&other_names);
    scanf("%i",&no_of_agents);
    char *token = strtok(other_names," ");
    while (token != NULL)
    {
        names[i] = token;
        token = strtok(NULL," ");
        i++;
    }
    names[i+1] = own_name;
    sort(names,i+1);
    for (int j = 0;j < i+2;j++)
    {
        if (strcmp(own_name,names[j]) == 0)
        {
            printf("%i",((j/no_of_agents)+1)*20);
        }
    }
}

char** swipe(char *list[],int index1,int index2)
{
    char *temp;
    if ((int)list[index1][index2] == (int)list[index1+1][index2])
    {
        swipe(list,index1,index2+1);
    }
    else if ((int)list[index1][index2] > (int)list[index1 + 1][index2])
    {
        temp = list[index1];
        list[index1] = list[index1+1];
        list[index1+1] = temp;
    }
    return list;
}

char** sort(char *list[],int index)
{
    char temp;
    for (int l = 0;l < index;l++)
    {
        for (int k = 0;k < index;k++)
        {
            swipe(list,k,0);
        }
    }
    return list;
}
