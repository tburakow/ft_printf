/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/10 14:58:11 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned convert_length(long long d)
{
    long long hex_base;
    long long i;

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
char    *hex_conversion(long long d)
{
    char        *hexadec;
    unsigned    i;
    unsigned    rem;
    unsigned    len;

    len = ft_strlen(ft_itoa(convert_length(d)));
    hexadec = ft_strnew(len);
    if (!hexadec)
        return (NULL);
    i = len;
    while (d > 0)
    {
        rem = d % 16;
        if (rem <= 9)
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

char    *hex_cap_conversion(long long d, int base_size)
{
    char        *hexadec;
    long long   i;
    long long   rem;
    unsigned long long neg;

    neg = 0;
    hexadec = ft_strnew(base_size);
    if (!hexadec)
        return (NULL);
    i = base_size;
    if (d > 0)
        while (d > 0)
        {
            rem = d % 16;
            if (rem <= 9)
                rem += 48;
            else
                rem += 55;
            hexadec[i - 1] = rem;
            i--;
            d = d / 16;
        }
    else
    {
        neg = d;
        while (neg > 0)
        {
                rem = neg % 16;
            if (rem <= 9)
                rem += 48;
            else
                rem += 55;
            hexadec[i - 1] = rem;
            i--;
            neg = neg / 16;
        }
    }
    hexadec[base_size] = '\0';
    if (i > 0)
        hexadec = ft_strsub(hexadec, i, (base_size - 1));
    return (hexadec);
}

char    *ptr_conversion(long long d)
{
    char        *hexadec;
    unsigned long  i;
    unsigned long  rem;
    unsigned long  len;

    len = ft_strlen(ft_itoa(convert_length(d)));
    hexadec = ft_strnew(len);
    // if (hexadec = NULL) Luo tähän exit strategy
    i = len;
    while (d > 0)
    {
        rem = d % 16;
        if (rem <= 9)
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
