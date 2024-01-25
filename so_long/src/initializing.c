/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:20:13 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 22:22:01 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_vars(t_data *v)
{
	v->collected = 0;
	v->total_coll = 0;
	v->row = 0;
	v->col = 0;
	v->moves = 0;
	v->max_row = 0;
}

void	init_img(t_data *v)
{
	v->p.img = mlx_xpm_file_to_image(v->mlx, \
			IMG_P, &v->p.img_width, &v->p.img_height);
	v->c.img = mlx_xpm_file_to_image(v->mlx, \
			IMG_C, &v->c.img_width, &v->c.img_height);
	v->f.img = mlx_xpm_file_to_image(v->mlx, \
			IMG_0, &v->f.img_width, &v->f.img_height);
	v->w.img = mlx_xpm_file_to_image(v->mlx, \
			IMG_1, &v->w.img_width, &v->w.img_height);
	v->e.img = mlx_xpm_file_to_image(v->mlx, \
			IMG_E, &v->e.img_width, &v->e.img_height);
	if (v->p.img_height != 40 || v->p.img_width != 40 || \
	v->c.img_height != 40 || v->c.img_width != 40 || \
	v->f.img_height != 40 || v->f.img_width != 40 || v->w.img_height != 40 || \
	v->w.img_width != 40 || v->e.img_height != 40 || v->e.img_width != 40)
		print_error("Las imágenes no tienen 40 px X 40 px", v);
	v->p.addr = mlx_get_data_addr(&v->p.img, &v->p.bits_per_pixel, \
			&v->p.line_length, &v->p.endian);
	v->c.addr = mlx_get_data_addr(&v->c.img, &v->c.bits_per_pixel, \
			&v->c.line_length, &v->c.endian);
	v->f.addr = mlx_get_data_addr(&v->f.img, &v->f.bits_per_pixel, \
			&v->f.line_length, &v->f.endian);
	v->w.addr = mlx_get_data_addr(&v->w.img, &v->w.bits_per_pixel, \
			&v->w.line_length, &v->w.endian);
	v->e.addr = mlx_get_data_addr(&v->e.img, &v->e.bits_per_pixel, \
			&v->e.line_length, &v->e.endian);
}

void	start_map(t_data *v, int x, int i)
{
	while (i < v->max_row)
	{
		if (v->map[i][x] == '1')
			mlx_put_image_to_window(v->mlx, v->win, v->w.img, v->col, v->row);
		else if (v->map[i][x] == '0')
			mlx_put_image_to_window(v->mlx, v->win, v->f.img, v->col, v->row);
		else if (v->map[i][x] == 'C')
			mlx_put_image_to_window(v->mlx, v->win, v->c.img, v->col, v->row);
		else if (v->map[i][x] == 'P')
		{
			mlx_put_image_to_window(v->mlx, v->win, v->p.img, v->col, v->row);
			v->heigth = i;
			v->width = x;
		}
		else if (v->map[i][x] == 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->col, v->row);
		v->col += v->e.img_width;
		if (++x == v->map_len)
		{
			x = 0;
			i++;
			v->row += v->e.img_height;
			v->col = 0;
		}
	}
}

int	get_map(int fd, t_data *v, int n_lines)
{
	char	*line;
	int		i;

	i = 0;
	v->map = (char **) malloc(n_lines * sizeof(char *) + 1);
	if (!v->map)
		print_error("Fallo de malloc", v);
	line = get_next_line(fd);
	while (line)
	{
		v->map[i++] = line;
		line = get_next_line(fd);
	}
	v->map[i] = NULL;
	if (i != n_lines)
		print_error("Fallo en get next line", v);
	return (1);
}
