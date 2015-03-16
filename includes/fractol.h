/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:54:30 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/16 16:07:58 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

enum	e_fractol
{
	MAN, JU, BS, OT
};

enum	e_activ
{
	YES, NO
};

typedef	struct	s_e
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bpp;
	int			endian;
	int			sizeline;
	char		*data;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		iteration_max;
	double		zoom_x;
	double		zoom_y;
	int			win_x;
	int			win_y;
	int			choice;
	double		c_r;
	double		c_i;
	int			activate_mouse;
	int			event;
	double		z_r;
	double		z_i;
}				t_e;

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			bpp;
	int			endian;
	int			sizeline;
	char		*data;
}				t_img;

int				key_hook(int keycode, t_e *e);
void			draw(t_e e);
void			put_pixel_to_image(t_e *ptr, int x, int y, int color);
int				mousedepl(int button, int x, int y, t_e *e);
int				motion_hook(int x, int y, t_e *e);
t_e				init_window(t_e e);
int				expose_hook(t_e *e);
int				key_hook(int key, t_e *e);
int				motion_hook(int x, int y, t_e *e);
t_e				init(t_e e);
void			draw(t_e e);

#endif
