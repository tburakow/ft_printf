/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/09 17:14:38 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

static int	determine_format(char c, va_list arg)
{
	char	*str;
	size_t	i;
	int		ret;

	i = 0;
	str = "abcd";
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret = va_arg(arg, int);
		i++;
	}
	return(ret);
}

int	ft_printf(const char *restrict format, ...)
{
	size_t	i;
	size_t	j;

	va_list arg;
	va_start(arg, format);

	i = 0;
	j = 0;
	while (format[j] != '\0')
	{
		while(format[j] != '%')
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
