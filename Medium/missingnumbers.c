#include<stdio.h>

int main(void)
{
    int num_index;
    scanf("%i",&num_index);
    int new_num_index = num_index;
    int new_val = 0;
    int old_val = 0;
    int val = 0;
    int a = 0;
    int val2 = 0;
    int nos[500];
    for (int i = 0;i < num_index;i++)
    {
        scanf("%i",&new_val);
        if (new_val == old_val + 1 || i == 0)
        {
            nos[i + val2] = new_val;
        }
        else
        {
            a = old_val;
            for (int k = 0;k < new_val - (a + 1);k++)
            {
                old_val += 1;
                nos[i + k] = old_val;
                val2 = k + 1;
                new_num_index += 1;
            }
            nos[i+val2] = new_val;
        }
        old_val = new_val;
    }
    for (int j = 0;j < new_num_index;j++)
    {
        printf("%i\n",nos[j]);
    }
}
