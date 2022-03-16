/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:06 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** This function sets the precision (precision flag) parameter, and
** returns the correctly incremented index (j).
*/
int	set_precision(char *str, int j, t_flags **flags)
{	
	(*flags)->precision = ft_atoi(&str[j]);
	if ((*flags)->precision != 0)
		(*flags)->empty_prec = 0;
	return (5);
}

/*
** This function sets the minimum field width (width flag) parameter, and
** returns the correctly incremented index (j).
*/
int	set_width(char *str, int j, t_flags **flags)
{	
	if ((*flags)->width == 0)
		(*flags)->width = ft_atoi(&str[j]);
	return (3);
}


/*
** this function checks if the current character matches
** the '0', '-' , '#', ' ' and '+' - flags.
*/
static int set_flags(char c, int flagcount, t_flags **flags)
{
	if (c == ' ')
		(*flags)->space = 1;
	if (c == '+')
		(*flags)->plus = 1;
	if (c == '-')
		(*flags)->minus = 1;
	if (c == '#')
		(*flags)->hash = 1;
	if (c == 'l')
		(*flags)->l += 1;
	if (c == 'h')
		(*flags)->h += 1;
	if (c == 'L')
		(*flags)->bigl = 1;
	if ((*flags)->l == 1)
		(*flags)->base_size = 16;
	if ((*flags)->l == 2)
		(*flags)->base_size = 32;
	if ((*flags)->h == 1)
		(*flags)->base_size = 16;
	if ((*flags)->h == 2)
		(*flags)->base_size = 16;
	return (flagcount + 1);
}

/*
** This function goes through the flags section of the format string.
** First, it checks for the '0', '-' , '#', ' ' and '+' - flags, and
** then checks for width and precision.
*/

int	ft_raise_flags(char *str, int j, t_flags **flags)
{
/*{
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
		if (str[j++] == '.')
			zero_width_prec = 'p';
		if (ft_isdigit(str[j]) == 1 && zero_width_prec == 'p')
			j = set_width(str, j, flags);
		if (check_for_char(str[j]) == 1)
			zero_width_prec = 'r';
	}
	*/
	int		status;
	int		flagcount;

	status = 0;
	flagcount = 0;
	j++;
	while (str && check_for_char(str[j], "diouxXfcsp%") == 0)
	{
		if (str[j] == '.')
		{
			status = 4;
			(*flags)->empty_prec = 1;
		}
		if (str[j] == '0' && status < 1 && (*flags)->width == 0)
		{
			(*flags)->zero = 1;
			status = 1;
		}
		flagcount = set_flags(str[j], flagcount, flags);
		if (status < 4 && ft_isdigit(str[j]) == 1 && str[j] != '0')
			status = set_width(str, j, flags);
		if (status == 4 && ft_isdigit(str[j]) == 1)
			status = set_precision(str, j, flags);
		j++;
	}
	(*flags)->type = str[j];
	//printf("\n%d\n", flagcount);
	return (j);
}
