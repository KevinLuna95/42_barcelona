int ft_isprint(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
int main (void)
{<
	printf("%d \n", ft_isprint('0'));
	printf("%d \n", ft_isprint('9'));
	printf("%d \n", ft_isprint('z'));
	printf("%d \n", ft_isprint('!'));
	printf("%d \n", ft_isprint('\n'));
	return (0);
}
*/