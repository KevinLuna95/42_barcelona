#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int c;
	char *res;

	c = 0;
	while (s[c])
		c++;
	res = (char *)malloc((1 + c) * sizeof(char));
	res[c] = NULL;
	while (--c >= 0)
		res[c] = f(c, res[c]);
	return (res);
}