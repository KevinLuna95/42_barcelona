#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
    int count;
    char *str_dup;
    count = 0;
    while (src[count])
        count++;
    str_dup = (char *)malloc(count * sizeof(char));
    if (!str_dup || count == 0)
        return (0);
    while (--count > -1)
        str_dup[count] = src[count];
    return (str_dup);
}

int main(void)
{
    printf("%s\n", ft_strdup(""));
    printf("%s\n", strdup(""));
    return (0);
}