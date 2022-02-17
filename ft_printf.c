/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/17 22:09:41 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** prints out the current argument in it's final form.
*/
static void print_out(char *out)
{
	int		i;

	i = 0;
	while (out[i] != '\0')
	{
		ft_putchar(out[i++]);
	}
}
/*
** checks which flags to apply and applies them (PARANTELE!)
*/
static void apply_flags(char *x, t_flags *flags)
{
	if (flags->l != 0)
		x = "flags l";
	if (flags->ll != 0)
		x = "flags ll";
	if (flags->h != 0)
		x = "flags h";
	if (flags->hh != 0)
		x = "flags hh";
	if (flags->L != 0)
		x = "flags L";
	if (flags->space != 0)
		x = "flags space";
	if (flags->plus != 0)
		x = "flags plus";
	if (flags->minus != 0)
		x = "flags minus";
	if (flags->hash != 0)
		x = "flags hash";
	if (flags->zero != 0)
		x = "flags zero";
	print_out(x);
}

/*
** Takes the index and calls the corresponding function
** with the current argument.
*/
static char *apply_format(int i, char *y)
{
	char 			*ret;
	t_apply_format	*apply_format[11];

	apply_format[0] = signed_int;
	apply_format[1] = signed_int;
	apply_format[2] = signed_octal;
	apply_format[3] = unsigned_dec;
	apply_format[4] = unsigned_hex;
	apply_format[5] = unsigned_hex_cap;
	apply_format[6] = float_dec_point;
	apply_format[7] = character;
	apply_format[8] = string;
	apply_format[9] = pointer;
	apply_format[10] = percent;
	ret = 0;
	ret = (apply_format[i](y));
	return (ret);
}

/*
** This function determines the format for the current argument
** by comparing it's format specifier to a list of specifiers,
** after which it calls the apply_format function with the 
** index of the correct type and returns the result of formatting.
*/
static void	determine_format(char c, va_list arg, t_flags *flags)
{
	char	*str;
	size_t	i;
	char	*ret;

	i = 0;
	str = "diouxXfcsp%";
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			printf("\nformat determined\n");
			ret = apply_format(i, va_arg(arg, char *));
			apply_flags(ret, flags);
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
	t_flags	flags;

	flags = *create_flags();
	va_start(arg, format);
	j = 0;
	while (format[j] != '\0')
	{
		reset_flags(&flags);
		while (format[j] != '%')
			ft_putchar(format[j++]);
		j = ft_raise_flags((char *)format, j, &flags);
		determine_format(format[j], arg, &flags);
		j++;
	}
	va_end(arg);
	return (0);
}
