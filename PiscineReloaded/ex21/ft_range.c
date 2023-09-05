#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int *arr;
    int count;

    count = -1;
    if (min >= max)
        return (0);
    arr = (int *)malloc((max - min) * sizeof(int));
    if (!arr)
        return (0);
    while (min < max)
        arr[++count] = min++;
    return (arr);
}

int main(void)
{
    int count = -1;
    int *nums = ft_range(5, 10);
    while (++count < 5)
        printf("%d,", nums[count]);
    return (0);
}