/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 11:51:40 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_out(char *input, t_flags **flags)
{
	int		i;
	char	c;
	char	*output;
	
	output = ft_strnew(ft_strlen(input));
	output = ft_strcpy(output, input);
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
	ft_strdel(&output);
}
