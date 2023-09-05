#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    int count;

    count = -1;
    while (str[++count])
        ft_putchar(str[count]);
}

int main(void)
{
    ft_putstr("Hola Mundo");
    return (0);
}