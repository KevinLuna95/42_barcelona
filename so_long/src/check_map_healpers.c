/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_healpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:25:20 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 22:03:30 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_line(char *line)
{
	int		i;
	char	c;

	i = -1;
	while (line[++i] != '\n' && line[i])
	{
		c = line[i];
		if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E')
			return (0);
	}
	return (1);
}

int	same_length(char *line, int *len)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (*len == 0 && i != 0)
	{
		*len = i;
	}
	else
	{
		if (i != *len || !i)
			return (0);
	}
	return (1);
}

int	is_special(t_data *v)
{
	if (v->map[v->heigth][v->width] == 'C')
	{
		v->map[v->heigth][v->width] = '0';
		v->collected++;
	}
	else if (v->map[v->heigth][v->width] == 'E' \
		&& v->collected == v->total_coll)
	{
		destroy_window(v);
		return (0);
	}
	else if (v->map[v->heigth][v->width] == 'E' \
		&& v->collected != v->total_coll)
		return (0);
	return (1);
}

int	not_solve(t_data *v)
{
	fill(v, (t_point){v->map_len, v->max_row}, \
		(t_point){v->width, v->heigth});
	return (confirm_map_solve(v));
}

int	can_solve(t_data *v, char *path)
{
	if (!not_solve(v))
	{
		return (0);
	}
	clean_map(v);
	check_map(path, v);
	return (1);
}
