/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluna-bo <kluna-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:26:22 by kluna-bo          #+#    #+#             */
/*   Updated: 2024/01/25 21:28:44 by kluna-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_up(t_data *v)
{
	if (v->map[v->heigth - 1][v->width] != '1')
	{
		v->heigth--;
		if (is_special(v))
		{
			mlx_put_image_to_window(v->mlx, v->win, v->p.img, \
				v->width * v->p.img_width, v->heigth * v->p.img_height);
			mlx_put_image_to_window(v->mlx, v->win, v->f.img, \
				(v->width) * v->p.img_width, (v->heigth + 1) * v->p.img_height);
			ft_printf("%i movimiento\n", ++v->moves);
		}
		else
			v->heigth++;
	}
}

void	move_down(t_data *v)
{
	if (v->map[v->heigth + 1][v->width] != '1')
	{
		v->heigth++;
		if (is_special(v))
		{
			mlx_put_image_to_window(v->mlx, v->win, v->p.img, \
				v->width * v->p.img_width, v->heigth * v->p.img_height);
			mlx_put_image_to_window(v->mlx, v->win, v->f.img, \
				(v->width) * v->p.img_width, (v->heigth - 1) * v->p.img_height);
			ft_printf("%d movimiento\n", ++v->moves);
		}
		else
			v->heigth--;
	}
}

void	move_left(t_data *v)
{
	if (v->map[v->heigth][v->width - 1] != '1')
	{
		v->width--;
		if (is_special(v))
		{
			mlx_put_image_to_window(v->mlx, v->win, v->p.img, \
				v->width * v->p.img_width, v->heigth * v->p.img_height);
			mlx_put_image_to_window(v->mlx, v->win, v->f.img, \
				(v->width + 1) * v->p.img_width, (v->heigth) * v->p.img_height);
			ft_printf("%i movimiento\n", ++v->moves);
		}
		else
			v->width++;
	}
}

void	move_right(t_data *v)
{
	if (v->map[v->heigth][v->width + 1] != '1')
	{
		v->width++;
		if (is_special(v))
		{
			mlx_put_image_to_window(v->mlx, v->win, v->p.img, \
				v->width * v->p.img_width, v->heigth * v->p.img_height);
			mlx_put_image_to_window(v->mlx, v->win, v->f.img, \
				(v->width - 1) * v->p.img_width, (v->heigth) * v->p.img_height);
			ft_printf("%i movimiento\n", ++v->moves);
		}
		else
			v->width--;
	}
}
