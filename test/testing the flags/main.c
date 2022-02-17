/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:16:03 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/17 16:59:35 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void print_flags(t_flags flags)
{
	printf("l: %u\n", flags.l);
	printf("ll: %u\n", flags.ll);
	printf("h: %u\n", flags.h);
	printf("hh: %u\n", flags.hh);
	printf("L: %u\n", flags.L);
	printf("zero: %u\n", flags.zero);
	printf("hash: %u\n", flags.hash);
	printf("minus: %u\n", flags.minus);
	printf("plus: %u\n", flags.plus);
	printf("width: %u\n", flags.width);
	printf("precision: %u\n", flags.precision);
	printf("space: %u\n", flags.space);
}

int	check_for_char(char c, char *str)
{
	int	i;

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
	format = "hips% -+#0400.30d";
	flags = *create_flags();
	while (format[j] != '\0')
	{
		while (format[j] != '%')
			ft_putchar(format[j++]);
		j = ft_raise_flags(format, j, &flags);
		j++;
	}
	//ft_putnbr(j);
	ft_putchar('\n');
	ft_putchar('\n');
	print_flags(flags);
}