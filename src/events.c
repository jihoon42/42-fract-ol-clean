/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:18:56 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/20 14:20:11 by mcombeau         ###   ########.fr       */
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

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
		return (end_fractol(mlx));
	if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2.0);
	else
		return (1);
	render(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP)
		zoom(mlx, 0.5);
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2.0);
	else
		return (0);
	render(mlx);
	return (0);
}
