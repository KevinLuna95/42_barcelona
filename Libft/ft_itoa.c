#include <stdlib.h>
#include <stdio.h>

static char *printstr(int n, char *res, int size, int neg)
{
	while ((--size) >= 0 && n)
	{
		res[size] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		res[size] = '-';
	return (res);
}

char *ft_itoa(int n)
{
	int tmp;
	int neg;
	int c;
	char *res;

	neg = 0;
	c = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
		c++;
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		c++;
	}
	res = (char *)malloc((c + 1) * sizeof(char));
	res[c] = '\0';
	return (printstr(n, res, c, neg));
}

int main(void)
{
	char *res;

	res = ft_itoa(-123456);
	printf("%s\n", res);
	free(res);
	return (0);
}