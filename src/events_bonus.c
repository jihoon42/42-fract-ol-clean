/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 02:45:49 by jkim2             #+#    #+#             */
/*   Updated: 2026/03/29 02:47:33 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_view(t_fractol *f, double factor, int x, int y)
{
	double	anchor_r;
	double	anchor_i;

	anchor_r = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
	anchor_i = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
	f->min_r = anchor_r + (f->min_r - anchor_r) * factor;
	f->max_r = anchor_r + (f->max_r - anchor_r) * factor;
	f->min_i = anchor_i + (f->min_i - anchor_i) * factor;
	f->max_i = anchor_i + (f->max_i - anchor_i) * factor;
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

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		return (end_fractol(f));
	if (keycode == KEY_PLUS)
		zoom_view(f, 0.5, WIDTH / 2, HEIGHT / 2);
	else if (keycode == KEY_MINUS)
		zoom_view(f, 2.0, WIDTH / 2, HEIGHT / 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_view(f, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_view(f, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_view(f, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_view(f, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(f);
	else if (!switch_fractal(keycode, f))
		return (1);
	render(f);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_WHEEL_UP)
		zoom_view(f, 0.5, x, y);
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom_view(f, 2.0, x, y);
	else if (keycode == MOUSE_BTN && f->set == JULIA)
		julia_shift(x, y, f);
	else
		return (0);
	render(f);
	return (0);
}
