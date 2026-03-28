/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:26:41 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/21 21:50:24 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_fractal_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tM / 1 - Mandelbrot", 1);
	ft_putendl_fd("\tJ / 2 - Julia", 1);
	ft_putstr_fd("\e[36mUsage example:\t./fractol <type>", 1);
	ft_putendl_fd("\n\t\t./fractol mandelbrot\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0.", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol julia\n\t\t./fractol julia 0.285 0.01\e[0m", 1);
}

static void	print_color_options(void)
{
	ft_putendl_fd("\n+===============  Color Display  ===============+", 1);
	ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
	ft_putendl_fd("The hex color code must be formatted as RRGGBB.", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol mandelbrot 0066FF\e[0m", 1);
	ft_putstr_fd("For Julia, provide the color after the ", 1);
	ft_putendl_fd("Julia parameters.", 1);
	ft_putstr_fd("\e[36mUsage example:\t./fractol julia ", 1);
	ft_putendl_fd("0.285 0.01 CC6600\e[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  ================+", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
	ft_putendl_fd("+============================================+\n", 1);
}

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("\n+============================================+", 1);
	ft_putendl_fd("|                FRACT'OL                    |", 1);
	ft_putendl_fd("+============================================+\n", 1);
	print_fractal_options();
	print_color_options();
	clean_exit(EXIT_FAILURE, f);
}
