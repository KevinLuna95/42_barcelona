typedef unsigned int size_t;

void *ft_memset(void *str, int c, size_t n)
{
	char *c_str = (char *)str;
	while (n)
		c_str[--n] = c;
}
/*
int main(void)
{
	#include <string.h>
	#include <stdio.h>
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);
	memset(str + 13, '.', 8 * sizeof(char));
	printf("After memset():  %s", str);
	char ft_str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", ft_str);
	ft_memset(ft_str + 13, '.', 8 * sizeof(char));

	printf("After memset():  %s", ft_str);
	return (0);
}*/