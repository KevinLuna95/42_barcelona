int ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}

/*
int main (void)
{
	printf("%d \n", ft_isascii('0'));
	printf("%d \n", ft_isascii('9'));
	printf("%d \n", ft_isascii('z'));
	printf("%d \n", ft_isascii('!'));
	printf("%d \n", ft_isascii('\n'));
	return (0);
}
*/