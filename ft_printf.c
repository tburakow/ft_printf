/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/22 22:15:03 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	error_output(char *mess)
{
	ft_putstr(mess);
	return (1);
}

/*
** Takes the index and calls the corresponding function
** with the current argument.
*/
static void apply_format(int i, va_list *arg, t_flags **flags)
{
	t_apply_format	*apply_format[11];
	
	apply_format[0] = signed_int;
	apply_format[1] = signed_int;
	apply_format[2] = unsigned_octal;
	apply_format[3] = unsigned_dec;
	apply_format[4] = unsigned_hex;
	apply_format[5] = unsigned_hex_cap;
	apply_format[6] = float_dec_point;
	apply_format[7] = character;
	apply_format[8] = string;
	apply_format[9] = pointer;
	if (i < 10)
		apply_format[i](arg, flags);
	else
		percent(flags);
}

/*
** This function determines the format for the current argument
** by comparing it's format specifier to a list of specifiers,
** after which it calls the apply_format function with the 
** index of the correct type and returns the result of formatting.
*/
static void	determine_format(char c, va_list *arg, t_flags **flags)
{
	char	*str;
	size_t	i;

	i = 0;
	str = "diouxXfcsp%";
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			//printf("\nformat determined\n");
			apply_format(i, arg, flags);
		}
		i++;
	}
}

/*
** Replace this with a cool explanation of printf
*/
int	ft_printf(const char *format, ...)
{
	int	j;
	va_list	arg;
	t_flags	*flags;
	
	if (create_flags(&flags) == 0)
		return (error_output("error: flags allocation failed"));
	va_start(arg, format);
	j = 0;
	while (format[j] != '\0')
	{
		reset_flags(&flags);
		while (format[j] != '%')
			ft_putchar(format[j++]);
		j = ft_raise_flags((char *)format, j, &flags);
		determine_format(format[j], &arg, &flags);
		j++;
	}
	va_end(arg);
	return (0);
}
