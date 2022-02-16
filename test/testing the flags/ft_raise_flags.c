/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/16 23:15:05 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function sets the precision (precision flag) parameter, and
** returns the correctly incremented index (j).
*/
int	set_precision(char *str, int j, t_flags *flags)
{	
	flags->precision = ft_atoi(&str[j]);
	while (ft_isdigit(str[j]) == 1)
		j++;
	return (j);
}

/*
** This function sets the minimum field width (width flag) parameter, and
** returns the correctly incremented index (j).
*/
int	set_width(char *str, int j, t_flags *flags)
{	
	flags->width = ft_atoi(&str[j]);
	while (ft_isdigit(str[j]) == 1)
		j++;
	return (j);
}


/*
** this function checks if the current character matches
** the '0', '-' , '#', ' ' and '+' - flags.
*/
static int set_flags(char c, int j, t_flags *flags)
{
	if (c == ' ')
		flags->space = 1;
	if (c == '+')
		flags->plus = 1;
	if (c == '-')
		flags->minus = 1;
	if (c == '#')
		flags->hash = 1;
	return (j + 1);
}

/*
** This function goes through the flags section of the format string.
** First, it checks for the '0', '-' , '#', ' ' and '+' - flags, and
** then checks for width and precision.
*/
int	ft_raise_flags(char *str, int j, t_flags *flags)
{
	char	zero_width_prec;
	
	zero_width_prec = 'z';
	while (zero_width_prec != 'r')
	{
		if (str[j] == '0' && zero_width_prec == 'z')
		{
			flags->zero = 1;
			zero_width_prec = 'w';
			j++;
		}
		if (ft_isdigit(str[j]) == 0)
			j = set_flags(str[j], j, flags);
		if (ft_isdigit(str[j]) == 1 && zero_width_prec == 'w')
			j = set_width(str, j, flags);
		if (str[j] == '.')
			zero_width_prec = 'p';
		if (ft_isdigit(str[j]) == 1 && zero_width_prec == 'p')
			j = set_width(str, j, flags);
		if (check_for_char(str[j]) == 1)
			zero_width_prec = 'r';
		j++;
	}
	return (j);
}
