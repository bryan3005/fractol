/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:54:15 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/06 14:58:37 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_e *e)
{
	draw(*e);
	return (0);
}

t_e		init(t_e e)
{
	e.iteration_max = 25;
	e.win_x = 1000;
	e.win_y = 1000;
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
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, 1000, 1000, "Raycaster");
	e.img_ptr = mlx_new_image(e.mlx_ptr, 1000, 1000);
	e.data = mlx_get_data_addr(e.img_ptr, &(e.bpp), &(e.sizeline), &(e.endian));
	mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_hook(e.win_ptr, 2, 3, key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (e);
}

int		key_hook(int key, t_e *e)
{
	 printf("key: %d\n",key );
	if (key == 65307)
		exit(0);
	if (key == 65451 || key == 61)
	{
		e->zoom_x = e->zoom_x * 1.2;
		e->zoom_y = e->zoom_y *1.2;
		 e->x1 +=100 / e->zoom_x;
		 e->x2 -= 100 / e->zoom_x;
		 e->y1 += 100 / e->zoom_y;
		 e->y2 -=100 / e->zoom_y;
	}
	if (key == 65365)
		e->iteration_max = e->iteration_max + 10;
	if (key == 65366 && e->iteration_max > 10)
		e->iteration_max = e->iteration_max - 10;
	if (key == 65453 || key == 45)
	{
		e->zoom_x = e->zoom_x * 0.8;
		e->zoom_y = e->zoom_y * 0.8;
		e->x1 -=100 / e->zoom_x;
		 e->x2 += 100 / e->zoom_x;
		 e->y1 -= 100 / e->zoom_y;
		 e->y2 +=100 / e->zoom_y;
	}
	if (key == 65364)
	{
		e->y1 -= 100 / e->zoom_y;
	}
	if (key == 65362)
	{
		e->y1 += 100 / e->zoom_y;
	}
	if (key == 65361)
	{
		e->x1 += 100 / e->zoom_x;
	}
	if (key == 65363)
	{
		e->x1 -= 100 / e->zoom_x;
	}
	if (key == 117 || key == 100 || key == 65451 || key == 61 ||
		key == 65453 || key == 45 || key == 65362 || key == 65364 ||
		key == 65361 || key == 65363 || key == 114 ||
		key == 112 || key == 105 || key == 65365 || key == 65366)
	{
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
		e->img_ptr = mlx_new_image(e->mlx_ptr, 1000, 1000);
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
					put_pixel_to_image2(&e, x, y, 0xff0000);
				else
					put_pixel_to_image2(&e, x, y, 0x2eb7ed);
				y++;
			}
			x++;

		}
		mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0); 
}

void	put_pixel_to_image2(t_e *ptr, int x, int y, int color)
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

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_e 	*ptr;
	ptr = (t_e *)malloc(sizeof(t_e) * 2);
	*ptr = init(*ptr);
	*ptr = init_window(*ptr);
	return (0);
}