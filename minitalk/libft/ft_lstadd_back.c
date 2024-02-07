/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:16:27 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/22 08:11:33 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;
	t_list	*list_end;

	if (lst)
	{
		if (*lst)
		{
			list = ft_lstlast(*lst);
			list_end = ft_lstlast(*lst);
			list->next = new;
			list->next->prev = list_end;
		}
		else
			*lst = new;
	}
}
