/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 13:40:43 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	signed_octal(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_dec(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_hex(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	unsigned_hex_cap(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}
