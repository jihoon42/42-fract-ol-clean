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

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
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
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		if (mag > 2.0)
			break ;
		fold = ball_fold(f->rx, mag);
		vr = vr * f->sx * fold + cr;
		vi = vi * f->sx * fold + ci;
		n++;
	}
	return (n);
}
