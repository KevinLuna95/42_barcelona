#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
    {
        count++;
    }
    return (count);
}
int ft_cpy(char *dest, char *strs, int count)
{
    int c_str;

    c_str = -1;
    while (strs[++c_str])
        dest[count++] = strs[c_str];
    return (count);
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    char *dest;
    int count;
    int all_size;
    int c_size;

    count = -1;
    all_size = 0;
    c_size = -1;
    if (size == 0)
        return (dest = (char *)malloc(sizeof(char)));
    while (++count < size)
        all_size += ft_strlen(strs[count]);
    dest = (char *)malloc((all_size + (ft_strlen(sep) * size - 1)) * sizeof(char));
    if (!dest)
        return (0);
    count = 0;
    while (++c_size < size)
    {
        count = ft_cpy(dest, strs[c_size], count);
        if (!(c_size == size - 1))
            count = ft_cpy(dest, sep, count);
    }
    return (dest);
}

int main(void)
{
    char *tab[4];
    tab[0] = "Hola";
    tab[1] = "soy";
    tab[2] = "yo";
    tab[3] = "kevin";
    printf("%s", ft_strjoin(4, tab, " "));
    return (0);
}