/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:42:41 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/16 16:19:01 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw2(t_e *e, int x, int y)
{
	if (e->choice == MAN || e->choice == BS)
	{
		e->c_r = x / e->zoom_x + e->x1;
		e->c_i = y / e->zoom_y + e->y1;
		e->z_r = 0;
		e->z_i = 0;
	}
	else if (e->choice == JU)
	{
		e->z_r = x / e->zoom_x + e->x1;
		e->z_i = y / e->zoom_y + e->y1;
	}
	else if (e->choice == OT)
	{
		e->c_r = x / e->zoom_x + e->x1;
		if (e->c_r < 0)
			e->c_r *= -1;
		e->c_i = y / e->zoom_y + e->y1;
		if (e->c_i < 0)
			e->c_i *= -1;
		e->z_r = 0;
		e->z_i = 0;
	}
}

void	draw3(t_e *e)
{
	double	tmp;

	tmp = e->z_r;
	e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
	if (e->z_r < 0 && e->choice == BS)
		e->z_r *= -1;
	e->z_i = 2 * e->z_i * tmp + e->c_i;
	if (e->z_i < 0 && e->choice == BS)
		e->z_i *= -1;
}

void	draw(t_e e)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < e.win_x)
	{
		y = -1;
		while (++y < e.win_y)
		{
			draw2(&e, x, y);
			i = -1;
			while (e.z_r * e.z_r + e.z_i * e.z_i < 4 && ++i < e.iteration_max)
				draw3(&e);
			put_pixel_to_image(&e, x, y, i * i);
		}
	}
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
}

void	put_pixel_to_image(t_e *ptr, int x, int y, int color)
{
	int	i;

	if (ptr->endian == 0)
	{
		i = (ptr->sizeline * y) + (x * (ptr->bpp / 8));
		ptr->data[i] = mlx_get_color_value(ptr->mlx_ptr, color);
		ptr->data[i + 1] = mlx_get_color_value(ptr->mlx_ptr, color >> 8);
		ptr->data[i + 2] = mlx_get_color_value(ptr->mlx_ptr, color >> 16);
	}
	else
	{
		i = (ptr->sizeline * y) + (x * (ptr->bpp / 8));
		ptr->data[i] = mlx_get_color_value(ptr->mlx_ptr, color >> 16);
		ptr->data[i + 1] = mlx_get_color_value(ptr->mlx_ptr, color >> 8);
		ptr->data[i + 2] = mlx_get_color_value(ptr->mlx_ptr, color);
	}
}
