/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 14:24:09 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_out(char *output, t_flags **flags)
{
	int	i;
	char c;
	
	i = 0;
	while (output[i] != '\0')
	{
		special_putchar(output[i], flags);
		i++;
	}
	if ((*flags)->char_null == 1)
	{
		c = '\0';
		(*flags)->output++;
		write(1, &c, 1);
	}
}
