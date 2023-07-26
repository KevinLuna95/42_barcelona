/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:31:08 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/24 15:17:04 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_diferent(char *base, int size)
{
	int	count;
	int	c_base;

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

void	rec_nb(int num, char *base, int size)
{
	int		mod;

	mod = num % size;
	num /= size;
	if (num != 0)
		rec_nb (num, base, size);
	if (mod < 0)
		mod *= -1;
	write (1, &base[mod], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	count;

	count = -1;
	while (base[++count])
	{
		if (base[count] == '+' || base[count] == '-')
			return ;
	}
	if (count > 1 && is_diferent(base, count))
	{
		if (nbr < 0)
			write (1, "-", 1);
		rec_nb (nbr, base, count);
	}
}
