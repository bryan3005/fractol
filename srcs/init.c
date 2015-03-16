/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:13:14 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/16 15:54:01 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_e		init_man(t_e e)
{
	e.iteration_max = 25;
	e.x1 = -2.1;
	e.x2 = 0.6;
	e.y1 = -1.2;
	e.y2 = 1.2;
	e.zoom_x = e.win_x / (e.x2 - e.x1);
	e.zoom_y = e.win_y / (e.y2 - e.y1);
	return (e);
}

t_e		init_ju(t_e e)
{
	e.iteration_max = 55;
	e.x1 = -1.6;
	e.x2 = 0.6;
	e.y1 = -1.2;
	e.y2 = 0.6;
	e.zoom_x = e.win_x / ((e.x2 - e.x1) * 1.5);
	e.zoom_y = e.win_y / ((e.y2 - e.y1) * 1.5);
	e.c_r = -0.7;
	e.c_i = 0.27015;
	return (e);
}

t_e		init_bs(t_e e)
{
	e.iteration_max = 25;
	e.x1 = -2.6;
	e.x2 = 0.1;
	e.y1 = -3;
	e.y2 = 0;
	e.zoom_x = e.win_x / ((e.x2 - e.x1) * 1.5);
	e.zoom_y = e.win_y / ((e.y2 - e.y1) * 1.5);
	return (e);
}

t_e		init(t_e e)
{
	e.win_x = 1000;
	e.win_y = 1000;
	e.activate_mouse = NO;
	if (e.choice == MAN)
		e = init_man(e);
	else if (e.choice == JU)
		e = init_ju(e);
	else if (e.choice == BS)
		e = init_bs(e);
	return (e);
}

t_e		init_window(t_e e)
{
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, e.win_x, e.win_y, "Raycaster");
	e.img_ptr = mlx_new_image(e.mlx_ptr, e.win_x, e.win_y);
	e.data = mlx_get_data_addr(e.img_ptr, &(e.bpp), &(e.sizeline), &(e.endian));
	mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_hook(e.win_ptr, 2, 3, key_hook, &e);
	if (e.choice == JU)
		mlx_hook(e.win_ptr, 6, 64, motion_hook, &e);
	mlx_mouse_hook(e.win_ptr, mousedepl, &e);
	mlx_loop(e.mlx_ptr);
	return (e);
}
