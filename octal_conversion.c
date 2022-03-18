/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/18 14:06:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** This function converts the long long "d" from decimal to octal and returns it.
*/
unsigned long long octal_conversion(unsigned long long d)
{
    unsigned long long octal;
    unsigned long long i;
    
    octal = 0;
    i = 1;
    //printf("\noctal : %llu\n", d);
    if (d == 0)
        return (0);
    while (d > 0)
    {
        octal = octal + (d % 8) * i;
        i = i * 10;
        d = d / 8;
    }
    //printf("\n%o\n", 42);
    //printf("\noctal : %llu\n", octal);
    return (octal);
}