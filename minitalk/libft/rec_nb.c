/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:56:11 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/13 08:03:05 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rec_nb(long num, char *base, int size, int *len)
{
	int		mod;

	mod = num % size;
	num /= size;
	if (num != 0)
		rec_nb (num, base, size, len);
	if (mod < 0)
		mod *= -1;
	if (*len == -1)
		return ;
	if (write (1, &base[mod], 1) == -1)
	{
		*len = -1;
		return ;
	}
	*len += 1;
}
