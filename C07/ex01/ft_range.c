#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int count;
    int *range;

    if (min >= max)
        return (0);
    range = (int *)malloc((max - min * sizeof(int)));
    if (!range)
        return (0);
    count = -1;
    while (min <= max)
        range[++count] = min++;
    return (range);
}

int main()
{
    int *a = ft_range(2, 8);
    printf("%i %i %i %i %i %i\n", a[0], a[1], a[2], a[3], a[4], a[5]);
    return 0;
}