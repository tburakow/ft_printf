/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 10:17:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(t_flags **flags)
{
	long double	number;

	if ((*flags)->bigl == 1)
		number = va_arg((*flags)->arg, long double);
	else
		number = va_arg((*flags)->arg, double);
	if ((*flags)->empty_prec == 0 && (*flags)->precision == 0)
		(*flags)->precision = 6;
	if (number < 0)
	{
		number = number * -1;
		(*flags)->neg = 1;
	}
	apply_flags(to_ascii(bankers_round(number, flags), flags), flags);
}

void	character(t_flags **flags)
{
	int		character;
	//char	*result;

	character = va_arg((*flags)->arg, int);
/* 	if (character == 0)
	{
		result = "";
		(*flags)->char_null = 1;
	}
	else
	{
		result = ft_strnew(1);
		result[0] = character;
	}
	apply_flags(result, flags); */
	character_mod(flags, character);
}

void	string(t_flags **flags)
{
	char	*string;

	string = va_arg((*flags)->arg, char *);
	if (string == NULL)
		apply_flags("(null)", flags);
	else
		apply_flags(string, flags);
}

void	pointer(t_flags **flags)
{
	unsigned long	pointer;
	char			*hex_ptr;
	char			*add;

	pointer = va_arg((*flags)->arg, unsigned long);
	(*flags)->base_size = 16;
	if (pointer == 0)
	{
		if ((*flags)->empty_prec == 1)
			print_out("0x", flags);
		else
		{
			apply_flags("0x0", flags);
		}
	}
	else
	{
		hex_ptr = ptr_conversion(pointer, flags);
		if (hex_ptr[0] == '0')
		{
			add = ft_strnew(3);
			add = ft_strcpy(add, "0x1");
			hex_ptr = strjoin_with_free(add, hex_ptr);
		}
		else
		{
			add = ft_strnew(2);
			add = ft_strcpy(add, "0x");
			hex_ptr = strjoin_with_free(add, hex_ptr);
		}
		apply_flags(hex_ptr, flags);
	}
}

void	percent(t_flags **flags)
{
	apply_flags("%", flags);
}
