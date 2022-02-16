/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:16:03 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/16 19:57:32 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_for_char(char c)
{
	int	i;
	char *str;

	str = ft_strnew(ft_strlen("diouxXfcsp%"));
	str = "diouxXfcsp%";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main (void)
{
	char *format;
	int j;
	t_flags	flags;

	j = 0;
	format = ft_strnew(ft_strlen("hips% -+#0100.100d"));
	format = "hips% -+#0100.100d";
	flags = *create_flags();
	while (format[j] != '\0')
	{
		while (format[j] != '%')
			ft_putchar(format[j++]);
		j = ft_raise_flags(format, j, &flags);
		j++;
	}
	ft_putnbr(j);
}