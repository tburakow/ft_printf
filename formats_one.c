/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/04 20:42:41 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int(va_list *arg, t_flags **flags)
{
	long long	nbr;
	char		*string_form;

	if ((*flags)->l == 2)
		nbr = (long long int)va_arg(*arg, long long);
	else if ((*flags)->l == 1)
		nbr = (long int)va_arg(*arg, long);
	else if ((*flags)->h == 2)
		nbr = (signed char)va_arg(*arg, int);
	else if ((*flags)->h == 1)
		nbr = (short int)va_arg(*arg, int);
	else
		nbr = va_arg(*arg, int);
	if (nbr < 0)
	{
		(*flags)->neg = 1;
		nbr = nbr * -1;
	}
	string_form = apply_flags(ft_itoa(nbr), flags);
	print_out(string_form);
}

void	unsigned_octal(va_list *arg, t_flags **flags)
{
	long long	nbr;
	char		*string_form;
	
	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg(*arg, long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg(*arg, long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg(*arg, int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg(*arg, int);
	else
		nbr = va_arg(*arg, unsigned int);
	string_form = ft_itoa(octal_conversion(nbr));
	string_form = apply_flags(string_form, flags);
	print_out(string_form);
}

void	unsigned_dec(va_list *arg, t_flags **flags)
{
	long long	nbr;
	char		*string_form;
	
	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg(*arg, long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg(*arg, long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg(*arg, int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg(*arg, int);
	else
		nbr = va_arg(*arg, unsigned int);
	string_form = apply_flags(ft_itoa(integer), flags);
	print_out(string_form);
}

void	unsigned_hex(va_list *arg, t_flags **flags)
{
	long long	nbr;
	char		*hexadec;

	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg(*arg, unsigned long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg(*arg, unsigned long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg(*arg, unsigned int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg(*arg, unsigned int);
	else	
		nbr = va_arg(*arg, unsigned int);
	hexadec = hex_conversion(nbr);
	hexadec = apply_flags(hexadec, flags);
	print_out(hexadec);
}

void	unsigned_hex_cap(va_list *arg, t_flags **flags)
{
	unsigned	nbr;
	char		*hexadec;
	
	if ((*flags)->l == 2)
		nbr = (unsigned long long int)va_arg(*arg, unsigned long long);
	else if ((*flags)->l == 1)
		nbr = (unsigned long int)va_arg(*arg, unsigned long);
	else if ((*flags)->h == 2)
		nbr = (unsigned char)va_arg(*arg, unsigned int);
	else if ((*flags)->h == 1)
		nbr = (unsigned short int)va_arg(*arg, unsigned int);
	else	
		nbr = va_arg(*arg, unsigned int);
	hexadec = hex_cap_conversion(nbr);
	hexadec = apply_flags(hexadec, flags);
	print_out(hexadec);
}
