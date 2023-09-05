#include <unistd.h>

void ft_print_alphabet(void)
{
    char letter;

    letter = 'a' - 1;
    while (++letter <= 'z')
    {
        write(1, &letter, 1);
        write(1, "\n", 1);
    }
}

int main(void)
{
    ft_print_alphabet();
    return (0);
}