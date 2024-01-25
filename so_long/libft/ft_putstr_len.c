/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:58:11 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/13 07:59:53 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_len(char *s)
{
	int	c;

	c = -1;
	if (!s)
	{
		if (ft_putstr_len("(null)") == -1)
			return (-1);
		return (6);
	}
	while (s[++c])
	{
		if (write(1, &s[c], 1) == -1)
			return (-1);
	}
	return (c);
}
