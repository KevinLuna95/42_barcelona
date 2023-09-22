int ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
		(9 >= 'A' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
int main (void)
{
	printf("%d \n", ft_isalnum('a'));
	printf("%d \n", ft_isalnum('G'));
	printf("%d \n", ft_isalnum('z'));
	printf("%d \n", ft_isalnum('4'));
	printf("%d \n", ft_isalnum('!'));
	printf("%d \n", ft_isalnum('\n'));
	return (0);
}
*/