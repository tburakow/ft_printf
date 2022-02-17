/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/17 16:51:45 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
/*
** This function converts the long "d" from decimal to octal and returns it.
*/
int octal_conversion(int d)
{
    int octal;
    int i;
    int j;

    octal = 0;
    i = 1;
    while (d > 0)
    {
        octal = octal + (d % 8) * i;
        i = i * 10;
        d = d / 8;
    }
    return (octal);
}