#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int count;

    count = -1;
    while (s1[++count] && s2[count])
    {
        if (s1[count] != s2[count])
            return (s1[count] - s2[count]);
    }
    if (s1[count] != s2[count])
        return (s1[count] - s2[count]);
    return (0);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strcpy(char *dest, char *src)
{
    int count;

    count = 0;
    while (src[count] != '\0')
    {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return (dest);
}
void print_params(int argc, char *argv[])
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
int main(int argc, char *argv[])
{
    int c1;
    int c2;
    char tmp[100];

    c1 = 0;
    c2 = 1;
    while (++c1 < argc)
    {
        while (++c2 < argc)
        {
            if (ft_strcmp(argv[c1], argv[c2]) > 0)
            {
                ft_strcpy(tmp, argv[c1]);
                ft_strcpy(argv[c1], argv[c2]);
                ft_strcpy(argv[c2], tmp);
            }
        }
        c2 = c1 + 1;
    }
    print_params(argc, &*argv);
}