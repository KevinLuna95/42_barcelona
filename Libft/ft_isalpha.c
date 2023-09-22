int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*
int main (void)
{
	printf("%d \n", ft_isalpha('a'));
	printf("%d \n", ft_isalpha('G'));
	printf("%d \n", ft_isalpha('z'));
	printf("%d \n", ft_isalpha('!'));
	printf("%d \n", ft_isalpha('4'));
	printf("%d \n", ft_isalpha('\n'));
	return (0);
}
*/