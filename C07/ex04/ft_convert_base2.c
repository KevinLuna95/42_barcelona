int num_in_base(char num, char *base)
{
    int count;

    count = -1;
    while (base[++count])
        {
            if(num == base[count])
            return (count);
        }
        return (0);
}

void	check(int *res, char *str, int *count, int *c_sign)
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

char	*ft_atoi(char *str, char *base, int *c_sign)
{
	int	count;
	int	res;

	count = -1;
	c_sign = 0;
	res = 0;
	while (str[++count] && str[count] != '-' && str[count] != '+'
		&& !(str[count] >= '0' && str[count] <= '9'))
	{
		if (!(str[count] >= 9 && str[count] <= 13) && str[count] != ' ')
			res = -1;
	}
	while (str[count] && !(num_in_base(str[count], base)))
		check(&res, str, &count, &c_sign);
	if (res == -1)
		return (0);
	return (str[count]);
}
/*
a fucntion check if base, have more of 2 values and dosen't repit any char.
RETURN If base is valid return the size, if is invalid return 0
*/
int check_base(char *base)
{
	int size;
	int count;
	int count2;

	size = 0;
	count = -1;
	count2 = 0;
	if (base[0])
		return (0);
	while (base[size]){
		size++;
	}
	if (size < 2)
		return (0);
	while (base[++count])
	{
		while (base[++count2] < size)
		{
			if (base[count] == base[count2])
				return (0);
		}
		count2 = count;
	}
	return (size);
}

char	*ft_strcat(char *dest, char *src, char *base)
{
	int	count_src;
	int	count_dest;

	count_src = 0;
	count_dest = 0;
	while (dest[count_dest] != '\0')
		count_dest++;
	while (src[count_src] != '\0' && num_in_base(src[count_src], base))
	{
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (dest);
}