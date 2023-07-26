/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:19:11 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/18 16:27:56 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	decimal_to_hexadecimal(int num)
{
	int		count;
	int		mod;
	int		div;
	char	h;

	mod = num % 16;
	div = ((num - mod) / 16);
	count = 0;
	write (1, "\\", 1);
	if (div < 10)
		h = 48 + div;
	else
		h = 87 + div;
	write (1, &h, 1);
	if (mod < 10)
		h = 48 + mod;
	else
		h = 87 + mod;
	write (1, &h, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (!(str[count] >= 32 && str[count] <= 126))
			decimal_to_hexadecimal(str[count]);
		else
			write (1, &str[count], 1);
		count++;
	}
}
