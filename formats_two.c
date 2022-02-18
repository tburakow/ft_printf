/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 13:50:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(char *x, t_flags **flags)
{
	int		integer;

	integer = ft_atoi(x);
	integer = apply_flags_numeric(integer, flags);
	print_out_numeric(integer);
}

void	character(char *x, t_flags **flags)
{
	char	*character;

	character = ft_strnew(1);
	character = ft_strncpy(character, x, 1);
	character = apply_flags(character, flags);
	print_out(character);
	free(character);
}

void	string(char *x, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(x));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}

void	pointer(char *x, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(x));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}

void	percent(char *x, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(x));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
}
