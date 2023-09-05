#include <stdio.h>

void ft_ft(int *nbr)
{
    *nbr = 42;
}

int main(void)
{
    int num;

    num = 0;
    ft_ft(&num);
    printf("%i", num);
    return (0);
}