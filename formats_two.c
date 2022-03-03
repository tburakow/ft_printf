/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/03 14:09:00 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(va_list *arg, t_flags **flags)
{
	int		integer;
	char	*string_form;
	
	integer = va_arg(*arg, int);
	string_form = apply_flags(ft_itoa(integer), flags);
	print_out(string_form);
}

void	character(va_list *arg, t_flags **flags)
{
	char	*character;

	character = ft_strnew(1);
	character = ft_strncpy(character, va_arg(*arg, char*), 1);
	character = apply_flags(character, flags);
	print_out(character);
	free(character);
}

void	string(va_list *arg, t_flags **flags)
{
	char	*string;

	string = ft_strnew(ft_strlen(va_arg(*arg, char*)));
	string = apply_flags(string, flags);
	print_out(string);
	free(string);
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
