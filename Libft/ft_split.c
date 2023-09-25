/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:29:46 by kluna-bo          #+#    #+#             */
/*   Updated: 2023/09/23 11:29:46 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_vars {
	int		c_s;
	int		sep;
	int		count;
	int		tmp;
	int		m;
	int		size;
}	t_vars;

static int	count_words(char const *s, char c)
{
	int	i;
	int	size;
	int	count;

	size = ft_strlen(s);
	i = -1;
	c = 0;
	while (i <= size)
	{
		if (s[++i] == c || s[i] == '\0')
			count++;
	}
	return (count);
}

// char	**ft_split(char const *s, char c)
// {
// 	printf("%i\n", count_words("char const *s", ' '));
// 	return (NULL);
// }

int	main(void)
{
	// char	**mat;
	// int		c;

	//c = -1;
	printf("%i\n", count_words("char const *s", ' '));
	//mat = ft_split("", ',');
	/*while (++c < 3)
	{
		printf("|%s|\n", mat[c]);
		free(mat[c]);
	}
	free(mat);*/
	return (0);
}

