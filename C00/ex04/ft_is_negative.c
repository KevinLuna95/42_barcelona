/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:54:30 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/07 19:19:52 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	is_negative;

	if (n < 0)
	{
		is_negative = 'N';
	}
	else
	{
		is_negative = 'P';
	}
	write (1, &is_negative, 1);
}
