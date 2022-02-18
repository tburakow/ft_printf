/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 16:48:10 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int(va_list arg, t_flags **flags)
{
	int	integer;
	
	integer = va_arg(arg, int);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_octal(va_list arg, t_flags **flags)
{
	unsigned	integer;
	
	integer = va_arg(arg, unsigned);
	integer = octal_conversion(integer);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_dec(va_list arg, t_flags **flags)
{
	int	integer;
	
	integer = va_arg(arg, int);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_hex(va_list arg, t_flags **flags)
{
	int	integer;
	
	integer = va_arg(arg, int);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_hex_cap(va_list arg, t_flags **flags)
{
	int	integer;
	
	integer = va_arg(arg, int);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}
