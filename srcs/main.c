/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:54:15 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/27 15:18:05 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_e *e)
{
	draw(*e);
	return (0);
}

// void	zoom_2(t_e *e, int x, int y)
// {
	
// }

// t_e		zoom(t_e e)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	while (y != e.y)
// 	{
// 		x = -1;
// 		while (++x != e.x)
// 			zoom_2(&e, x, y);
// 		y++;
// 	}
// 	return (e);
// }

t_e		init(t_e e)
{
	e.iteration_max = 50;
	e.win_x = 500;
	e.win_y = 500;
	e.x1 = -2.1;
	e.x2 = 0.6;
	e.y1 = -1.2;
	e.y2 = 1.2;
	e.zoom_x = e.win_x / (e.x2 - e.x1);
	e.zoom_y = e.win_y / (e.y2 - e.y1);
	return (e);
}

t_e		init_window(t_e e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "Raycaster");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
	return (e);
}

int		key_hook(int key, t_e *e)
{
	printf("key: %d\n",key );
	if (key == 65307)
		exit(0);
	if (key == 65451)
	{
		e->zoom_x = e->zoom_x + 1000;
		e->zoom_y = e->zoom_y + 1000;
		// e->x1 += 0.2;
		// e->x2 += 0.2;
		// e->y1 -= 0.2;
		// e->y2 -= 0.4;
		 e->iteration_max = 1000;
	}
	if (key == 65364)
	{
		e->y1 -= 0.2;
	}
	if (key == 65362)
	{
		e->y1 += 0.2;
	}
	if (key == 65361)
	{
		e->x1 += 0.2;
	}
	if (key == 65363)
	{
		e->x1 -= 0.2;
	}
	if (key == 117 || key == 100 || key == 65451 || key == 61 ||
		key == 65453 || key == 45 || key == 65362 || key == 65364 ||
		key == 65361 || key == 65363 || key == 114 ||
		key == 112 || key == 105)
	{
		// *e = zoom(*e);
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
	}
	return (0);
}

void	draw(t_e e)
{
	int x = 0;
	int y = 0;
	int i = 0;
	while (x < e.win_x)
		{
			y = 0;
			// z = 0;
			i = 0;
			while (y < e.win_y)
			{
				double c_r = x / e.zoom_x + e.x1;
				double c_i = y / e.zoom_y + e.y1;
				double z_r = 0;
				double z_i = 0;
				i = 0;
				while(z_r * z_r + z_i * z_i < 4 && i < e.iteration_max)
				{
					double tmp = z_r;
					z_r = z_r * z_r - z_i * z_i + c_r;
					z_i = 2 * z_i * tmp + c_i;
					i++;
				}
				if (i == e.iteration_max)
					mlx_pixel_put(e.mlx, e.win, x, y, 0xff0000);
				else
					mlx_pixel_put(e.mlx, e.win, x, y, 0x2eb7ed);
				y++;
			}
			x++;
		}
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_e e;
	

	e = init(e);
	e = init_window(e);
	draw(e);
	// mlx_hook(win, 2, 3, key_hook, NULL);
	
	return (0);
}