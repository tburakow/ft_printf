/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:55 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/03 18:20:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_out_numeric(int output)
{
	ft_putnbr(output);
}

void print_out(char *output)
{
	int	i;
	
	i = 0;
	while (output[i] != '\0')
	{
		ft_putchar(output[i]);
		i++;
	}
}
