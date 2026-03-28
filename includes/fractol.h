/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 02:44:33 by jkim2             #+#    #+#             */
/*   Updated: 2026/03/29 02:47:33 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60
# define NUM_COLOR_PATTERNS 9

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	mb_scale;
	double	mb_radius;
	double	mb_fixed;
	int		*palette;
	int		color_pattern;
	int		color;
	int		line_bytes;
}	t_fractol;

/*  Fractal Sets   */
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
int		burning_ship(double cr, double ci);
int		tricorn(double cr, double ci);
int		mandelbox(t_fractol *f, double cr, double ci);

/*  Draw Fractal	*/
void	render(t_fractol *f);
int		julia_shift(int x, int y, t_fractol *f);

/* Colors	*/
void	color_shift(t_fractol *f);
void	set_color_mono(t_fractol *f, int color);
void	set_color_multiple(t_fractol *f, int *colors, int n);
void	set_color_zebra(t_fractol *f, int color);
void	set_color_triad(t_fractol *f, int color);
void	set_color_tetra(t_fractol *f, int color);
void	set_color_opposites(t_fractol *f, int color);
void	set_color_contrasted(t_fractol *f, int color);
void	set_color_graphic(t_fractol *f, int color);
int		get_percent_color(int color, double percent);

/*  Events   */
int		key_event(int keycode, t_fractol *f);
int		mouse_event(int keycode, int x, int y, t_fractol *f);

/* Initialization */
void	clean_init(t_fractol *f);
void	reinit_img(t_fractol *f);
void	init(t_fractol *f);
void	get_complex_layout(t_fractol *f);
void	handle_args(t_fractol *f, int ac, char **av);
void	get_color(t_fractol *f, int ac, char **av);
int		ft_atof(char *str, double *nb);
int		ft_atox_color(t_fractol *f, char *color);

/*  Utils   */
int		end_fractol(t_fractol *f);
int		expose_fractol(t_fractol *f);
void	clean_exit(int error_code, t_fractol *f);
int		msg(char *str1, char *str2, int err_num);
void	help_msg(t_fractol *f);
void	print_controls(void);

#endif
