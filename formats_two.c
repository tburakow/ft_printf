/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/28 15:06:45 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(t_flags **flags)
{
	long double	number;
	char		*str;
	int			x;

	if ((*flags)->bigl == 1)
		number = va_arg((*flags)->arg, long double);
	else
		number = va_arg((*flags)->arg, double);
	if ((*flags)->empty_prec == 0 && (*flags)->precision == 0)
		(*flags)->precision = 6;
	if ((*flags)->empty_prec == 1)
	{
		(*flags)->precision = 0;
		(*flags)->empty_prec = 0;
	}
	x = infinity(number, flags);
	if (x != 0)
	{
		if (x == 2)
			float_mod("nan", flags);
		else
			float_mod("inf", flags);
	}
	else
	{
		if (number < 0)
		{
			number = number * -1;
			(*flags)->neg = 1;
		}
		if (1 / number < 0)
			(*flags)->neg = 1;
	
		str = to_ascii(bankers_round(number, flags), flags);
		float_mod(str, flags);
		ft_strdel(&str);
	}
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
		{
			add = ft_strnew(2);
			add = ft_strcpy(add, "0x");
			print_out(add, flags);
		}
		else
		{
			add = ft_strnew(3);
			add = ft_strcpy(add, "0x0");
			apply_flags(add, flags);
		}
		ft_strdel(&add);
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
		ft_strdel(&hex_ptr);
	}
}

void	percent(t_flags **flags)
{
	apply_flags("%", flags);
}
