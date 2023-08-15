#include <stdio.h>

char *ft_atoi(char *str, char *base, int *c_sign);
int check_base(char *base);
char *ft_strcat(char *dest, char *src, char *base);
int num_in_base(char num, char *base);
int ft_recursive_power_or_f(int nb, int power, char ft, int res);
char *ft_putnbr_base(int nbr, char *base);

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
        dec += (ft_recursive_power_or_f(check_base(base), --size_num, 'P', 0) * num_in_base(nbr[++count], base));
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

int ft_recursive_power_or_f(int nb, int power, char ft, int res)
{
    if (ft == 'F')
    {
    }
    else
    {
        if (power == 0)
            return (1);
        else if (power > 1)
            return (nb * ft_recursive_power_or_f(nb, --power, ft, 0));
        else
            return (nb);
    }
}

int is_diferent(char *base, int size)
{
    int count;
    int c_base;

    count = -1;
    c_base = 0;
    while (++count < size)
    {
        while (c_base < size)
        {
            if (base[count] == base[++c_base])
                return (0);
        }
        c_base = 1 + count;
    }
    return (1);
}

void rec_nb(int num, char *base, int size)
{
    int mod;

    mod = num % size;
    num /= size;
    if (num != 0)
        rec_nb(num, base, size);
    if (mod < 0)
        mod *= -1;
    write(1, &base[mod], 1);
}

char *ft_putnbr_base(int nbr, char *base)
{
    int count;
    char *str_num;

    count = -1;
    str_num = (char *)malloc(ft_recursive_power_or_f(nbr, 0, 'F', 0));
    while (base[++count])
    {
        if (base[count] == '+' || base[count] == '-')
            return;
    }
    if (count > 1 && is_diferent(base, count))
    {
        if (nbr < 0)
            write(1, "-", 1);
        rec_nb(nbr, base, count);
    }
}

int main()
{
    printf("%d\n", ft_convert_base("  2432", "01234567", "012345"));
    return (0);
}