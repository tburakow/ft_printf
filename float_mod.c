/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:11:46 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/25 13:44:45 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_mod(char *input, t_flags **flags)
{
	//#hash will always give decimal point.
	//zero is on even with precision.
	//space works.
	//plus overrides space.
	unsigned int	i;
	unsigned int	len;
	char			c;

	c = ' ';
	i = 0;
	if ((*flags)->space != 0 && (*flags)->neg == 0 && (*flags)->plus == 0)
		(*flags)->output += write(1, &c, 1);
	if ((*flags)->zero != 0 && (*flags)->minus == 0)
		c = '0';
	len = (*flags)->width - ft_strlen(input);
	if ((*flags)->plus != 0)
	{
		if ((*flags)->neg == 0)
			c = '+';
		else
			c = '-';
		(*flags)->output += write(1, &c, 1);
	}
	if (len > 0 && (*flags)->minus == 0)
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
	print_out(input, flags);
	if (len > 0 && (*flags)->minus != 0)
		while (i++ < len)
			(*flags)->output += write(1, &c, 1);
}
