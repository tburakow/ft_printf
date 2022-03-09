/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/09 12:44:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(va_list *arg, t_flags **flags)
{
	char		*string;
	long double	number;

	number = va_arg(*arg, double);
	//printf("\n%Lf\n", number);
	number = bankers_round(number, flags);
	string = to_ascii(number, flags);
	//string = apply_flags(string, flags);
	print_out(string);
	ft_strdel(&string);
}

void	character(va_list *arg, t_flags **flags)
{
	int		character;
	char	*result;

	result = ft_strnew(1);
	character = va_arg(*arg, int);
	result[0] = character;
	result = apply_flags(result, flags);
	print_out(result);
	free(result);
}

void	string(va_list *arg, t_flags **flags)
{
	char	*string;

	string = va_arg(*arg, char*);
	string = apply_flags(string, flags);
	print_out(string);
}

void	pointer(va_list *arg, t_flags **flags)
{
	unsigned long	pointer;
	char			*hex_ptr;
	
	pointer  = va_arg(*arg, unsigned long);
	if (pointer == 0)
		print_out("0x0");
	else
	{
		hex_ptr = ptr_conversion(pointer);
		if (hex_ptr[0] == '0')
			hex_ptr = ft_strjoin("0x1", hex_ptr);
		else
			hex_ptr = ft_strjoin("0x10", hex_ptr);
		hex_ptr = apply_flags(hex_ptr, flags);
		print_out(hex_ptr);
	}
}

void	percent(t_flags **flags)
{
	char	*character;

	character = ft_strnew(1);
	character = "%";
	character = apply_flags(character, flags);
	print_out(character);
	//free(character);
}
