/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:40 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/20 14:06:56 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	int	base_color;

	reinit_img(f);
	base_color = f->color;
	if (base_color == 0x000000)
		base_color = 0x333333;
	set_color_multiple(f, (int [3]){0x000000, base_color, 0xFFFFFF}, 3);
}
