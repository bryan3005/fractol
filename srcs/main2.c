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

int		handle_arg(int argc, char **argv, t_e *e)
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of argument", 2);
		ft_putendl_fd("./fractol man\n./fractol ju \n./fractol bs", 2);
		return (0);
	}
	if (ft_strequ(argv[1], "man"))
		e->choice = MAN;
	else if (ft_strequ(argv[1], "ju"))
		e->choice = JU;
	else if (ft_strequ(argv[1], "bs"))
		e->choice = BS;
	if (ft_strequ(argv[1], "man") || ft_strequ(argv[1], "ju") ||
		ft_strequ(argv[1], "bs"))
		return (1);
	else
	{
		ft_putendl_fd("Wrong name\n./fractol man\n./fractol ju\n./fractol bs"
		, 2);
		return (0);
	}
}

int		main(int argc, char **argv)
{
	t_e		ptr;

	if (handle_arg(argc, argv, &ptr) == 0)
		return (0);
	ptr = init(ptr);
	ptr = init_window(ptr);
	return (0);
}
