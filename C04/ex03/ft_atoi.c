/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:38:37 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/24 22:41:16 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

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

int	ft_atoi(char *str)
{
	int	count;
	int	c_sign;
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
/*
int main()
{
	printf("aroi or: %i\n", atoi("         -123"));
	printf("atoi ft: %i\n", ft_atoi("      -123"));
	return (0);
}*/
