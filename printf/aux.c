/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:56:17 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/10/07 22:28:07 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

void	rec_nb(long num, char *base, int size, int *len)
{
	int		mod;

	mod = num % size;
	num /= size;
	if (num != 0)
		rec_nb (num, base, size, len);
	if (mod < 0)
		mod *= -1;
	write (1, &base[mod], 1);
	*len += 1;
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	count;
	int	len;

	len = 0;
	count = -1;
	while (base[++count])
	{
		if (base[count] == '+' || base[count] == '-')
			return (0);
	}
	if (count > 1)
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
			len++;
		}
		rec_nb (nbr, base, count, &len);
	}
	return (len);
}

int	ft_putstr_len(char *s)
{
	int	c;

	c = -1;
	if (!s)
	{
		ft_putstr_len("(null)");
		return (6);
	}
	while (s[++c])
		write(1, &s[c], 1);
	return (c);
}
