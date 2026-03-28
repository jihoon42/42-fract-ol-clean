/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkim <jihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:00 by jihkim            #+#    #+#             */
/*   Updated: 2026/03/28 18:15:00 by jihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold_scale(double radius, double magnitude)
{
	if (magnitude < radius)
		return (1.0 / (radius * radius));
	if (magnitude < 1.0)
		return (1.0 / (magnitude * magnitude));
	return (1.0);
}

int	mandelbox(t_fractol *f, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;
	double	fold;

	vr = cr;
	vi = ci;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		vr = f->mb_fixed * box_fold(vr);
		vi = f->mb_fixed * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		if (mag > 2.0)
			break ;
		fold = ball_fold_scale(f->mb_radius, mag);
		vr = vr * f->mb_scale * fold + cr;
		vi = vi * f->mb_scale * fold + ci;
		n++;
	}
	return (n);
}
