/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:17 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/12 12:04:28 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	poss;
	int	sort;
	int	tmp;
	int	tmp2;

	poss = 0;
	sort = 0;
	while (!sort)
	{
		sort++;
		while (poss < size)
		{
			if (tab[poss] > tab[poss +1])
			{
				tmp = tab[poss];
				tmp2 = tab[poss +1];
				tab[poss +1] = tmp;
				tab[poss] = tmp2;
				sort = 0;
			}
			poss++;
		}
		poss = 0;
	}
}
