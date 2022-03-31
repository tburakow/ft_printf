/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:30:51 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/31 13:09:48 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spec(t_flags **flags)
{
	char c;

	c = ' ';
	if ((*flags)->neg == 0 && (*flags)->plus != 0)
	{
		c = '+';
		(*flags)->output += write(1, &c, 1);
	}
	if ((*flags)->neg == 1)
	{
		c = '-';
		(*flags)->output += write(1, &c, 1);
	}
	(*flags)->plus = 0;
	(*flags)->neg = 0;
}

static void print_filler(int len, t_flags **flags)
{
	char	c;
	int		i;
	
	c = ' ';
	i = 0;
	if ((*flags)->zero != 0)
	{
		c = '0';
		if ((*flags)->plus != 0 || (*flags)->neg != 0)
		{
			print_spec(flags);
			len--;
		}
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
	}
	else
	{
		if ((*flags)->plus != 0|| (*flags)->neg != 0)
			len--;
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
		if ((*flags)->plus != 0 || (*flags)->neg != 0)
			print_spec(flags);
	}
}

static void	flag_exclusions(t_flags **flags)
{
	if ((*flags)->minus != 0 || ((*flags)->empty_prec == 0 && (*flags)->f_check != 0))
		(*flags)->zero = 0;
}

void octal_mod(char *input, t_flags **flags)
{
	// hash forces the first number to be zero.
	// zero works. minus overrides this.
	// minus flag works.
	// plus sign works.
	char	c;
	int		len;
	int		i;
	
	c = ' ';
	i = 0;
	len = (*flags)->width - ft_strlen(input);
	flag_exclusions(flags);
	print_filler(len, flags);
	print_out(input, flags);
	if (len > 0 && (*flags)->minus != 0)
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
}