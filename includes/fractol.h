/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:54:30 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/27 14:43:55 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef	struct		s_e
{
	void			*mlx;
	void			*win;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			iteration_max;
	double			zoom_x;
	double			zoom_y;
	double			decalx;
	double			decaly;
	double			angle1;
	double			angle2;
	int				decala;
	int				win_x;
	int				win_y;
}					t_e;


int		key_hook(int keycode, t_e *e);
void	draw(t_e e);

#endif