/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:09:47 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/21 10:36:24 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec_nb(int num)
{
	int		mod;
	char	c_num;

	mod = num % 10;
	num /= 10;
	if (num != 0)
		rec_nb (num);
	if (mod < 0)
		mod *= -1;
	c_num = '0' + mod;
	write (1, &c_num, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		write (1, "-", 1);
	rec_nb (nb);
}
/*
 * int main() {
  ft_putnbr(0);
  return 0;
}*/
