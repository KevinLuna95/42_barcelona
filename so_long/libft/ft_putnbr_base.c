/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:57:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/13 07:59:29 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long nbr, char *base, int point)
{
	int	count;
	int	len;

	len = 0;
	count = ft_strlen(base);
	if (count > 1)
	{
		if (nbr < 0 && !point)
		{
			if (ft_putchar_len('-') == -1)
				return (-1);
			len++;
		}
		if (point && len != -1)
		{
			len = ft_putstr_len("0x");
			if (len == -1)
				return (-1);
			rec_nb_point ((unsigned long)nbr, base, count, &len);
		}
		else if (len != -1)
			rec_nb (nbr, base, count, &len);
	}
	return (len);
}
