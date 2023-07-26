/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:17:59 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/23 22:00:54 by jrafols-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int				count;
	int				c_sign;
	unsigned int	res;

	count = -1;
	c_sign = 0;
	res = 0;
	while (str[++count] && !(str[count] >= '0' && str[count] <= '9'))
	{
		if (str[count] == '-')
			c_sign++;
	}
	while (str[count] >= '0' && str[count] <= '9')
		res = (res * 10) + (str[count++] - '0');
	if (c_sign % 2)
		res *= -1;
	return (res);
}

char	*ft_str_trim(char *str)
{
	int	i;
	int	j;
	int	last_space;

	i = 0;
	j = 0;
	last_space = 1;
	while (str[i])
	{
		if (str[i] != ' ' || !last_space)
		{
			str[j] = str[i];
			j++;
		}
		if (str[i] == ' ')
			last_space = 1;
		else
			last_space = 0;
		i++;
	}
	str[j] = '\0';
	return (str);
}

unsigned int	ft_str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_error(unsigned int code)
{
	if (code == 0)
		write(1, "Error\n", 6);
	if (code == 1)
		write(1, "Dict Error\n", 11);
}

unsigned int	ft_power(unsigned int n, unsigned int power)
{
	unsigned int	result;

	if (power == 0)
		return (1);
	result = n;
	while (power > 1)
	{
		result *= n;
		power--;
	}
	return (result);
}
