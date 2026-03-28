/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:20:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/21 21:52:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* skip_space_sign_0x:
*	Skips spaces, '+' sign character and '0x' or '0X'
*	to parse hexadecimal color code strings.
*/
static int	skip_space_sign_0x(char *color)
{
	int	i;

	i = 0;
	while (color[i] == ' ' || (color[i] >= '\t' && color[i] <= '\r'))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i + 1] == 'X')))
		i = i + 2;
	return (i);
}

/* ft_atox_color:
*	Translates a hexadecimal color code string into an integer.
*	Valid: "RRGGBB", "0XRRGGBB", "rrggbb", "   +rrggbb"
*	Invalid: "-RRGGBB" "RRGGBB-", "RR GG BB"
*	If the string is not a valid hex color code, an error is displayed.
*	Returns the converted int. -1 if an error occured.
*/
int	ft_atox_color(t_fractol *f, char *color)
{
	int	i;
	int	x;
	int	n;

	n = 0;
	i = 0;
	i = skip_space_sign_0x(color);
	x = 0;
	while (color[i] && (ft_isdigit(color[i])
			|| (color[i] >= 'A' && color[i] <= 'F')
			|| (color[i] >= 'a' && color[i] <= 'f')))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else
			n = (n * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
		x++;
	}
	if (x == 6 && !color[i])
		return (n);
	else
		help_msg(f);
	return (-1);
}

/* skip_space_sign:
*	Skips spaces, '+' and '-' sign characters and sets the
*	is_neg variable if a '-' sign is detected.
*	Used to parse strings representing float values for Julia.
*/
static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

static int	parse_decimal_part(char *str, int i, double *nb, int *has_digit)
{
	double	div;

	div = 0.1;
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		*nb = *nb + ((str[i] - '0') * div);
		div *= 0.1;
		*has_digit = 1;
		i++;
	}
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	return (i);
}

/* ft_atof:
*	Converts a string into a float (decimal number). Used to parse
*	Julia starting values given as program arguments.
*	Returns 1 on success and stores the converted value in nb.
*	Returns 0 in case of parsing error.
*/
int	ft_atof(char *str, double *nb)
{
	int		i;
	int		is_neg;
	int		has_digit;
	double	value;

	value = 0;
	is_neg = 1;
	has_digit = 0;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]))
	{
		value = (value * 10.0) + (str[i] - '0');
		has_digit = 1;
		i++;
	}
	i = parse_decimal_part(str, i, &value, &has_digit);
	if (!has_digit || str[i] != '\0')
		return (0);
	*nb = value * is_neg;
	return (1);
}
