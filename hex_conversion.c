/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:59:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 14:52:44 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_return(void)
{
	char	*hexadec;

	hexadec = ft_strnew(1);
	hexadec = ft_strcpy(hexadec, "0");
	return (hexadec);
}

static char	*hex_base(char *hexadec, long long d, long long i, \
t_flags **flags)
{
	long long	rem;
	char		*output;

	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
	output = ft_memset(output, ' ', (*flags)->base_size);
	while (d > 0)
	{
		rem = d % 16;
		if (rem <= 9)
			rem += 48;
		else
			rem += 87;
		if ((*flags)->type == 'X')
			rem = ft_toupper(rem);
		output[i - 1] = rem;
		i--;
		d = d / 16;
	}
	output[(*flags)->base_size] = '\0';
	if (i > 0)
		output = strsub_with_free(output, i, (*flags)->base_size - i);
	return (output);
}

static char	*neg_hex_base(char *hexadec, unsigned long long neg, long long i, \
t_flags **flags)
{
	long long	rem;
	char		*output;

	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
	output = ft_memset(output, ' ', (*flags)->base_size);
	while (neg > 0 && i >= 0)
	{
		rem = neg % 16;
		if (rem <= 9)
			rem += 48;
		else
			rem += 87;
		if ((*flags)->type == 'X')
			rem = ft_toupper(rem);
		output[i - 1] = rem;
		i--;
		neg = neg / 16;
	}
	output[(*flags)->base_size] = '\0';
	if (i > 0)
		output = strsub_with_free(output, i, (*flags)->base_size - i);
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
		return (zero_return());
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
