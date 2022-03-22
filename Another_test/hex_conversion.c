/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 11:29:03 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *hex_base(char *hexadec, long long d, long long i, \
t_flags **flags)
{
    long long	rem;
	char		*output;

	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
    while (d > 0)
    {
        rem = d % 16;
        if (rem <= 9)
            rem += 48;
        else
            rem += 87;
        output[i - 1] = rem;
        i--;
        d = d / 16;
    }
    output[(*flags)->base_size] = '\0';
/*     if (i > 0)
        output = strsub_with_free(output, i, (*flags)->base_size - 1); */
    return (output);
}

static char *neg_hex_base(char *hexadec, unsigned long long neg, long long i,\
 t_flags **flags)
{
    long long	rem;
	char		*output;
    
	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
    while (neg > 0 && i >= 0)
    {
            rem = neg % 16;
        if (rem <= 9)
            rem += 48;
        else
            rem += 87;
        output[i - 1] = rem;
        i--;
        neg = neg / 16;
    }
    output[(*flags)->base_size] = '\0';
/*     if (i > 0)
        output = strsub_with_free(output, i, (*flags)->base_size - 1); */
    return (output);
}

/*
** This function converts the long "d" from decimal to octal and returns it.
*/
char	*hex_conversion(long long d, t_flags **flags)
{
	char				*hexadec;
	long long			i;
	unsigned long long	neg;

	neg = 0;
	if (d == 0)
		return ("0");
	hexadec = ft_strnew((*flags)->base_size);
	if (!hexadec)
		return (NULL);
	i = (*flags)->base_size;
	if (d > 0)
        hexadec = hex_base(hexadec, d, i, flags);
	else
	{
		neg = d;
        hexadec = neg_hex_base(hexadec, neg, i, flags);
	}
	return (hexadec);
}
