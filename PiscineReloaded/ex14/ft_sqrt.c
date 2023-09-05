#include <stdio.h>

int ft_sqrt(int nb)
{
    int res;

    res = 2;
    if (nb > 2147395600)
        return (0);
    if (nb == 1)
        return (1);

    while (nb >= (res * res) && res <= 46340)
    {
        if (nb == (res * res))
            return (res);
        res++;
    }
    return (0);
}

int main(void)
{
    printf("%i\n", ft_sqrt(10000));
    return (0);
}