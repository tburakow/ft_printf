/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:48:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 15:04:57 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	round_or_not(t_flags **flags)
{
	long double		new_num;

	new_num = (*flags)->checksum * ((*flags)->precision * 10);
	if (new_num - (long long)new_num > 0.5 || new_num - \
	(long long)new_num < -0.5)
		return (1);
	else if ((new_num - (long long)new_num == 0.5 || new_num - \
	(long long)new_num == -0.5))
	{
		if (((long long)new_num + 1) % 2 != 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

long double	bankers_round(long double number, t_flags **flags)
{
	unsigned int	i;
	long double		rounder;

	i = 0;
	rounder = 0.5;
	if (round_or_not(flags) == 0)
		return (number);
	while (i < (*flags)->precision)
	{
		rounder = rounder / 10;
		i++;
	}
	if (((intmax_t)number + 1) < number + rounder)
		return (number + rounder);
	if (((intmax_t)number + 1) % 2 != 0 && (*flags)->precision == 0)
		return (number);
	return (number + rounder);
}
