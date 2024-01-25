/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   healpers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:22:41 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 22:20:58 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clean_map(t_data *v)
{
	int	i;

	i = 0;
	while (v->map[i])
	{
		free(v->map[i]);
		i++;
	}
	free(v->map);
}

int	destroy_window(t_data *vars)
{
	clean_map(vars);
	if (vars->mlx && vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	exit(EXIT_SUCCESS);
	if (vars)
		return (0);
	return (0);
}

void	print_error(char *err, t_data *v)
{
	if (v)
		clean_map(v);
	ft_printf(RED "Error\n%s\n" BLACK, err);
	exit(EXIT_FAILURE);
}

int	count_lines(char *path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	fd = open(path, fd, O_RDONLY);
	if (fd == -1)
		print_error("En file descriptor", NULL);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		print_error("Al cerrar archivo", NULL);
	free(line);
	return (i);
}
