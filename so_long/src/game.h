/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:43:28 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 21:35:52 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <libc.h>
# include <math.h>

# define BLACK   "\e[0;30m"
# define RED     "\e[0;31m"

# define IMG_P	"./img/P.xpm"
# define IMG_C	"./img/C.xpm"
# define IMG_0	"./img/0.xpm"
# define IMG_1	"./img/1.xpm"
# define IMG_E	"./img/E.xpm"

typedef struct s_img
{
	void	*img;
	void	*addr;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		max_row;
	int		endian;
	void	*mlx;
	void	*win;
	char	**map;
	int		row;
	int		col;
	int		map_len;
	int		heigth;
	int		width;
	int		collected;
	int		total_coll;
	int		moves;
	t_img	p;
	t_img	e;
	t_img	f;
	t_img	w;
	t_img	c;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	move_up(t_data *v);
void	move_down(t_data *v);
void	move_left(t_data *v);
void	move_right(t_data *v);
int		is_valid_line(char *line);
int		same_length(char *line, int *len);
int		is_special(t_data *v);
int		not_solve(t_data *v);
int		can_solve(t_data *v, char *path);
int		mins_map(t_data *v);
int		check_walls(t_data *v);
void	check_map(char *path, t_data *v);
void	fill(t_data *v, t_point size, t_point cur);
int		confirm_map_solve(t_data *v);
void	init_vars(t_data *v);
void	init_img(t_data *v);
void	start_map(t_data *v, int x, int i);
int		get_map(int fd, t_data *v, int n_lines);
void	clean_map(t_data *v);
int		destroy_window(t_data *vars);
void	print_error(char *err, t_data *v);
int		count_lines(char *path);

#endif