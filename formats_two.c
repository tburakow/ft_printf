/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 15:28:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(va_list arg, t_flags **flags)
{
	int	integer;
	
	integer = va_arg(arg, int);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);	
}

void	character(va_list arg, t_flags **flags)
{
	char	*character;

	character = ft_strnew(1);
	character = ft_strncpy(character, va_arg(arg, char*), 1);
	character = apply_flags(character, flags);
	print_out(character);
	free(character);
}

void	string(va_list arg, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(va_arg(arg, char*)));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}

void	pointer(va_list arg, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(va_arg(arg, char*)));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}

void	percent(va_list arg, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(va_arg(arg, char*)));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}