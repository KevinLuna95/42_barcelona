#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*TODO Atencion, estoy usando unas funciones de c, he de añadirle el ft_*/
/*TODO Por algun motivo no funciona el free, HELP*/

int isinset(char c, char const *set)
{
	int count;

	count = -1;
	while (set[++count])
	{
		if (set[count] == c)
			return (1);
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int size;
	int c;
	char *res;
	int tmp;

	size = strlen(s1) - 1;
	c = 0;
	while (isinset(s1[c], set))
		c++;
	while (isinset(s1[size], set))
		size--;
	res = (char *)malloc((size - c + 1) * sizeof(char));
	if (!res)
		return (NULL);
	tmp = 0;
	while (c <= size)
		res[tmp++] = s1[c++];
	res[tmp] = '\0';
	return (res);
}

int main(void)
{
	char *str = "Hola soy kevin";
	char *strres;

	printf("str: %s|\n", str);
	strres = ft_strtrim(str, "+- ");
	printf("str: %s|\n", strres);
	free(strres);
	return (0);
}