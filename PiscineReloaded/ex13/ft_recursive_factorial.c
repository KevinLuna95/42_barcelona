#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    if (nb > 12)
        return (0);
    if (nb >= 1)
        return (nb * ft_recursive_factorial(nb - 1));
    else
        return (1);
}

int main(void)
{
    printf("%i\n", ft_recursive_factorial(2));
    return (0);
}