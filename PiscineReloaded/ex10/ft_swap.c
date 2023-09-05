#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int num;
    int num2;

    num = 1;
    num2 = 2;
    printf("%i, %i\n", num, num2);
    ft_swap(&num, &num2);
    printf("%i, %i\n", num, num2);
    return (0);
}