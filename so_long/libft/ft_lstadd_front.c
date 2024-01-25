/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:41:50 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/26 12:39:41 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		new->prev = NULL;
		*lst = new;
		if ((*lst)->next)
			(*lst)->next->prev = new;
	}
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*list2;
// 	t_list	*list3;

// 	list = ft_lstnew("pan");
// 	list2 = ft_lstnew("cola");
// 	ft_lstadd_front(&list, list2);
// 	printf("list %p\n", list->next);
// 	printf("list 2%p\n", list2->next);
// 	list3 = list2->next;
// 	printf("list3 content:%s\n", list3->content);
// }