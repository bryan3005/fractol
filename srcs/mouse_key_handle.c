/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:45:34 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/16 18:12:39 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook2(int key, t_e *e)
{
	if (key == 65307)
		exit(0);
	if (key == 65451 || key == 61)
	{
		e->zoom_x = e->zoom_x * 1.2;
		e->zoom_y = e->zoom_y * 1.2;
		e->x1 += 50 / e->zoom_x;
		e->x2 -= 50 / e->zoom_x;
		e->y1 += 50 / e->zoom_y;
		e->y2 -= 50 / e->zoom_y;
	}
	if (key == 65365)
		e->iteration_max = e->iteration_max + 10;
	if (key == 65366 && e->iteration_max > 25)
		e->iteration_max = e->iteration_max - 10;
	if (key == 65453 || key == 45)
	{
		e->zoom_x = e->zoom_x * 0.8;
		e->zoom_y = e->zoom_y * 0.8;
		e->x1 -= 50 / e->zoom_x;
		e->x2 += 50 / e->zoom_x;
		e->y1 -= 50 / e->zoom_y;
		e->y2 += 50 / e->zoom_y;
	}
}

int		key_hook(int key, t_e *e)
{
	key_hook2(key, e);
	if (key == 65364)
		e->y1 -= 100 / e->zoom_y;
	if (key == 65362)
		e->y1 += 100 / e->zoom_y;
	if (key == 65361)
		e->x1 += 100 / e->zoom_x;
	if (key == 114)
		*e = init(*e);
	if (key == 97)
		e->activate_mouse = YES;
	if (key == 100)
		e->activate_mouse = NO;
	if (key == 65363)
		e->x1 -= 100 / e->zoom_x;
	if (key == 100 || key == 65451 || key == 61 || key == 65453 ||
		key == 45 || key == 65362 || key == 65364 || key == 65361 ||
		key == 65363 || key == 114 || key == 65365 || key == 65366)
	{
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
		e->img_ptr = mlx_new_image(e->mlx_ptr, e->win_x, e->win_y);
		draw(*e);
	}
	return (0);
}

int		mousedepl(int button, int x, int y, t_e *e)
{
	double div;

	div = 5;
	if (button == 4)
	{
		e->zoom_x = e->zoom_x * 1.2;
		e->zoom_y = e->zoom_y * 1.2;
		e->x1 += (x / div) / e->zoom_x;
		e->x2 -= (x / div) / e->zoom_x;
		e->y1 += (y / div) / e->zoom_y;
		e->y2 -= (y / div) / e->zoom_y;
	}
	if (button == 5)
	{
		e->zoom_x = e->zoom_x * 0.8;
		e->zoom_y = e->zoom_y * 0.8;
		e->x1 -= (x / div) / e->zoom_x;
		e->x2 += (x / div) / e->zoom_x;
		e->y1 -= (y / div) / e->zoom_y;
		e->y2 += (y / div) / e->zoom_y;
	}
	if (button == 4 || button == 5)
		draw(*e);
	return (0);
}

int		motion_hook(int x, int y, t_e *e)
{
	if (e->activate_mouse == NO)
		return (0);
	if (e->choice == JU && e->activate_mouse == YES)
	{
		e->c_r = -0.7 + ((double)x - 500) / 250;
		e->c_i = 0.27015 + ((double)y - 500) / 250;
		e->event = 1;
		draw(*e);
	}
	return (0);
}
