/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:44:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/11 17:25:14 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_dec_point(va_list *arg, t_flags **flags)
{
	char		*string;
	long double	number;

	if ((*flags)->bigl == 1)
		number = va_arg(*arg, long double);
	else
		number = va_arg(*arg, double);
	//printf("\n%Lf\n", number);
	if ((*flags)->empty_prec == 0 && (*flags)->precision == 0)
		(*flags)->precision = 6;
	if (number < 0)
    {
        number = number * -1;
        (*flags)->neg = 1;
    }
	number = bankers_round(number, flags);
	string = to_ascii(number, flags);
	string = apply_flags(string, flags);
	print_out(string, flags);
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
	print_out(result, flags);
	ft_strdel(&result);
}

void	string(va_list *arg, t_flags **flags)
{
	char	*string;

	string = va_arg(*arg, char *);
	string = apply_flags(string, flags);
	print_out(string, flags);
}

void	pointer(va_list *arg, t_flags **flags)
{
	unsigned long	pointer;
	char			*hex_ptr;

	pointer = va_arg (*arg, unsigned long);
	if (pointer == 0)
		print_out("0x0", flags);
	else
	{
		hex_ptr = ptr_conversion(pointer, flags);
		if (hex_ptr[0] == '0')
			hex_ptr = ft_strjoin("0x1", hex_ptr);
		else
			hex_ptr = ft_strjoin("0x10", hex_ptr);
		hex_ptr = apply_flags(hex_ptr, flags);
		print_out(hex_ptr, flags);
	}
}

void	percent(t_flags **flags)
{
	char	*character;

	character = apply_flags("%", flags);
	print_out(character, flags);
}
