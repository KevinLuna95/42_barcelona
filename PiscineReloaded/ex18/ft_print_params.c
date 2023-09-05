#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int c1;
    int c2;

    c1 = 0;
    c2 = -1;
    while (++c1 <= argc - 1)
    {
        while (argv[c1][++c2])
            ft_putchar(argv[c1][c2]);
        ft_putchar('\n');
        c2 = -1;
    }
}