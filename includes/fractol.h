/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:54:30 by mbryan            #+#    #+#             */
/*   Updated: 2015/03/13 14:26:01 by mbryan           ###   ########.fr       */
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

enum e_fractol
{
	MAN, JU, AUTRE 
};

typedef	struct		s_e
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			iteration_max;
	double			zoom_x;
	double			zoom_y;
	int				win_x;
	int				win_y;
	int				choice;
}					t_e;

typedef struct	s_img
{
  void		*mlx_ptr;
  void		*img_ptr;
  void		*win_ptr;
  int		bpp;
  int		endian;
  int		sizeline;
  char		*data;
}		t_img;


int		key_hook(int keycode, t_e *e);
void	draw(t_e e);
void	put_pixel_to_image2(t_e *ptr, int x, int y, int color);
int		mousedepl(int button, int x, int y, t_e *e);

#endif