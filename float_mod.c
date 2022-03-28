/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:11:46 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/28 15:16:46 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	infinity(long double x, t_flags **flags)
{
	
    if (x == -1.0 / 0.0)
	{
		(*flags)->zero = 0;
		//(*flags)->plus = 0;
		//(*flags)->space = 0;
		(*flags)->neg = 1;
        return (-1);
	}
    if (x == 1.0 / 0.0)
	{
		//(*flags)->plus = 0;
		//(*flags)->space = 0;
		(*flags)->zero = 0;
    	return (1);
	}
	if (x != x)
	{
		(*flags)->plus = 0;
		(*flags)->space = 0;
		(*flags)->zero = 0;
		return (2);
	}
    return (0);
}

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

void	float_mod(char *input, t_flags **flags)
{
	//#hash will always give decimal point.
	//zero is on even with precision.
	//space works.
	//plus overrides space.
	int		i;
	int		len;
	char	c;

	c = ' ';
	i = 0;
	len = (*flags)->width - ft_strlen(input);
	if ((*flags)->space != 0 && (*flags)->neg == 0 && (*flags)->plus == 0)
	{
		(*flags)->output += write(1, &c, 1);
		len--;
	}
	print_filler(len, flags);
	print_out(input, flags);
	if (len > 0 && (*flags)->minus != 0)
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
}
