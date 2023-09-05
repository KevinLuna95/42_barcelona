#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    int count;

    count = -1;
    while (s1[++count] && s2[++count])
    {
        if (s1[count] != s2[count])
            return (s1[count] - s2[count]);
    }
    if (s1[count] != s2[count])
        return (s1[count] - s2[count]);
    return (0);
}

int main(void)
{
    printf("FT = %i\nOR = %i", ft_strcmp("hola", "hole"), strcmp("hola", "hole"));
    return (0);
}