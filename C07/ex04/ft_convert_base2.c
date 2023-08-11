void check(int *res, char *str, int *count, int *c_sign)
{
	if (str[*count] != '+' && str[*count] != '-')
		*res = -1;
	if (str[*count] == '-')
	{
		*c_sign += 1;
		*res = 0;
	}
	*count += 1;
}
int ft_recursive_power(int nb, int power)
{
	if (power == 0 && nb == 0)
		return (1);
	else if (power == 0)
		return (0);
	else if (power > 1)
		return (nb * ft_recursive_power(nb, --power));
	else
		return (nb);
}

int ft_atoi(char *str)
{
	int count;
	int c_sign;
	int res;

	count = -1;
	c_sign = 0;
	res = 0;
	while (str[++count] && str[count] != '-' && str[count] != '+' && !(str[count] >= '0' && str[count] <= '9'))
	{
		if (!(str[count] >= 9 && str[count] <= 13) && str[count] != ' ')
			res = -1;
	}
	while (str[count] && !(str[count] >= '0' && str[count] <= '9'))
	{
		check(&res, str, &count, &c_sign);
	}
	if (res == -1)
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		res = (res * 10) + (str[count++] - '0');
	if (c_sign % 2)
		res *= -1;
	return (res);
}

int is_diferent(char *base, int size)
{
	int count;
	int c_base;

	count = -1;
	c_base = 0;
	while (++count < size)
	{
		while (c_base < size)
		{
			if (base[count] == base[++c_base])
				return (0);
		}
		c_base = 1 + count;
	}
	return (1);
}

void rec_nb(int num, char *base, int size)
{
	int mod;

	mod = num % size;
	num /= size;
	if (num != 0)
		rec_nb(num, base, size);
	if (mod < 0)
		mod *= -1;
	write(1, &base[mod], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
	int count;
	char *res;

	count = -1;
	while (base[++count])
	{
		if (base[count] == '+' || base[count] == '-')
			return;
	}
	if (count > 1 && is_diferent(base, count))
	{
		if (nbr < 0)
			res[0] = '-';
		rec_nb(nbr, base, count);
	}
}