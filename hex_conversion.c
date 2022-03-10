/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/10 15:36:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function converts the long "d" from decimal to octal and returns it.
*/
char    *hex_conversion(long long d, t_flags **flags)
{
    char        *hexadec;
    long long   i;
    long long   rem;
    unsigned long long neg;

    neg = 0;
    hexadec = ft_strnew((*flags)->base_size);
    if (!hexadec)
        return (NULL);
    i = (*flags)->base_size;
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
                rem += 87;
            hexadec[i - 1] = rem;
            i--;
            neg = neg / 16;
        }
    }
    hexadec[(*flags)->base_size] = '\0';
    if (i > 0)
        hexadec = ft_strsub(hexadec, i, ((*flags)->base_size - 1));
    return (hexadec);
}

char    *hex_cap_conversion(long long d, t_flags **flags)
{
    char        *hexadec;
    long long   i;
    long long   rem;
    unsigned long long neg;

    neg = 0;
    hexadec = ft_strnew((*flags)->base_size);
    if (!hexadec)
        return (NULL);
    i = (*flags)->base_size;
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
    hexadec[(*flags)->base_size] = '\0';
    if (i > 0)
        hexadec = ft_strsub(hexadec, i, ((*flags)->base_size - 1));
    return (hexadec);
}

char    *ptr_conversion(long long d, t_flags **flags)
{
    char        *hexadec;
    long long   i;
    long long   rem;
    unsigned long long neg;

    neg = 0;
    hexadec = ft_strnew((*flags)->base_size);
    if (!hexadec)
        return (NULL);
    i = (*flags)->base_size;
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
                rem += 87;
            hexadec[i - 1] = rem;
            i--;
            neg = neg / 16;
        }
    }
    hexadec[(*flags)->base_size] = '\0';
    if (i > 0)
        hexadec = ft_strsub(hexadec, i, ((*flags)->base_size - 1));
    return (hexadec);
}
