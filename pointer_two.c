/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:35:39 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 14:43:06 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_pointer(t_flags **flags)
{
	char	*add;

	if ((*flags)->empty_prec == 1)
	{
		add = ft_strnew(2);
		add = ft_strcpy(add, "0x");
		print_out(add, flags);
	}
	else
	{
		add = ft_strnew(3);
		add = ft_strcpy(add, "0x0");
		apply_flags(add, flags);
	}
	ft_strdel(&add);
}

void	non_zero_pointer(unsigned long pointer, t_flags **flags)
{
	char			*hex_ptr;
	char			*add;

	hex_ptr = ptr_conversion(pointer, flags);
	if (hex_ptr[0] == '0')
	{
		add = ft_strnew(3);
		add = ft_strcpy(add, "0x1");
		hex_ptr = strjoin_with_free(add, hex_ptr);
	}
	else
	{
		add = ft_strnew(2);
		add = ft_strcpy(add, "0x");
		hex_ptr = strjoin_with_free(add, hex_ptr);
	}
	apply_flags(hex_ptr, flags);
	ft_strdel(&hex_ptr);
}
