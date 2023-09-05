#include <unistd.h>

void ft_print_numbers(void)
{
    char num;

    num = '0' - 1;
    while (++num <= '9')
        write(1, &num, 1);
}

int main(void)
{
    ft_print_numbers();
    return (0);
}