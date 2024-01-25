/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:24:39 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 22:22:05 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*arr[i][j][P][E][C]*/
int	mins_map(t_data *v)
{
	int	arr[5];

	arr[0] = -1;
	arr[1] = -1;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;
	while (++arr[0] < v->max_row)
	{
		while (v->map[arr[0]][++arr[1]] && v->map[arr[0]][arr[1]] != '\n')
		{
			if (v->map[arr[0]][arr[1]] == 'P')
				arr[2]++;
			if (v->map[arr[0]][arr[1]] == 'E')
				arr[3]++;
			if (v->map[arr[0]][arr[1]] == 'C')
				arr[4]++;
		}
		arr[1] = 0;
	}
	v->total_coll = arr[4];
	if (arr[2] == 1 && arr[3] == 1 && arr[4] >= 1)
		return (1);
	else
		return (0);
}

int	check_walls(t_data *v)
{
	int	arr[2];

	arr[0] = -1;
	arr[1] = -1;
	while (++arr[0] < v->max_row)
	{
		if (arr[0] == 0 || arr[0] == v->max_row - 1)
		{
			while (v->map[arr[0]][++arr[1]] && v->map[arr[0]][arr[1]] != '\n')
			{
				if (v->map[arr[0]][arr[1]] != '1')
					return (0);
			}
		}
		else
		{
			if (v->map[arr[0]][0] != '1' || \
				v->map[arr[0]][v->map_len - 1] != '1')
				return (0);
		}
		arr[1] = 0;
	}
	return (1);
}

void	check_map(char *path, t_data *v)
{
	int	fd;
	int	i;

	i = -1;
	fd = 0;
	if (!ft_strnstr(path, ".ber", ft_strlen(path) - 1))
		print_error("El archivo no es un .ber", NULL);
	v->map_len = 0;
	v->max_row = count_lines(path);
	fd = open(path, fd, O_RDONLY);
	if (fd == -1)
		print_error("En file descriptor", v);
	if (!get_map(fd, v, v->max_row))
		print_error("En el mapa", v);
	while (v->map[++i])
	{
		if (!is_valid_line(v->map[i]) || !same_length(v->map[i], &v->map_len))
			print_error("En el mapa", v);
	}
	if (!mins_map(v) || !check_walls(v) || (v->max_row > 33 || v->map_len > 64))
		print_error("En el mapa", v);
}

void	fill(t_data *v, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x \
		|| (v->map[cur.y][cur.x] != '0' && v->map[cur.y][cur.x] != 'P' \
		&& v->map[cur.y][cur.x] != 'C'))
		return ;
	v->map[cur.y][cur.x] = 'F';
	fill(v, size, (t_point){cur.x - 1, cur.y});
	fill(v, size, (t_point){cur.x + 1, cur.y});
	fill(v, size, (t_point){cur.x, cur.y - 1});
	fill(v, size, (t_point){cur.x, cur.y + 1});
}

int	confirm_map_solve(t_data *v)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < v->map_len)
	{
		while (++j < v->max_row)
		{
			if (v->map[j][i] == 'C')
				return (0);
			if (v->map[j][i] == 'E')
			{
				if (v->map[j + 1][i] == 'F' || v->map[j - 1][i] == 'F' || \
					v->map[j][i + 1] == 'F' || v->map[j][i - 1] == 'F')
					break ;
				else
					return (0);
			}
		}
		j = -1;
	}
	return (1);
}
