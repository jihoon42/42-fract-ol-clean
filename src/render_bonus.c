/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkim <jihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:25:00 by jihkim            #+#    #+#             */
/*   Updated: 2026/03/28 18:25:00 by jihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	unsigned char	*pixel_data;

	pixel_data = (unsigned char *)f->img_buf;
	pixel_data[x * 4 + y * f->line_bytes] = color;
	pixel_data[x * 4 + y * f->line_bytes + 1] = color >> 8;
	pixel_data[x * 4 + y * f->line_bytes + 2] = color >> 16;
	pixel_data[x * 4 + y * f->line_bytes + 3] = color >> 24;
}

static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	if (f->set == MANDELBROT)
		return (mandelbrot(pr, pi));
	if (f->set == JULIA)
		return (julia(f, pr, pi));
	if (f->set == BURNING_SHIP)
		return (burning_ship(pr, pi));
	if (f->set == TRICORN)
		return (tricorn(pr, pi));
	return (mandelbox(f, pr, pi));
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
