#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int count;
    int all_size;
    char *dest;

    count = -1;
    all_size = 0;
    if (size == 0)
        return (dest = (char *)malloc(sizeof(char)));
    while (++count < size)
        all_size += ft_strlen(strs[count]);
    dest = (char *)malloc((all_size + (ft_strlen(sep) * size - 1)) * sizeof(char));
    // falta hacer la concatenación.
}

int main(void)
{
    char *tab[4];
    tab[0] = " ";
    tab[1] = " ";
    tab[2] = " ";
    tab[3] = " ";
    printf("%s", ft_strjoin(4, tab, "Pasquale"));
    return (0);
}