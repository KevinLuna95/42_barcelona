/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:16:50 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 22:21:29 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	key_press(int keycode, t_data *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 126)
		move_up(vars);
	else if (keycode == 1 || keycode == 125)
		move_down(vars);
	else if (keycode == 0 || keycode == 123)
		move_left(vars);
	else if (keycode == 2 || keycode == 124)
		move_right(vars);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data			vars;

	if (argc == 2)
	{
		init_vars(&vars);
		check_map(argv[1], &vars);
		vars.mlx = mlx_init();
		init_img(&vars);
		vars.win = mlx_new_window(vars.mlx, vars.w.img_width * vars.map_len, \
			vars.w.img_height * (vars.max_row), "Magical DoReMi");
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
		start_map(&vars, 0, 0);
		if (!can_solve(&vars, argv[1]))
			print_error("El mapa no se puede resolver", &vars);
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
		mlx_hook(vars.win, 17, 1L << 0, destroy_window, &vars);
		mlx_loop(vars.mlx);
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_error("Se han pasado argumentos no permitidos", NULL);
	}
}
