/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:01:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/11 18:40:35 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp1;
	int	tmp2;
	int	count;

	count = 0;
	while (count < ((size - size % 2)) / 2)
	{
		tmp1 = tab[count];
		tmp2 = tab[size - 1 - count];
		tab[count] = tmp2;
		tab[size - 1 - count] = tmp1;
		count++;
	}
}
