/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:24:31 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/27 11:37:36 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	count;

	count = 3;
	if (nb <= 2 || nb >= 2147483647 || (nb % 2) == 0)
		return (0);
	while (nb > count)
	{
		if ((nb % count) == 0)
			return (0);
		count += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb)
	{
		if (ft_is_prime(nb))
			return (nb);
		else
			nb++;
	}
	return (0);
}
