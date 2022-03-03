/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/03 18:20:03 by tburakow         ###   ########.fr       */
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
static void format(int i, va_list *arg, t_flags **flags)
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
}

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
			//printf("\nformat determined\n");
			format(i, arg, flags);
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
	while (j < jmax)
	{
		reset_flags(&flags);
		while (format[j] != '%' && j <= jmax)
			ft_putchar(format[j++]);
		if (j <= jmax)
		{
			j = ft_raise_flags((char *)format, j, &flags);
			determine_format(format[j], &arg, &flags);
		}
		j++;
	}
	va_end(arg);
	return (0);
}
