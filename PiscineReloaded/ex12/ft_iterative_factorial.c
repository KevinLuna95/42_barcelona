#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    if (nb > 12)
        return (0);
    int res;

    res = nb;
    while (nb > 1)
        res *= --nb;
    return (res);
}

int main(void)
{
    printf("%i\n", ft_iterative_factorial(12));
    return (0);
}