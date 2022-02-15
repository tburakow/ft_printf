/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/15 11:54:24 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

static int	apply_flags(int x, t_flags flags)
{
	if (flags.test == 'A')
		return (x * 10);
	return (x);
}

static int	apply_format_and_flags(int i, int y, int x, t_flags flags)
{
	int				ret;
	t_math_function	*math_array[4];

	math_array[0] = add;
	math_array[1] = sub;
	math_array[2] = mult;
	math_array[3] = divide;
	ret = 0;
	ret = apply_flags(math_array[i](y, x), flags);
	return (ret);
}

static int	determine_format(char c, va_list arg)
{
	char			*str;
	size_t			i;
	int				ret;
	t_flags			flags;

	i = 0;
	str = "abcd";
	flags = *create_flags();
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret = apply_format_and_flags(i, va_arg(arg, int), 5, flags);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *restrict format, ...)
{
	size_t	i;
	size_t	j;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	j = 0;
	while (format[j] != '\0')
	{
		while (format[j] != '%')
		{
			ft_putchar(format[j]);
			j++;
		}
		j++;
		i = determine_format(format[j], arg);
		ft_putnbr(i);
		j++;
	}
	va_end(arg);
	return (0);
}
