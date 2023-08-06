#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int count;

    if (min >= max)
        return (0);
    range = (int **)malloc((max + 1 - min) * sizeof(int *));
    if (!range)
        return (-1);
    count = -1;
    while (min < max)
    {
        range[++count] = (int *)malloc(sizeof(int));
        if (!range[count])
            return (-1);
        *range[count] = min++;
    }
    return (count + 1);
}