#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

int main(void)
{
    printf("FT = %i\nOR = %I64i", ft_strlen(""), strlen(""));
    return (0);
}