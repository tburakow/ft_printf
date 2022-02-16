/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/16 17:31:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_flags_print(char *x, t_flags flags)
{
	if (flags.left_adjust != 0)
		return (x * 10);
	if (flags.min_field_w != 0)
		return (x * 10);
	if (flags.separ_w_prec != 0)
		return (x * 10);
	if (flags.precision != 0)
		return (x * 10);
	if (flags.min_value != 0)
		return (x * 10);
	if (flags.short_long != 0)
		return (x * 10);
	return (x);
}

static char *apply_format(int i, char *y)
{
	char 			*ret;
	t_apply_format	*apply_format[10];

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

static char *determine_format(char c, va_list arg, t_flags flags)
{
	char	*str;
	size_t	i;
	char	*ret;

	i = 0;
	str = "diouxXfcsp%";
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret = apply_format(i, va_arg(arg, char *));
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int	j;
	va_list	arg;
	t_flags	flags;
	char	*out;

	flags = *create_flags();
	va_start(arg, format);
	j = 0;
	out = NULL;
	while (format[j] != '\0')
	{
		reset_flags(flags);
		while (format[j] != '%')
			ft_putchar(format[j++]);
		j = ft_raise_flags(format, j, &flags);
		out = determine_format(format[j], arg);
		out = apply_flags(out, flags);
		print_out(out);
		j++;
	}
	va_end(arg);
	return (0);
}
