/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:48:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/09 13:56:54 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double bankers_round(long double number, t_flags **flags)
{
    unsigned int    i;
    long double     rounder;

    i = 0;
    rounder = 0.5;
    while (i < (*flags)->precision)
    {
        rounder = rounder / 10;
        i++;
    }
    if (((intmax_t)number + 1) < number + rounder)
        return (number + rounder);
    if (((intmax_t) number + 1) % 2 != 0 && (*flags)->precision == 0)
        return (number);
    return (number + rounder);
}
