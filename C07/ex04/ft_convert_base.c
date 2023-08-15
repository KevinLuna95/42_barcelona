#include <stdio.h>

char *ft_atoi(char *str, char *base, int *c_sign);
int check_base(char *base);
char *ft_strcat(char *dest, char *src, char *base);
int num_in_base(char num, char *base);
int ft_recursive_power(int nb, int power);

int nbr_base_to_dec(char *nbr, char *base, int *c_sign)
{
    int dec;
    char str[11];
    int size_num;
    int count;

    size_num = 0;
    count = -1;
    ft_strcat(str, ft_atoi(nbr, base, c_sign), base);
    while (nbr[size_num])
        size_num++;
    while (size_num >= 0)
    {
        dec += (ft_recursive_power(check_base(base), --size_num) * num_in_base(nbr[++count], base));
    }
    return (dec);
}

int ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int size_from;
    int size_to;
    int c_sign;

    size_from = check_base(base_from);
    size_to = check_base(base_to);
    c_sign = 0;
    printf("sizeFrom: %i, sizeTo: %i\n", size_from, size_to);
    if (size_from == 0 && size_to == 0)
        return (0);
    return (nbr_base_to_dec(nbr, base_from, &c_sign));
}

int ft_recursive_power(int nb, int power)
{

    if (power == 0)
        return (1);
    else if (power > 1)
        return (nb * ft_recursive_power(nb, --power));
    else
        return (nb);
}

int main()
{
    printf("%d\n", ft_convert_base("2492", "01234567", "012345"));
    return (0);
}