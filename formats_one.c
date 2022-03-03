/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/03 14:09:48 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int(va_list *arg, t_flags **flags)
{
	int		integer;
	char	*string_form;
	
	integer = va_arg(*arg, int);
	string_form = apply_flags(ft_itoa(integer), flags);
	print_out(string_form);
}

void	unsigned_octal(va_list *arg, t_flags **flags)
{
	unsigned	integer;
	char		*string_form;
	
	integer = va_arg(*arg, unsigned);
	string_form = ft_itoa(octal_conversion(integer));
	string_form = apply_flags(string_form, flags);
	print_out(string_form);
}

void	unsigned_dec(va_list *arg, t_flags **flags)
{
	unsigned	integer;
	char		*string_form;
	
	integer = va_arg(*arg, unsigned);
	string_form = apply_flags(ft_itoa(integer), flags);
	print_out(string_form);
}

void	unsigned_hex(va_list *arg, t_flags **flags)
{
	unsigned	integer;
	char		*hexadec;
	
	integer = va_arg(*arg, unsigned);
	hexadec = hex_conversion(integer);
	hexadec = apply_flags(hexadec, flags);
	print_out(hexadec);
}

void	unsigned_hex_cap(va_list *arg, t_flags **flags)
{
	unsigned	integer;
	char		*hexadec;
	
	integer = va_arg(*arg, unsigned);
	hexadec = hex_cap_conversion(integer);
	hexadec = apply_flags(hexadec, flags);
	print_out(hexadec);
}
