/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkim <jihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:00 by jihkim            #+#    #+#             */
/*   Updated: 2026/03/28 18:15:00 by jihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double factor)
{
	double	range_r;
	double	range_i;
	double	center_r;
	double	center_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	center_r = f->min_r + (range_r / 2.0);
	center_i = f->min_i + (range_i / 2.0);
	range_r *= factor;
	range_i *= factor;
	f->min_r = center_r - (range_r / 2.0);
	f->max_r = center_r + (range_r / 2.0);
	f->min_i = center_i - (range_i / 2.0);
	f->max_i = center_i + (range_i / 2.0);
}

static void	move_view(t_fractol *f, double distance, char direction)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += range_r * distance;
		f->max_r += range_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= range_r * distance;
		f->max_r -= range_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= range_i * distance;
		f->max_i -= range_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += range_i * distance;
		f->max_i += range_i * distance;
	}
}

static void	zoom_to_position(t_fractol *f, double factor, int x, int y)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	zoom(f, factor);
	if (x < 0)
		move_view(f, (double)(-x) / WIDTH, 'L');
	else if (x > 0)
		move_view(f, (double)x / WIDTH, 'R');
	if (y < 0)
		move_view(f, (double)(-y) / HEIGHT, 'U');
	else if (y > 0)
		move_view(f, (double)y / HEIGHT, 'D');
}

static int	switch_fractal(int keycode, t_fractol *f)
{
	int	new_set;

	new_set = f->set;
	if (keycode == KEY_ONE)
		new_set = MANDELBROT;
	else if (keycode == KEY_TWO)
		new_set = JULIA;
	else if (keycode == KEY_THREE)
		new_set = BURNING_SHIP;
	else if (keycode == KEY_FOUR)
		new_set = TRICORN;
	else if (keycode == KEY_FIVE)
		new_set = MANDELBOX;
	if (new_set == f->set)
		return (0);
	f->set = new_set;
	get_complex_layout(f);
	return (1);
}

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
		return (end_fractol(mlx));
	if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2.0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_view(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_view(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_view(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_view(mlx, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(mlx);
	else if (!switch_fractal(keycode, mlx))
		return (1);
	render(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
		zoom_to_position(mlx, 0.5, x, y);
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom_to_position(mlx, 2.0, x, y);
	else if (keycode == MOUSE_BTN && mlx->set == JULIA)
		julia_shift(x, y, mlx);
	else
		return (0);
	render(mlx);
	return (0);
}
