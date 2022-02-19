/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/19 11:10:53 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned convert_length(unsigned d)
{
    unsigned hex_base;
    unsigned i;

    hex_base = 0;
    i = 1;
    while (d > 0)
    {
        hex_base = hex_base + (d % 16) * i;
        i = i * 10;
        d = d / 16;
    }
    return (hex_base);
}
/*
** This function converts the long "d" from decimal to octal and returns it.
*/
char    *hex_conversion(unsigned d)
{
    char        *hexadec;
    unsigned    i;
    unsigned    rem;
    unsigned    len;

    len = ft_strlen(ft_itoa(convert_length(d)));
    hexadec = ft_strnew(len);
    // if (hexadec = NULL) Luo tähän exit strategy
    i = len;
    while (d > 0)
    {
        rem = d % 16;
        if (rem < 9)
            rem += 48;
        else
            rem += 87;
        hexadec[i - 1] = rem;
        i--;
        d = d / 16;
    }
    hexadec[len] = '\0';
    return (hexadec);
}

char    *hex_cap_conversion(unsigned d)
{
    char        *hexadec;
    unsigned    i;
    unsigned    rem;
    unsigned    len;

    len = ft_strlen(ft_itoa(convert_length(d)));
    hexadec = ft_strnew(len);
    // if (hexadec = NULL) Luo tähän exit strategy
    i = len;
    while (d > 0)
    {
        rem = d % 16;
        if (rem < 9)
            rem += 48;
        else
            rem += 55;
        hexadec[i - 1] = rem;
        i--;
        d = d / 16;
    }
    hexadec[len] = '\0';
    return (hexadec);
}

char    *ptr_conversion(unsigned long d)
{
    char        *hexadec;
    unsigned long   i;
    unsigned long   rem;
    unsigned long   len;

    len = ft_strlen(ft_itoa(convert_length(d)));
    hexadec = ft_strnew(len);
    // if (hexadec = NULL) Luo tähän exit strategy
    i = len;
    while (d > 0)
    {
        rem = d % 16;
        if (rem < 9)
            rem += 48;
        else
            rem += 87;
        hexadec[i - 1] = rem;
        i--;
        d = d / 16;
    }
    hexadec[len] = '\0';
    return (hexadec);
}
