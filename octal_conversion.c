/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/18 12:57:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** This function converts the long long "d" from decimal to octal and returns it.
*/
unsigned long long octal_conversion(unsigned long long d)
{
    unsigned long long octal;
    long long i;
    
    octal = 0;
    i = 1;
    if (d == 0)
        return (0);
    while (d > 0)
    {
        octal = octal + (d % 8) * i;
        i = i * 10;
        d = d / 8;
    }
    return (octal);
}