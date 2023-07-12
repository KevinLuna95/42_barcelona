/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:17 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/07/11 17:54:21 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_st_nd(int *tab, int count_poss);
void	change_nd_last(int *tab, int poss, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	count_poss;
	int	count_small;

	count_poss = 0;
	count_small = 0;
	while (count_poss < size)
	{
		while (count_small < size)
		{
			if (tab[count_poss] > tab[count_poss + 1] && count_poss < size)
			{
				change_st_nd(tab, count_poss);
				change_nd_last(tab, count_small, size);
				count_small++;
			}
			else
			{
				change_nd_last(tab, count_poss, size);
				count_small++;
			}
		}
	}
	count_poss++;
	count_small = 0 + count_poss;
}

void	change_nd_last(int *tab, int poss, int size)
{
	int	tmp;
	int	tmp2;

	tmp = tab[poss + 1];
	while (poss < size - 1)
	{
		tmp2 = tab[poss + 2];
		tab[poss + 1] = tmp2;
		poss++;
		if (poss == size - 1)
			tab[size - 1] = tmp;
	}
}

void	change_st_nd(int *tab, int count_poss)
{
	int	tmp;
	int	tmp2;

	tmp = tab[count_poss];
	tmp2 = tab[count_poss + 1];
	tab[count_poss + 1] = tmp;
	tab[count_poss] = tmp2;
}
