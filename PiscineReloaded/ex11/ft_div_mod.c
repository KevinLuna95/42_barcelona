#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

int main(void)
{
    int mod;
    int div;

    mod = 0;
    div = 0;
    ft_div_mod(11, 2, &div, &mod);
    printf("mod: %i, div: %i\n", mod, div);
    return (0);
}