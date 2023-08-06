#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
    int size;
    int count;
    char *dup_str;

    size = 0;
    count = -1;
    while (src[size])
        size++;

    dup_str = (char *)malloc(size * sizeof(char));

    if (!dup_str)
        return ('\0');
    while (src[++count])
        dup_str[count] = src[count];
    dup_str[count] = '\0';
    return (dup_str);
}

int main()
{
    char *str = ft_strdup("Esto es la leche porque me permite inizializar cosas facil");

    printf("%s\n", str);
}