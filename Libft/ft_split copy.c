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

typedef struct s_vars {
	int		c_s;
	int		sep;
	int		count;
	int		tmp;
	int		m;
	int		size;
}	t_vars;

static int	first(t_vars *vars, char const *s, char **mat)
{
	char	*str;

	vars->count = vars->sep;
	vars->sep = vars->c_s;
	if (!vars->m)
		str = (char *)malloc((vars->sep + 1 - vars->count) * 4);
	else
		str = (char *)malloc((vars->sep - vars->count) * sizeof(char));
	if (!str)
		return (0);
	vars->tmp = -1;
	while (vars->count < vars->sep)
	{
		if (vars->m == -1)
			str[++vars->tmp] = s[vars->count++];
		else
			str[++vars->tmp] = s[++vars->count];
	}
	if (vars->m == -1)
		str[vars->tmp + 1] = '\0';
	else
		str[vars->tmp] = '\0';
	mat[++vars->m] = str;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	t_vars	vars;
	char	**mat;

	vars.c_s = -1;
	vars.sep = 0;
	while (s[++vars.c_s])
	{
		if (s[vars.c_s] == c)
			vars.sep++;
	}
	vars.size = vars.sep + 1;
	mat = (char **)malloc((vars.size) * sizeof(char *));
	if (!mat)
		return (NULL);
	vars.c_s = -1;
	vars.m = -1;
	vars.sep = 0;
	while (vars.m + 1 < vars.size)
	{
		if (s[++vars.c_s] == c || !s[vars.c_s])
			if (!first(&vars, s, mat))
				return (NULL);
	}
	return (mat);
}
/*
int	main(void)
{
	char	**mat;
	int		c;

	c = -1;
	mat = ft_split("", ',');
	while (++c < 3)
	{
		printf("|%s|\n", mat[c]);
		free(mat[c]);
	}
	free(mat);
	return (0);
}
*/
