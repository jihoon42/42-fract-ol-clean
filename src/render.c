/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:21:20 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/18 14:07:39 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
*/
static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	unsigned char	*buf;

	buf = (unsigned char *)f->buf;
	buf[x * 4 + y * f->line_bytes] = color;
	buf[x * 4 + y * f->line_bytes + 1] = color >> 8;
	buf[x * 4 + y * f->line_bytes + 2] = color >> 16;
	buf[x * 4 + y * f->line_bytes + 3] = color >> 24;
}

/* calculate_fractal:
*	Picks the correct fractal calculation function depending
*	on the current fractal set.
*/
static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	if (f->set == MANDELBROT)
		return (mandelbrot(pr, pi));
	return (julia(f, pr, pi));
}

static void	render_line(t_fractol *f, int y, double pi, double step_r)
{
	int		x;
	int		nb_iter;
	double	pr;

	x = -1;
	while (++x < WIDTH)
	{
		pr = f->min_r + (double)x * step_r;
		nb_iter = calculate_fractal(f, pr, pi);
		set_pixel_color(f, x, y, f->palette[nb_iter]);
	}
}

/* render:
*	Iterates through each pixel of the window, translates the pixel's
*	coordinates into a complex number to be able to calculate if that number
*	is part of the fractal set or not.
*	The number of iterations that complex number goes through before being
*	rejected from the fractal set determines which color is applied to the pixel.
*	Once all pixels have been assessed and added to the MLX image,
*	this function displays the MLX image to the window.
*/
void	render(t_fractol *f)
{
	int		y;
	double	pi;
	double	step_r;
	double	step_i;

	step_r = (f->max_r - f->min_r) / WIDTH;
	step_i = (f->min_i - f->max_i) / HEIGHT;
	y = -1;
	pi = f->max_i;
	while (++y < HEIGHT)
	{
		render_line(f, y, pi, step_r);
		pi += step_i;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
