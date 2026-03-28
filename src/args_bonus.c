/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkim <jihkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:00 by jihkim            #+#    #+#             */
/*   Updated: 2026/03/28 18:15:00 by jihkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	match_set_name(char *arg, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (arg[i] && str[i])
	{
		if (ft_tolower(arg[i]) != str[i])
			return (0);
		i++;
	}
	if (arg[i] == '\0' && str[i] == '\0')
		return (1);
	return (arg[1] == '\0' && (ft_tolower(arg[0]) == c || arg[0] == n));
}

static void	get_set(t_fractol *f, char **av)
{
	if (match_set_name(av[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (match_set_name(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (match_set_name(av[1], "burning_ship", 'b', '3')
		|| match_set_name(av[1], "burningship", 'b', '3'))
		f->set = BURNING_SHIP;
	else if (match_set_name(av[1], "tricorn", 't', '4'))
		f->set = TRICORN;
	else if (match_set_name(av[1], "mandelbox", 'x', '5'))
		f->set = MANDELBOX;
	else
		help_msg(f);
}

static void	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	double	kr;
	double	ki;

	kr = 0;
	ki = 0;
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		help_msg(f);
	if (!ft_atof(av[2], &kr) || !ft_atof(av[3], &ki)
		|| kr > 2.0 || kr < -2.0
		|| ki > 2.0 || ki < -2.0)
		help_msg(f);
	f->kr = kr;
	f->ki = ki;
}

void	get_color(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && ac == 5)
		f->color = ft_atox_color(f, av[4]);
	else if (f->set != JULIA && ac == 3)
		f->color = ft_atox_color(f, av[2]);
	if (ac == 2 || (f->set == JULIA && ac == 4))
		f->color = 0x9966FF;
}

void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if ((f->set != JULIA && ac > 3) || (f->set == JULIA && ac > 5))
		help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}
