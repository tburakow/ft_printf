/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/31 14:01:30 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int(t_flags **flags)
{
	long long	nbr;
	char		*str;

	if ((*flags)->l == 2)
		nbr = (long long int)va_arg((*flags)->arg, long long);
	else if ((*flags)->l == 1)
		nbr = (long int)va_arg((*flags)->arg, long);
	else if ((*flags)->h == 2)
		nbr = (signed char)va_arg((*flags)->arg, int);
	else if ((*flags)->h == 1)
		nbr = (short int)va_arg((*flags)->arg, int);
	else
		nbr = va_arg((*flags)->arg, int);
	if (nbr < 0 && nbr >= -9223372036854775807)
	{
		(*flags)->neg = 1;
		nbr = nbr * -1;
	}
	if (nbr != 0)
		(*flags)->empty_prec = 0;
	if (/* nbr == 0 &&  */(*flags)->f_check == 1)
		(*flags)->zero = 0;
	if (nbr == 0)
	{
		str = ft_strnew(1);
		str = ft_memset(str, '0', 1);
		//printf("HEllo!\n");
	}
	else
		str = ft_itoa(nbr);
	apply_flags(str, flags);
	ft_strdel(&str);
}

void	unsigned_octal(t_flags **flags)
{
	unsigned long long	nbr;
	char				*str;

	if ((*flags)->l == 2)
		nbr = (unsigned long long)va_arg((*flags)->arg, unsigned long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long)va_arg((*flags)->arg, unsigned long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg((*flags)->arg, int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg((*flags)->arg, int);
	else
		nbr = (unsigned int)va_arg((*flags)->arg, int);
	if ((*flags)->hash == 1)
		(*flags)->empty_prec = 0;
	if (nbr == 0)
		(*flags)->hash = 0;
	if (nbr != 0 && (*flags)->empty_prec != 0)
		(*flags)->empty_prec = 0;
	str = ft_itoa_unsigned(octal_conversion(nbr));
	if (nbr == ULONG_MAX)
		apply_flags("1777777777777777777777", flags);
	else
		apply_flags(str, flags);
	ft_strdel(&str);
}

void	unsigned_dec(t_flags **flags)
{
	unsigned long long	nbr;
	char				*str;

	nbr = 0;
	if ((*flags)->l == 2)
		nbr = va_arg((*flags)->arg, unsigned long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long long)va_arg((*flags)->arg, unsigned long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg((*flags)->arg, unsigned int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short)va_arg((*flags)->arg, unsigned int);
	else
		nbr = (unsigned long long)va_arg((*flags)->arg, unsigned int);
	if (nbr < 0)
	{
		(*flags)->neg = 1;
		nbr = nbr * -1;
	}
	if (nbr != 0 && (*flags)->empty_prec != 0)
		(*flags)->empty_prec = 0;
	str = ft_itoa_unsigned(nbr);
	apply_flags(str, flags);
	ft_strdel(&str);
}

void	unsigned_hex(t_flags **flags)
{
	long long	nbr;
	char		*str;

	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg((*flags)->arg, long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg((*flags)->arg, long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg((*flags)->arg, int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg((*flags)->arg, int);
	else
		nbr = va_arg((*flags)->arg, int);
	if (nbr == 0)
		(*flags)->hash = 0;
	(*flags)->hash *= 2;
	if (nbr != 0 && (*flags)->empty_prec != 0)
		(*flags)->empty_prec = 0;
	str = hex_conversion(nbr, flags);
	apply_flags(str, flags);
	ft_strdel(&str);
}

/* void	unsigned_hex_cap(t_flags **flags)
{
	long long	nbr;
	char		*str;

	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg((*flags)->arg, long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg((*flags)->arg, long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg((*flags)->arg, int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg((*flags)->arg, int);
	else
		nbr = va_arg((*flags)->arg, int);
	if (nbr == 0)
		(*flags)->hash = 0;
	(*flags)->hash *= 2;
	str = hex_cap_conversion(nbr, flags);
	apply_flags(str, flags);
	ft_strdel(&str);
} */