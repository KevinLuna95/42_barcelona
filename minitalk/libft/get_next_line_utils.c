/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:27:04 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/11/13 08:11:31 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*ft_strjoin_push(char *s1, char *s2, int n)
{
	int		c1;
	int		c2;
	char	*str;

	c1 = -1;
	c2 = -1;
	str = (char *)malloc((ft_strlen(s1) + n + 1) * sizeof(char));
	if (!str)
		return (ft_free(s1));
	while (s1[++c1])
		str[++c2] = s1[c1];
	c1 = -1;
	while (++c1 != n)
		str[++c2] = s2[c1];
	str[++c2] = '\0';
	c2 = 0;
	while (c2 < BUFFER_SIZE)
	{
		if (c1 < BUFFER_SIZE && s2[c1])
			s2[c2++] = s2[c1++];
		else
			s2[c2++] = '\0';
	}
	ft_free(s1);
	return (str);
}
