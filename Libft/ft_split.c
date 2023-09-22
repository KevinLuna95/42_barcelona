#include <stdlib.h>
#include <stdio.h>

char **ft_split(char const *s, char c)
{
	int c_s;
	int sep;
	int count;
	int tmp;
	int m;
	int size;
	char **mat;
	char *str;

	c_s = -1;
	sep = 0;
	while (s[++c_s])
	{
		if (s[c_s] == c)
			sep++;
	}
	size = sep + 1;
	mat = (char **)malloc((size) * sizeof(char *));
	if (!mat)
		return (NULL);
	c_s = -1;
	m = -1;
	sep = 0;
	while (m + 1 < size)
	{
		if (s[++c_s] == c || !s[c_s])
		{
			count = sep;
			sep = c_s;
			if (!m)
				str = (char *)malloc((sep + 1 - count) * sizeof(char));
			else
				str = (char *)malloc((sep - count) * sizeof(char));
			if (!str)
				return (NULL);
			tmp = -1;
			while (count < sep)
			{
				if (m == -1)
					str[++tmp] = s[count++];
				else
					str[++tmp] = s[++count];
			}
			if (m == -1)
				str[tmp + 1] = '\0';
			else
				str[tmp] = '\0';
			mat[++m] = str;
		}
	}
	return (mat);
}

int main(void)
{
	char **mat;
	int c;

	c = -1;
	mat = ft_split("", '5');
	while (++c < 1)
		printf("|%s|\n", mat[c]);
	return (0);
}