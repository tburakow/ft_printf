/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/28 15:06:04 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* static char	*inf_float_special(char *input, t_flags **flags)
{
	int		len;
	char	*space;

	len = 0;
	space = NULL;
	if ((*flags)->neg != 0)
		input = ft_strjoin("-", input);
	else if((*flags)->plus != 0 && (*flags)->neg == 0)
		input = ft_strjoin("+", input);
	len = (*flags)->width - ft_strlen(input);
	if (len > 0)
	{
		space = ft_strnew(len);
		space = (char *)ft_memset(space, ' ', len);
		input = ft_strjoin(space, input);
		ft_strdel(&space);
	}
	(*flags)->f_check = 0;
	return (input);
} */

void print_out(char *input, t_flags **flags)
{
	int		i;
	char	c;
	char	*output;
	
/* 	if ((*flags)->f_check == 100)
		input = inf_float_special(input, flags); */
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
	//printf("\nYO!\n");
	ft_strdel(&output);
}
