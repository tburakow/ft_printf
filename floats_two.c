/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:23:51 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 14:33:09 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	float_input_type(t_flags **flags)
{
	long double	nbr;

	if ((*flags)->bigl == 1)
		nbr = va_arg((*flags)->arg, long double);
	else
		nbr = va_arg((*flags)->arg, double);
	(*flags)->checksum = nbr;
	if ((*flags)->empty_prec == 0 && (*flags)->precision == 0)
		(*flags)->precision = 6;
	if ((*flags)->empty_prec == 1)
	{
		(*flags)->precision = 0;
		(*flags)->empty_prec = 0;
	}
	return (nbr);
}

void	float_dec_point_two(long double nbr, t_flags **flags)
{
	char		*str;

	if (nbr < 0)
	{
		nbr = nbr * -1;
		(*flags)->neg = 1;
	}
	if (1 / nbr < 0)
		(*flags)->neg = 1;
	str = to_ascii(bankers_round(nbr, flags), flags);
	float_mod(str, flags);
	ft_strdel(&str);
}
