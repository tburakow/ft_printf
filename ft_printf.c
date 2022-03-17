/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/17 13:45:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_formats	*formats[10] = {signed_int, signed_int, unsigned_octal, \
unsigned_dec, unsigned_hex, unsigned_hex_cap, float_dec_point, \
character, string, pointer};

int	error_output(char *mess)
{
	ft_putstr(mess);
	return (1);
}

/*
** Takes the index and calls the corresponding function
** with the current argument.
*/
/* static void format(int i, va_list *arg, t_flags **flags)
{
	t_format	*format[11];
	
	format[0] = signed_int;
	format[1] = signed_int;
	format[2] = unsigned_octal;
	format[3] = unsigned_dec;
	format[4] = unsigned_hex;
	format[5] = unsigned_hex_cap;
	format[6] = float_dec_point;
	format[7] = character;
	format[8] = string;
	format[9] = pointer;
	if (i < 10)
		format[i](arg, flags);
	else
		percent(flags);
} */

/*
** This function determines the format for the current argument
** by comparing it's format specifier to a list of specifiers,
** after which it calls the format function with the 
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
			if (c == '%')
				percent(flags);
			else
			//printf("\nformat determined\n");
				formats[i](arg, flags);
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
	int jmax;
	va_list	arg;
	t_flags	*flags;
	
	jmax = ft_strlen(format);
	if (create_flags(&flags) == 0)
		return (error_output("error: flags allocation failed"));
	va_start(arg, format);
	j = 0;
	if (format[0] == '%' && format[1] == '\0')
		return (0);
	while (j < jmax)
	{
		reset_flags(&flags);
		while (format[j] != '%' && j <= jmax)
			special_putchar(format[j++], &flags);
		if (j <= jmax)
		{
			j = ft_raise_flags((char *)format, j, &flags);
			determine_format(format[j], &arg, &flags);
		}
		j++;
	}
	va_end(arg);
	return (flags->output);
}
